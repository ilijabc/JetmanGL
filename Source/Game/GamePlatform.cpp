#include "GamePlatform.h"
#include "GameLevel.h"

GamePlatform::GamePlatform(GameLevel *level, float x1, float y1, float x2, float y2, Type type)
: GameObject(level)
{
    float x = (x1 + x2) / 2;
    float y = (y1 + y2) / 2;
    float w = x2 - x1;
    float h = y2 - y1;

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(x, y);
    mBody = level->getWorld()->CreateBody(&groundBodyDef);
    mBody->SetUserData(this);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(w, h);
    mBody->CreateFixture(&groundBox, 0.0f);
}

GamePlatform::~GamePlatform()
{
}

void GamePlatform::onUpdate(float dt)
{
}

void GamePlatform::onDraw(GLView *view)
{
}

void GamePlatform::onCollision(b2Body *other)
{
}
