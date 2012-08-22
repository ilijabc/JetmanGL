/*
 * GLParticleSystem.h
 *
 *  Created on: Jun 16, 2012
 *      Author: Ilija
 */

#ifndef GLPARTICLESYSTEM_H_
#define GLPARTICLESYSTEM_H_

#include "GLMath.h"
#include "GLTexture.h"
#include "GLMaterial.h"

#define GLPLUS_PARTICLES_MAX	200


struct GLParticle
{
	bool 		isAlive;
	GLFloat2 	position;
	GLFloat2 	size;
	GLFloat2 	moveVector;
	GLColor 	color;
	float 		spin;
	float 		spinSpeed;
	float 		blendSpeed;
	float 		timeout;

	GLParticle();
	void update(float dt);
	void draw();
};


struct GLParticleSystemProperties
{
	float			AngleWidth;
	GLVariablef 	MoveSpeed;
	GLVariablef 	LifeTime;
	GLVariablef 	BlendSpeed;
	GLVariablef 	SpawnRadius;
	GLVariablef 	Size;
	int				SpinType;
	GLVariablef 	SpinSpeed;
	GLColor			Color;

	GLParticleSystemProperties();
	void save(const char *filename);
	void load(const char *filename);
};


class GLParticleSystem
{
public:
	GLParticleSystem();
	virtual ~GLParticleSystem();

	void update(float dt);
	void draw();

	void explode(int count);
	void reset();
	void startEmitter(float timeout);
	void stopEmitter();

	bool  getIsEmitter() const;
	int getParticlesCount() const;
	void setTexture(GLTexture *tex);
	inline const GLTexture *getTexture() const { return texture; }

	//position
	GLFloat2	position;
	float		rotation;
	GLParticleSystemProperties Properties;

private:
	void resetParticle(int i);

	//particles
	GLParticle 	particles[GLPLUS_PARTICLES_MAX];
	int 		particlesCount;
	GLTexture* 	texture;

	//emitter
	bool		emitterEnabled;
	float		emitterTimer;
	float		emitterTimeout;
};


#endif /* GLPARTICLESYSTEM_H_ */
