#ifndef GAMEPLATFORM_H
#define GAMEPLATFORM_H

#include "GameCommon.h"


class GamePlatform : public GameObject
{
public:
    GamePlatform(b2Body *b);
    virtual ~GamePlatform();
	virtual void onUpdate(float dt);
	virtual void onDraw(GLView *view);
	virtual void onCollision(b2Body *other);
};

#endif // GAMEPLATFORM_H
