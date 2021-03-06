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
#include "App/AppClient.h"

class GameScene
{
public:
	enum
	{
		e_drawShapeFlag = 0x1,
		e_drawImageFlag = 0x2,
		e_drawBox2DFlag = 0x4,
		e_drawBoundsFlag = 0x8
	};

public:
	GameScene(AppClient *game);
	virtual ~GameScene();
	//control
	void update(float dt);
	void draw(GLView *view);
	GameObject *addObject(GameObject *obj, bool to_back = true);
	GameObject *getObjectByName(const char *name);
	//loaders
	void loadSVG(const char *filename);
	//setters
	inline void setDrawFlags(unsigned int flags) { mDrawFlags = flags; }
	//getters
    inline b2World *getWorld() const { return mWorld; }
    inline AppClient *getGame() const { return mGame; }
    inline unsigned int getDrawFlags() const { return mDrawFlags; }

private:
    void processGameObjects();
    void drawWorldDebug();
    void drawBodyDebug(b2Body *body);

private:
    AppClient *mGame;
	b2World *mWorld;
	float mWorldUpdateTimeout;
	std::list<GameObject*> mGameObjectList;
	unsigned int mDrawFlags;
};

#endif /* GAMESCENE_H_ */
