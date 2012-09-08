/*
 * JetmanPlayer.h
 *
 *  Created on: Jun 19, 2012
 *      Author: Ilija
 */

#ifndef JETMANPLAYER_H_
#define JETMANPLAYER_H_

#include "GameCommon.h"

class GamePlayer
{
public:
	enum Type
	{
		BOX = 0,
		CRAFT
	};

public:
	GamePlayer(GameLevel *level, float x, float y, float w, float h, Type type);
	virtual ~GamePlayer();
	virtual void onUpdate(float dt);
	virtual void onDraw(GLView *view);
	virtual void onCollision(b2Body *other);
	inline void setTexture(GLTexture *tex) { mTexture = tex; }
	inline GLTexture *getTexture() const { return mTexture; }

private:
    GameLevel *mLevel;
	b2Body *mBody;
    GLTexture *mTexture;
};

#endif /* JETMANPLAYER_H_ */
