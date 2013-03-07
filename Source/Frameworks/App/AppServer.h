/*
 * AppServer.h
 *
 *  Created on: 29.01.2013.
 *      Author: idjukic
 */

#ifndef APPSERVER_H_
#define APPSERVER_H_

#include "AppClient.h"


class AppServer
{
public:
	struct Settings
	{
		int width;
		int height;
		int fullscreen;
		int desktop;
		int audio;
	};

public:
	AppServer(const char *settings_path);
	virtual ~AppServer();
	int run(AppClient* client);
	//getters
	Settings getSettings() const { return mSettings; }
	AppClient *getClient() const { return mClient; }

private:
	Settings mSettings;
	AppClient *mClient;
	bool mInitialized;
	bool mRunning;
};

#endif /* APPSERVER_H_ */
