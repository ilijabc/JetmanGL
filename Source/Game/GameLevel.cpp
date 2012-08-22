/*
 * GameLevel.cpp
 *
 *  Created on: Jun 19, 2012
 *      Author: Ilija
 */

#include "GameLevel.h"

GameLevel::GameLevel()
{
	world = new b2World(b2Vec2(0, -10));
	worldUpdateTimeout = 0;

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);
	b2Body* groundBody = world->CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	b2Body* body = world->CreateBody(&bodyDef);
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);
}

GameLevel::~GameLevel()
{
	delete world;
	for (std::list<GameObject*>::iterator iobj = gameObjectList.begin(); iobj != gameObjectList.end(); iobj++)
	{
		delete *iobj;
	}
}

void GameLevel::update(float dt)
{
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	worldUpdateTimeout += dt;
	if (worldUpdateTimeout >= timeStep)
	{
		world->Step(timeStep, velocityIterations, positionIterations);
		worldUpdateTimeout -= timeStep;
	}
	for (std::list<GameObject*>::iterator iobj = gameObjectList.begin(); iobj != gameObjectList.end(); iobj++)
	{
		(*iobj)->onUpdate(dt);
	}
}



void GameLevel::draw(GLView *view)
{
	b2Body *body = world->GetBodyList();
	while (body)
	{
		GameObject* obj = (GameObject*)body->GetUserData();
		b2Vec2 position = body->GetPosition();
		float rotation = body->GetAngle() * GLPLUS_TODEG;
		glPushMatrix();
		glTranslatef(position.x, position.y, 0);
		glRotatef(rotation, 0, 0, 1);
		if (obj)
		{
			obj->onDraw(view);
		}
		drawBodyDebug(body);
		glPopMatrix();
		//next
		body = body->GetNext();
	}
}

void GameLevel::drawBodyDebug(b2Body *body)
{
	glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
	b2Fixture *fix = body->GetFixtureList();
	while (fix)
	{
		b2Shape *shape = fix->GetShape();
		if (shape)
		{
			if (shape->GetType() == b2Shape::e_polygon)
			{
				b2PolygonShape *poly = (b2PolygonShape*)shape;
				for (int i = 0; i < poly->GetVertexCount(); i++)
				{
					b2Vec2 v = poly->GetVertex(i);
					glVertex2f(v.x, v.y);
				}
			}
		}
		//next
		fix = fix->GetNext();
	}
	glEnd();
}

