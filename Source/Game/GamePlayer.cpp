/*
 * GamePlayer.cpp
 *
 *  Created on: Jun 19, 2012
 *      Author: Ilija
 */

#include "GamePlayer.h"

GamePlayer::GamePlayer(b2Body *b) : GameObject(b)
{
    b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	b->CreateFixture(&fixtureDef);
}

GamePlayer::~GamePlayer()
{
}

void GamePlayer::onUpdate(float dt)
{
}

void GamePlayer::onDraw(GLView *view)
{
	glColor3f(1,0,0);
	glRectf(-0.5, -0.5, 0.5, 0.5);
}

void GamePlayer::onCollision(b2Body *other)
{
}
