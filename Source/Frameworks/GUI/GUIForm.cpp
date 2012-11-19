/*
 * GUIForm.cpp
 *
 *  Created on: Nov 17, 2012
 *      Author: Ilija
 */

#include "GUIForm.h"

GUIForm::GUIForm(int left, int top, int width, int height)
		: GUIControl(NULL, 0)
{
	setPosition(left, top, width, height);
	mMouseState.x = 0;
	mMouseState.y = 0;
	mMouseState.buttonDown = 0;
	mHoveredControl = NULL;
}

GUIForm::~GUIForm()
{
}

void GUIForm::onDraw(GLView *view)
{
	float x1 = mLeft;
	float y1 = mTop;
	float x2 = mLeft + mWidth;
	float y2 = mTop + mHeight;
	//fill
	glBegin(GL_QUADS);
	glColor4f(1, 1, 1, 0.6);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
	//border
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
}

bool GUIForm::sendButtonDown()
{
	mMouseState.buttonDown = 1;
	return mHoveredControl && mHoveredControl != this;
}

bool GUIForm::sendButtonUp()
{
	mMouseState.buttonDown = 0;
	return mHoveredControl && mHoveredControl != this;
}

void GUIForm::sendMouseMove(int x, int y)
{
	mMouseState.x = x;
	mMouseState.y = y;
	GUIControl *hover = pickControl(x, y);
	if (hover != mHoveredControl)
	{
		if (mHoveredControl)
			mHoveredControl->setStateFlags(0);
		if (hover)
			hover->setStateFlags(1);
		mHoveredControl = hover;
	}
}

void GUIForm::sendKeyPress(char key)
{
}

void GUIForm::draw(GLView *view)
{
	drawControl(view);
}
