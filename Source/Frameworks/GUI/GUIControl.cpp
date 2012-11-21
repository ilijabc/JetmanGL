/*
 * GUIControl.cpp
 *
 *  Created on: Nov 17, 2012
 *      Author: Ilija
 */

#include "GUIControl.h"

#include <stdio.h>

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
		, mTextAlign(0)
		, mTextPositionX(0)
		, mTextPositionY(0)
		, mDrawFlags(0)
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

void GUIControl::onDraw(GLView *view)
{
}

void GUIControl::onClick()
{
	printf("onClick not implemented!\n");
}

void GUIControl::setPosition(int left, int top, int width, int height)
{
	mLeft = left;
	mTop = top;
	if (width > -1) mWidth = width;
	if (height > -1) mHeight = height;
	updateTextPosition();
}

GUIControl *GUIControl::pickControl(int x, int y)
{
	if (x >= mLeft && x < mLeft + mWidth &&
		y >= mTop && y < mTop + mHeight)
	{
		GUIControl *child = NULL;
		std::list<GUIControl*>::reverse_iterator ictl;
		for (ictl = mControlList.rbegin(); ictl != mControlList.rend(); ictl++)
		{
			child = (*ictl)->pickControl(x - mLeft, y - mTop);
			if (child)
				break;
		}
		if (child)
			return child;
		else
			return this;
	}
	return NULL;
}

void GUIControl::drawControl(GLView *view, int x, int y)
{
	glLoadIdentity();
	glTranslatef(x, y, 0);
	//clipping
	int sx = x;
	int sy = y;
	int sw = mWidth;
	int sh = mHeight;
	if (mParent)
	{
		if (mLeft < 0) sx = x - mLeft;
		if (mTop < 0) sy = y - mTop;
		if (mLeft + mWidth > mParent->mWidth) sw = mParent->mWidth - mLeft;
		if (mTop + mHeight > mParent->mHeight) sh = mParent->mHeight - mTop;
	}
	glScissor(sx - 1, view->getHeight() - sy - sh - 1, sw + 1, sh + 1);
	//draw event!
	onDraw(view);
	//children
	std::list<GUIControl*>::iterator ictl;
	for (ictl = mControlList.begin(); ictl != mControlList.end(); ictl++)
	{
		GUIControl *ctl = *ictl;
		ctl->drawControl(view, x + ctl->getLeft(), y + ctl->getTop());
	}
}

void GUIControl::updateTextPosition()
{
	if (mFont)
	{
		int text_w = mFont->getStringWidth(mText.c_str());
		int text_h = mFont->getStringHeight(mText.c_str());
		mTextPositionX = 0;
		mTextPositionY = 0;
		if ((mTextAlign & e_alignCenter) == e_alignCenter)
			mTextPositionX = mWidth / 2 - text_w / 2;
		if ((mTextAlign & e_alignRight) == e_alignRight)
			mTextPositionX = mWidth - text_w;
		if ((mTextAlign & e_alignMiddle) == e_alignMiddle)
			mTextPositionY = mHeight / 2 - text_h / 2;
		if ((mTextAlign & e_alignBottom) == e_alignBottom)
			mTextPositionY = mHeight - text_h;
	}
}
