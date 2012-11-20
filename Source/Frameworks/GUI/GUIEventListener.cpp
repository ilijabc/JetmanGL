/*
 * GUIEventListener.cpp
 *
 *  Created on: 20.11.2012.
 *      Author: idjukic
 */

#include "GUIEventListener.h"

GUIEventListener::GUIEventListener()
{
	mEventCount = 0;
}

GUIEventListener::~GUIEventListener()
{
	clearEvents();
}

bool GUIEventListener::sendEvent(GUIEvent::Type t, GUIControl *c)
{
	if (mEventCount == GUI_MAX_EVENTS - 1)
		return false;
	mEventList[mEventCount].type = t;
	mEventList[mEventCount].control = c;
	mEventCount++;
	return true;
}

void GUIEventListener::processEvents()
{
	for (int i = mEventCount - 1; i >= 0; i--)
	{
		onEvent(&mEventList[i]);
	}
	clearEvents();
}

void GUIEventListener::clearEvents()
{
	mEventCount = 0;
}
