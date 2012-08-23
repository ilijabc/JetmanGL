/*
 * GameLevel.cpp
 *
 *  Created on: Jun 19, 2012
 *      Author: Ilija
 */

#include "GameLevel.h"

GameLevel::GameLevel()
{
	mWorld = new b2World(b2Vec2(0, -10));
	mWorldUpdateTimeout = 0;

	float ww = 100;
	float hh = 50;
	GamePlatform *floor = createPlatform(-ww, -(hh - 2), ww, -hh, GamePlatform::FLOOR);
	GamePlatform *ceiling = createPlatform(-ww, hh, ww, (hh - 2), GamePlatform::CEILING);
	int ni = 5;
	for (int i = 0; i <= ni; i++)
	{
		int nj = rand() % 3 + 1;
		for (int j = 0; j <= nj; j++)
		{
			float w = randf(15) + 6;
			float h = randf(4) + 4;
			float x = (float)i / (float)ni * (ww * 0.8 * 2) - ww * 0.8 + randf(-2, 2);
			float y = (float)j / (float)nj * (hh * 0.8 * 2) - hh * 0.8;
			float x1 = x - w;
			float y1 = y + h;
			float x2 = x + w;
			float y2 = y - h;
			GamePlatform *island = createPlatform(x1, y1, x2, y2, GamePlatform::ISLAND);
		}
	}
	GamePlayer *player = createPlayer(0.0f, 4.0f);
}

GameLevel::~GameLevel()
{
	for (std::list<GameObject*>::iterator iobj = mGameObjectList.begin(); iobj != mGameObjectList.end(); iobj++)
	{
		delete *iobj;
	}
	delete mWorld;
}

void GameLevel::update(float dt)
{
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	mWorldUpdateTimeout += dt;
	if (mWorldUpdateTimeout >= timeStep)
	{
		mWorld->Step(timeStep, velocityIterations, positionIterations);
		mWorldUpdateTimeout -= timeStep;
	}
	for (std::list<GameObject*>::iterator iobj = mGameObjectList.begin(); iobj != mGameObjectList.end(); iobj++)
	{
		(*iobj)->onUpdate(dt);
	}
}

void GameLevel::draw(GLView *view)
{
	for (std::list<GameObject*>::iterator iobj = mGameObjectList.begin(); iobj != mGameObjectList.end(); iobj++)
	{
		GameObject* obj = *iobj;
		b2Vec2 position = obj->getBody()->GetPosition();
		float rotation = obj->getBody()->GetAngle() * GLPLUS_TODEG;
		glPushMatrix();
		glTranslatef(position.x, position.y, 0);
		glRotatef(rotation, 0, 0, 1);
		obj->onDraw(view);
		glPopMatrix();
	}
	// DEBUG DRAW FOR BOX2D
	for (b2Body *body = mWorld->GetBodyList(); body; body = body->GetNext())
	{
		b2Vec2 position = body->GetPosition();
		float rotation = body->GetAngle() * GLPLUS_TODEG;
		glPushMatrix();
		glTranslatef(position.x, position.y, 0);
		glRotatef(rotation, 0, 0, 1);
		drawBodyDebug(body);
		glPopMatrix();
	}
}

// Factory

GamePlayer *GameLevel::createPlayer(float x, float y)
{
	GamePlayer *player = new GamePlayer(this, x, y);
	mGameObjectList.push_back(player);
	return player;
}

GamePlatform *GameLevel::createPlatform(float x1, float y1, float x2, float y2, GamePlatform::Type type)
{
	GamePlatform *platform = new GamePlatform(this, x1, y1, x2, y2, type);
	mGameObjectList.push_back(platform);
	return platform;
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

