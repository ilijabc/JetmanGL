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
	mClickedControl = NULL;
	mFocusedControl = NULL;
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
	glColor4f(0, 0, 0, 0.6);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
	//border
	glBegin(GL_LINE_LOOP);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
}

bool GUIForm::sendButtonDown()
{
	mMouseState.buttonDown = 1;
	mClickedControl = mHoveredControl;
	if (mClickedControl)
	{
		mClickedControl->setDrawFlag(GUIControl::e_drawClickedFlag, true);
	}
	return mHoveredControl && mHoveredControl != this;
}

bool GUIForm::sendButtonUp()
{
	mMouseState.buttonDown = 0;
	if (mClickedControl)
	{
		mClickedControl->setDrawFlag(GUIControl::e_drawClickedFlag, false);
		if (mClickedControl == mHoveredControl)
		{
			//click event !
			mClickedControl->onClick();
		}
	}
	mClickedControl = NULL;
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
			mHoveredControl->setDrawFlag(GUIControl::e_drawHoveredFlag, false);
		if (hover)
			hover->setDrawFlag(GUIControl::e_drawHoveredFlag, true);
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
