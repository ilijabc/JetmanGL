/*
 * GUIEventListener.h
 *
 *  Created on: 20.11.2012.
 *      Author: idjukic
 */

#ifndef GUIEVENTLISTENER_H_
#define GUIEVENTLISTENER_H_

#include "GUIControl.h"

#define GUI_MAX_EVENTS 64

struct GUIEvent
{
	//type
	enum Type
	{
		e_clickEvent = 1,
		e_keyPressEvent
	};
	//attributes
	Type type;
	GUIControl *control;
};

class GUIEventListener
{
public:
	GUIEventListener();
	virtual ~GUIEventListener();
	virtual void onEvent(GUIEvent *e) = 0;
	bool sendEvent(GUIEvent::Type t, GUIControl *c);
private:
	friend class GUIForm;
	void processEvents();
	void clearEvents();
private:
	GUIEvent mEventList[GUI_MAX_EVENTS];
	int mEventCount;
};

#endif /* GUIEVENTLISTENER_H_ */
