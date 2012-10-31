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
#include <string.h>
#include <time.h>
#include <list>

class GameLevel;

struct Rect
{
    float x1, y1, x2, y2;
    Rect() : x1(0), y1(0), x2(0), y2(0) { }
    Rect(float _x1, float _y1, float _x2, float _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) { }
	inline void set(float _x1, float _y1, float _x2, float _y2) { x1=_x1; y1=_y1; x2=_x2; y2=_y2; }
	inline float getCenterX() const { return (x1+x2) ? (x1+x2)/2 : 0; }
	inline float getCenterY() const { return (y1+y2) ? (y1+y2)/2 : 0; }
	inline float getWidth() const { return x2 - x1; }
	inline float getHeight() const { return y2 - y1; }
    inline bool testPoint(float x, float y) { return (x >= x1 && x <= x2 && y >= y1 && y <= y2); }
};

#ifdef DEBUG
#define LOG(msg, args...) printf("[%d] "msg"\n", (int)time(NULL), ##args)
#else
#define LOG(args...)
#endif

inline float randf() { return (float)rand() / (float)RAND_MAX; }
inline float randf(float max) { return (float)rand() / (float)RAND_MAX * max; }
inline float randf(float min, float max) { return (float)rand() / (float)RAND_MAX * (max - min) + min; }

inline void set4fv(float *pf, float x, float y, float z, float w) { pf[0]=x; pf[1]=y; pf[2]=z; pf[3]=w; }

#define MIN(A, B) (((A) < (B)) ? (A) : (B))
#define MAX(A, B) (((A) > (B)) ? (A) : (B))

inline void parseIntColor(int color, float *vcolor)
{
	vcolor[0] = ((color >> 16) & 0xFF) / 255.0f;
	vcolor[1] = ((color >> 8) & 0xFF) / 255.0f;
	vcolor[2] = ((color >> 0) & 0xFF) / 255.0f;
	vcolor[3] = ((color >> 24) & 0xFF) / 255.0f;
}

#endif /* GAMECOMMON_H_ */
