/*
 * JetmanLevel.h
 *
 *  Created on: Jun 19, 2012
 *      Author: Ilija
 */

#ifndef JETMANLEVEL_H_
#define JETMANLEVEL_H_

#include "GameCommon.h"
#include "GamePlayer.h"
#include "GamePlatform.h"

class GameLevel
{
public:
	GameLevel();
	virtual ~GameLevel();
	void update(float dt);
	void draw(GLView *view);
    inline b2World *getWorld() const { return mWorld; }
    //factory
    GamePlayer *createPlayer(float x, float y);
    GamePlatform *createPlatform(float x1, float y1, float x2, float y2, GamePlatform::Type type);

private:
	void drawBodyDebug(b2Body *body);

private:
	b2World *mWorld;
	float mWorldUpdateTimeout;
	std::list<GameObject*> mGameObjectList;
};

#endif /* JETMANLEVEL_H_ */
