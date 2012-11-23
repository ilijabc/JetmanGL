/*
 * GUIForm.h
 *
 *  Created on: Nov 17, 2012
 *      Author: Ilija
 */

#ifndef GUIFORM_H_
#define GUIFORM_H_

#include "GUIControl.h"
#include "GUIEventListener.h"

class GUIForm: public GUIControl
{
public:
	struct MouseState
	{
		int x;
		int y;
		int buttonDown;
	};
public:
	GUIForm(int left, int top, int width, int height);
	virtual ~GUIForm();
	//callbacks
	virtual void onDraw(GLView *view);
	//control
	bool sendMouseDown();
	bool sendMouseUp();
	void sendMouseMove(int x, int y);
	void sendKeyPress(char key);
	void doEvents();
	//draw
	void draw(GLView *view);
	//control
	template <class T> T* addControl(int x, int y, int w, int h, const char *text = NULL)
	{
		T* ctl = new T(this);
		ctl->setPosition(x, y, w, h);
		if (text)
			ctl->setText(text);
		return ctl;
	}
	//setters
	inline void setEventListener(GUIEventListener *listener) { mEventListener = listener; }
	//getters
	//inline const MouseState &getMouseState() const { return mMouseState; }
	//GUIControl *getHoveredControl() const { return mHoveredControl; }
	//GUIControl *getClickedControl() const { return mClickedControl; }
	//GUIControl *getFocusedControl() const { return mFocusedControl; }

private:
	MouseState mMouseState;
	GUIControl *mHoveredControl;
	GUIControl *mClickedControl;
	GUIControl *mFocusedControl;
	GUIEventListener *mEventListener;
};

#endif /* GUIFORM_H_ */
