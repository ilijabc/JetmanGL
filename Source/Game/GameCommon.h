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


class GameObject
{
public:
	GameObject(b2Body *b) { body = b; }
	virtual ~GameObject() { }
	//events
	virtual void onUpdate(float dt) = 0;
	virtual void onDraw(GLView *view) = 0;
	virtual void onCollision(b2Body *other) = 0;
	//funcs
	inline b2Body *getBody() const { return body; }
protected:
	b2Body *body;
};

#ifdef DEBUG
#define LOG(msg, args...) printf("[%d] "msg"\n", (int)time(NULL), ##args)
#else
#define LOG(args...)
#endif

inline float randf() { return (float)rand() / (float)RAND_MAX; }

#endif /* GAMECOMMON_H_ */
