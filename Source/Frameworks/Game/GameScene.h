/*
 * GameScene.h
 *
 *  Created on: 19.10.2012.
 *      Author: idjukic
 */

#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "GameCommon.h"
#include "GameObject.h"
#include "GameClient.h"

class GameScene
{
public:
	GameScene(GameClient *game);
	virtual ~GameScene();
	//control
	void update(float dt);
	void draw(GLView *view);
	GameObject *addObject(GameObject *obj);
	//loaders
	void loadSVG(const char *filename);
	//getters
    inline b2World *getWorld() const { return mWorld; }
    inline GameClient *getGame() const { return mGame; }

private:
    void drawWorldDebug();
    void drawBodyDebug(b2Body *body);

private:
    GameClient *mGame;
	b2World *mWorld;
	float mWorldUpdateTimeout;
	std::list<GameObject*> mGameObjectList;
};

#endif /* GAMESCENE_H_ */
