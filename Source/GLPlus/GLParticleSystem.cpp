/*
 * GLParticleSystem.cpp
 *
 *  Created on: Jun 16, 2012
 *      Author: Ilija
 */

#include "GLParticleSystem.h"
#include <stdio.h>


GLParticle::GLParticle()
{
	isAlive = false;;
	position.set(0, 0);
	size.set(1, 1);
	moveVector.set(0, 0);
	color.set(1, 1, 1, 1);
	spin = 0;
	spinSpeed = 0;
	blendSpeed = 0;
	timeout = 0;
}


void GLParticle::update(float dt)
{
	if (isAlive)
	{
		position += moveVector * dt;
		spin += spinSpeed * dt;
		timeout -= dt;
		if (timeout <= 0)
		{
			color.a -= blendSpeed * dt;
			if (color.a <= 0)
				isAlive = false;
		}
	}
}


void GLParticle::draw()
{
	float xx = size.x / 2;
	float yy = size.y / 2;
	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	glRotatef(spin, 0, 0, 1);
	glColor4fv(color.getPtr());
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(-xx, -yy);
	glTexCoord2f(1, 0); glVertex2f( xx, -yy);
	glTexCoord2f(1, 1); glVertex2f( xx,  yy);
	glTexCoord2f(0, 1); glVertex2f(-xx,  yy);
	glEnd();
	glPopMatrix();
}


GLParticleSystemProperties::GLParticleSystemProperties()
{
	AngleWidth = 360;
	MoveSpeed.setValue(1, 2);
	LifeTime.setValue(0.5, 1);
	BlendSpeed.setValue(1, 2);
	SpawnRadius = 0;
	Size = 0.2;
	SpinType = 0;
	SpinSpeed.setValue(300, 200);
	Color = GLColor::White;
}


void GLParticleSystemProperties::save(const char *filename)
{
#define PSP_WRITE_VAR(var) \
	if (var.isConst) \
		fprintf(fp, "%s %f\n", #var, var.value); \
	else \
		fprintf(fp, "%s %f %f\n", #var, var.minValue, var.maxValue)
#define PSP_WRITE_FLOAT(var) \
	fprintf(fp, "%s %f\n", #var, var)
#define PSP_WRITE_INT(var) \
	fprintf(fp, "%s %i\n", #var, var)
#define PSP_WRITE_COLOR(var) \
	fprintf(fp, "%s %f %f %f %f", #var, var.r, var.g, var.b, var.a)

	FILE *fp = fopen(filename, "wt");
	if (fp)
	{
		PSP_WRITE_FLOAT(AngleWidth);
		PSP_WRITE_VAR(MoveSpeed);
		PSP_WRITE_VAR(LifeTime);
		PSP_WRITE_VAR(BlendSpeed);
		PSP_WRITE_VAR(SpawnRadius);
		PSP_WRITE_VAR(Size);
		PSP_WRITE_INT(SpinType);
		PSP_WRITE_VAR(SpinSpeed);
		PSP_WRITE_COLOR(Color);
		fclose(fp);
	}
#undef PSP_WRITE_VAR
#undef PSP_WRITE_FLOAT
#undef PSP_WRITE_INT
}


void GLParticleSystemProperties::load(const char *filename)
{

}


GLParticleSystem::GLParticleSystem()
{
	particlesCount = 0;
	emitterEnabled = false;
	rotation = 0;
}

GLParticleSystem::~GLParticleSystem()
{
	// TODO Auto-generated destructor stub
}


void GLParticleSystem::update(float dt)
{
	//update particles
	for (int i = 0; i < particlesCount; i++)
	{
		particles[i].update(dt);
		if (!particles[i].isAlive)
		{
			if (emitterEnabled && emitterTimer > emitterTimeout)
			{
				resetParticle(i);
				emitterTimer = 0;
			}
			else
			{
				particles[i] = particles[particlesCount - 1];
				particlesCount--;
			}
		}
	}
	//animate emitter
	if (emitterEnabled)
	{
		emitterTimer += dt;
		if (emitterTimer >= emitterTimeout && particlesCount < GLPLUS_PARTICLES_MAX)
		{
			resetParticle(particlesCount);
			particlesCount++;
			emitterTimer = 0;
		}
	}
}


void GLParticleSystem::draw()
{
	glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_ENABLE_BIT);
	glEnable(GL_BLEND);
	//glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	if (texture) texture->push();
	for (int i = 0; i < particlesCount; i++)
	{
		particles[i].draw();
	}
	if (texture) texture->pop();
	glPopAttrib();
}


void GLParticleSystem::explode(int count)
{
	int istart = particlesCount;

	particlesCount += count;
	if (particlesCount > GLPLUS_PARTICLES_MAX)
		particlesCount = GLPLUS_PARTICLES_MAX;

	for (int i = istart; i < particlesCount; i++)
	{
		resetParticle(i);
	}
}


void GLParticleSystem::reset()
{
	particlesCount = 0;
}


void GLParticleSystem::startEmitter(float timeout)
{
	emitterEnabled = true;
	emitterTimer = 0;
	emitterTimeout = timeout;
}

void GLParticleSystem::stopEmitter()
{
	emitterEnabled = false;
}

bool GLParticleSystem::getIsEmitter() const
{
	return emitterEnabled;
}


int GLParticleSystem::getParticlesCount() const
{
	return particlesCount;
}


void GLParticleSystem::setTexture(GLTexture *tex)
{
	texture = tex;
}


void GLParticleSystem::resetParticle(int i)
{
	float angle = (rotation + glplusRandomf(-Properties.AngleWidth / 2, Properties.AngleWidth / 2)) * GLPLUS_TORAD;
	float speed = Properties.MoveSpeed.getValue();
	float dist = Properties.SpawnRadius.getValue();
	float size = Properties.Size.getValue();
	particles[i].isAlive = true;
	particles[i].position.x = position.x + cosf(angle) * dist;
	particles[i].position.y = position.y + sinf(angle) * dist;
	particles[i].size.x = size;
	particles[i].size.y = size;
	particles[i].moveVector.x = cosf(angle) * speed;
	particles[i].moveVector.y = sinf(angle) * speed;
	particles[i].color = Properties.Color;
	particles[i].spin = glplusRandomf(0, 360);
	particles[i].spinSpeed = Properties.SpinSpeed.getValue();
	particles[i].blendSpeed = Properties.BlendSpeed.getValue();
	particles[i].timeout = Properties.LifeTime.getValue();
}




