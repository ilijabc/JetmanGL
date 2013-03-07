/*
 * GameClient.cpp
 *
 *  Created on: 19.10.2012.
 *      Author: idjukic
 */

#include "AppClient.h"
#include <string.h>

AppClient::AppClient(AppServer *server)
{
	mServer = server;
}

AppClient::~AppClient()
{
	for (int i = 0; i < mTexturePool.size(); i++)
	{
		delete mTexturePool[i];
	}
}

GLTexture *AppClient::getTexture(const char *filename, int flags)
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
