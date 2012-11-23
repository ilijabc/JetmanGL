/*
 * GUIScrollBar.cpp
 *
 *  Created on: 23.11.2012.
 *      Author: idjukic
 */

#include "GUIScrollBar.h"

GUIScrollBar::GUIScrollBar(GUIControl *parent)
		: GUIControl(parent, 0)
		, mScrollPos(0)
		, mIsClicked(false)
		, mOrientation(e_verticalOrientation)
{
}

GUIScrollBar::~GUIScrollBar()
{
}

void GUIScrollBar::onDraw(GLView *view)
{
	//background
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(0, 0);
	glVertex2f(mWidth, 0);
	glVertex2f(mWidth, mHeight);
	glVertex2f(0, mHeight);
	glEnd();
	if (mOrientation == e_verticalOrientation)
	{
		//vertical scroller
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex2f(0, 0);
		glVertex2f(mWidth, 0);
		glVertex2f(mWidth, mScrollPos);
		glVertex2f(0, mScrollPos);
		glEnd();
	}
	else
	{
		//horizontal scroller
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex2f(0, 0);
		glVertex2f(mScrollPos, 0);
		glVertex2f(mScrollPos, mHeight);
		glVertex2f(0, mHeight);
		glEnd();
	}
}

void GUIScrollBar::onMouseDown(int x, int y)
{
	mIsClicked = true;
	onMouseMove(x, y);
}

void GUIScrollBar::onMouseUp(int x, int y)
{
	mIsClicked = false;
}

void GUIScrollBar::onMouseMove(int x, int y)
{
	if (mIsClicked)
	{
		if (mOrientation == e_verticalOrientation)
		{
			mScrollPos = y - mScreenY;
		}
		else
		{
			mScrollPos = x - mScreenX;
		}
	}
}
