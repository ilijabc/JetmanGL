/*
 * JetmanPlayer.h
 *
 *  Created on: Jun 19, 2012
 *      Author: Ilija
 */

#ifndef JETMANPLAYER_H_
#define JETMANPLAYER_H_

#include "GameCommon.h"

class GamePlayer: public GameObject
{
public:
	GamePlayer(b2Body *b);
	virtual ~GamePlayer();

	virtual void onUpdate(float dt);
	virtual void onDraw(GLView *view);
	virtual void onCollision(b2Body *other);
};

#endif /* JETMANPLAYER_H_ */
