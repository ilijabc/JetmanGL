/*
 * GUIControl.cpp
 *
 *  Created on: Nov 17, 2012
 *      Author: Ilija
 */

#include "GUIControl.h"

GUIControl::GUIControl(GUIControl *parent, int type)
		: mParent(parent)
		, mType(type)
		, mForm(NULL)
		, mLeft(0)
		, mTop(0)
		, mWidth(0)
		, mHeight(0)
		, mVisible(true)
		, mEnabled(true)
		, mText("")
		, mStateFlags(0)
		, mFont(NULL)
{
	if (parent)
	{
		parent->mControlList.push_back(this);
		mForm = parent->mForm;
		mFont = parent->mFont;
	}
}

GUIControl::~GUIControl()
{
}

void GUIControl::setPosition(int left, int top, int width, int height)
{
	mLeft = left;
	mTop = top;
	if (width > -1) mWidth = width;
	if (height > -1) mHeight = height;
}

void GUIControl::setText(const char *text)
{
	mText = text;
}

GUIControl *GUIControl::pickControl(int x, int y)
{
	if (x >= mLeft && x < mLeft + mWidth &&
		y >= mTop && y < mTop + mHeight)
	{
		GUIControl *top_child = NULL;
		std::list<GUIControl*>::iterator ictl;
		for (ictl = mControlList.begin(); ictl != mControlList.end(); ictl++)
		{
			GUIControl *child = (*ictl)->pickControl(mLeft + x, mTop + y);
			if (child)
				top_child = child;
		}
		if (top_child)
			return top_child;
		else
			return this;
	}
	return NULL;
}

void GUIControl::drawControl(GLView *view)
{
	onDraw(view);
	//children
	glPushMatrix();
	glTranslatef(mLeft, mTop, 0);
	std::list<GUIControl*>::iterator ictl;
	for (ictl = mControlList.begin(); ictl != mControlList.end(); ictl++)
	{
		(*ictl)->drawControl(view);
	}
	glPopMatrix();
}
