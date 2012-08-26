/*
 * GamePlayer.cpp
 *
 *  Created on: Jun 19, 2012
 *      Author: Ilija
 */

#include "GamePlayer.h"
#include "GameLevel.h"

GamePlayer::GamePlayer(GameLevel *level, float x, float y, float w, float h, Type type)
: GameObject(level)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    if (type == CRAFT)
        bodyDef.fixedRotation = true;
    mBody = level->getWorld()->CreateBody(&bodyDef);
    mBody->SetUserData(this);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(w / 2, h / 2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.5f;
    mBody->CreateFixture(&fixtureDef);

    mTexture = NULL;
    mBounds = Rect(-w / 2, -h / 2, w / 2, h / 2);
}

GamePlayer::~GamePlayer()
{
}

void GamePlayer::onUpdate(float dt)
{
    b2Vec2 v = mBody->GetLinearVelocity();

}

void GamePlayer::onDraw(GLView *view)
{
    float u2 = 1;
    //if (mBody->GetLinearVelocity().x < 0)
    //    u2 = -1;
	glColor3f(1, 1, 1);
	if (mTexture)
    {
        mTexture->drawImage(mBounds.x1, mBounds.y1, mBounds.x2, mBounds.y2,
                            0, 0, u2, 1);
    }
}

void GamePlayer::onCollision(b2Body *other)
{
}
