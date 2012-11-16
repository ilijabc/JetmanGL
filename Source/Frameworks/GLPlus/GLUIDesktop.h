/*
 * GLUIDesktop.h
 *
 *  Created on: 16.11.2012.
 *      Author: idjukic
 */

#ifndef GLUIDESKTOP_H_
#define GLUIDESKTOP_H_

#include "GLView.h"
#include "GLUIWidget.h"

class GLUIDesktop : public GLUIWidget
{
public:
	GLUIDesktop(int width, int height);
	virtual ~GLUIDesktop();
	//override
	virtual void onDraw(GLView *view);
	//control
	bool sendButtonDown();
	bool sendButtonUp();
	void sendMouseMove(int x, int y);
	void sendKeyPress(char key);
	//draw
	void draw(GLView *view);

private:
	struct
	{
		int x;
		int y;
		int buttonDown;
	} mMouseState;
	GLUIWidget *mHoveredWidget;
};

#endif /* GLUIDESKTOP_H_ */
