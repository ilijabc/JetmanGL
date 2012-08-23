#include "GamePlatform.h"
#include "GameLevel.h"

GamePlatform::GamePlatform(GameLevel *level, float x1, float y1, float x2, float y2, Type type)
: GameObject(level)
{
    mPositionX = (x1 + x2) ? ((x1 + x2) / 2) : 0;
    mPositionY = (y1 + y2) ? ((y1 + y2) / 2) : 0;
    mSizeX = (x2 - x1) / 2;
    mSizeY = (y1 - y2) / 2;
    mType = type;
    printf("platform: %f %f %f %f\n", mPositionX, mPositionY, mSizeX, mSizeY);

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(mPositionX, mPositionY);
    mBody = level->getWorld()->CreateBody(&groundBodyDef);
    mBody->SetUserData(this);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(mSizeX, mSizeY);
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
    switch (mType)
    {
    case FLOOR:
        glColor4f(1, 0, 0, 0.5);
        break;
    case CEILING:
        glColor4f(0, 1, 0, 0.5);
        break;
    case ISLAND:
        glColor4f(0, 0, 1, 0.5);
        break;
    }
    glRectf(-mSizeX, -mSizeY, mSizeX, mSizeY);
}

void GamePlatform::onCollision(b2Body *other)
{
}
