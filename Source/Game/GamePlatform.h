#ifndef GAMEPLATFORM_H
#define GAMEPLATFORM_H

#include "GameCommon.h"


class GamePlatform : public GameObject
{
public:
    enum Type
    {
        FLOOR = 0,
        CEILING,
        ISLAND
    };

public:
    GamePlatform(GameLevel *level, float x1, float y1, float x2, float y2, Type type);
    virtual ~GamePlatform();
	virtual void onUpdate(float dt);
	virtual void onDraw(GLView *view);
	virtual void onCollision(b2Body *other);

private:
    void generateFloor();
    void generateCeiling();
    void generateIsland();

private:
    float mPositionX;
    float mPositionY;
    float mSizeX;
    float mSizeY;
    Type mType;
};

#endif // GAMEPLATFORM_H
