/*
 * GLUIDesktop.cpp
 *
 *  Created on: 16.11.2012.
 *      Author: idjukic
 */

#include "GLUIDesktop.h"

GLUIDesktop::GLUIDesktop(int width, int height)
		: GLUIWidget(NULL, 0)
{
	setSize(width, height);
	mMouseState.x = 0;
	mMouseState.y = 0;
	mMouseState.buttonDown = 0;
	mHoveredWidget = NULL;
}

GLUIDesktop::~GLUIDesktop()
{
	// TODO Auto-generated destructor stub
}

void GLUIDesktop::onDraw(GLView *view)
{
	//nothing
}

bool GLUIDesktop::sendButtonDown()
{
	mMouseState.buttonDown = 1;
	return mHoveredWidget && mHoveredWidget != this;
}

bool GLUIDesktop::sendButtonUp()
{
	mMouseState.buttonDown = 0;
	return mHoveredWidget && mHoveredWidget != this;
}

void GLUIDesktop::sendMouseMove(int x, int y)
{
	mMouseState.x = x;
	mMouseState.y = y;
	GLUIWidget *hover = pickWidget(x, y);
	if (hover != mHoveredWidget)
	{
		if (mHoveredWidget)
			mHoveredWidget->setDrawFlags(0);
		if (hover)
			hover->setDrawFlags(1);
		mHoveredWidget = hover;
	}
}

void GLUIDesktop::sendKeyPress(char key)
{
}

void GLUIDesktop::draw(GLView *view)
{
	drawWidget(view);
}
