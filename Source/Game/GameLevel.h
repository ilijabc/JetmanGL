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

class GameLevel : public b2ContactListener
{
public:
	GameLevel(const char *level_svg);
	virtual ~GameLevel();
	virtual void BeginContact(b2Contact* contact);
	void update(float dt);
	void draw(GLView *view);
    inline b2World *getWorld() const { return mWorld; }
    //factory
    GamePlayer *createPlayer(float x, float y, float w, float h, GamePlayer::Type type);
    GamePlatform *createPlatform(float x1, float y1, float x2, float y2, GamePlatform::Type type);
    inline GamePlayer *getPlayer() const { return mPlayer; }
    GLTexture *getTexture(const char *filename);
    inline const Rect& getBounds() const { return mBounds; }

private:
	void drawBodyDebug(b2Body *body);
    void generateLevel();
    void loadSVGLevel(const char *filename);
    void loadSVGLevel_XML(const char *filename);

private:
	b2World *mWorld;
	float mWorldUpdateTimeout;
	std::list<GameObject*> mGameObjectList;
	GamePlayer *mPlayer;
	std::vector<GLTexture*> mTexturePool;
	Rect mBounds;
};

#endif /* JETMANLEVEL_H_ */
