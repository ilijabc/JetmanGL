/*
 * GameClient.cpp
 *
 *  Created on: 19.10.2012.
 *      Author: idjukic
 */

#include "GameClient.h"

GameClient::GameClient()
{
	// TODO Auto-generated constructor stub

}

GameClient::~GameClient()
{
	for (int i = 0; i < mTexturePool.size(); i++)
	{
		delete mTexturePool[i];
	}
}

GLTexture *GameClient::getTexture(const char *filename, int flags)
{
	int n = mTexturePool.size();
	for (int i = 0; i < mTexturePool.size(); i++)
	{
		if (mTexturePool[i]->getFileName() && strcmp(mTexturePool[i]->getFileName(), filename) == 0)
			return mTexturePool[i];
	}
	GLTexture *tex = new GLTexture(filename, flags);
	mTexturePool.push_back(tex);
	return tex;
}
