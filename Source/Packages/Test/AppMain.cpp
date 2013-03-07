/*
 * AppMain.cpp
 *
 *  Created on: 29.01.2013.
 *      Author: idjukic
 */

#include "TestClient.h"

int main(int argc, char **argv)
{
	AppServer *server = new AppServer("Data/settings.ini");
	TestClient *game = new TestClient(server, (argc > 1) ? argv[1] : NULL);

	server->run(game);

	delete game;
	delete server;
}
