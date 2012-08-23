/*
 * GameCommon.h
 *
 *  Created on: Jun 15, 2012
 *      Author: Ilija
 */

#ifndef GAMECOMMON_H_
#define GAMECOMMON_H_

#include "GLPlus/GLPlus.h"
#include "Box2D/Box2D.h"
#include <stdio.h>
#include <stdlib.h>
#include <list>

class GameLevel;

struct Rect
{
    float x1, y1, x2, y2;
    Rect() : x1(0), y1(0), x2(0), y2(0) { }
    Rect(float _x1, float _y1, float _x2, float _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) { }
    inline bool testPoint(float x, float y) { return (x >= x1 && x <= x2 && y >= y1 && y <= y2); }
};

class GameObject
{
public:
	GameObject(GameLevel *level) : mLevel(level), mBody(NULL) { }
	virtual ~GameObject() { }
	//events
	virtual void onUpdate(float dt) = 0;
	virtual void onDraw(GLView *view) = 0;
	virtual void onCollision(b2Body *other) = 0;
	//funcs
	inline b2Body *getBody() const { return mBody; }
    inline void setBounds(float x1, float y1, float x2, float y2) { mBounds = Rect(x1, y1, x2, y2); }
    inline const Rect& getBounds() const { return mBounds; }
protected:
    GameLevel *mLevel;
	b2Body *mBody;
    Rect mBounds;
};

#ifdef DEBUG
#define LOG(msg, args...) printf("[%d] "msg"\n", (int)time(NULL), ##args)
#else
#define LOG(args...)
#endif

inline float randf() { return (float)rand() / (float)RAND_MAX; }
inline float randf(float max) { return (float)rand() / (float)RAND_MAX * max; }
inline float randf(float min, float max) { return (float)rand() / (float)RAND_MAX * (max - min) + min; }

#define MIN(A, B) (((A) < (B)) ? (A) : (B))
#define MAX(A, B) (((A) > (B)) ? (A) : (B))

#endif /* GAMECOMMON_H_ */
