/*
 * GUIButton.cpp
 *
 *  Created on: Nov 17, 2012
 *      Author: Ilija
 */

#include "GUIButton.h"

GUIButton::GUIButton(GUIControl *parent)
		: GUIControl(parent, 0)
{
	setTextAlign(GUIControl::e_alignCenter | GUIControl::e_alignMiddle);
}

void GUIButton::onDraw(GLView *view)
{
	float x1 = mLeft;
	float y1 = mTop;
	float x2 = mLeft + mWidth;
	float y2 = mTop + mHeight;
	//fill
	glBegin(GL_QUADS);
	if (getDrawFlag(GUIControl::e_drawHoveredFlag))
		glColor4f(1, 1, 1, 0.2);
	else
		glColor4f(1, 1, 1, 0.4);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
	//border
	glBegin(GL_LINE_LOOP);
	if (getDrawFlag(GUIControl::e_drawClickedFlag))
		glColor3f(1, 1, 0);
	else
		glColor3f(1, 1, 1);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
	//text
	if (mFont)
	{
		//glColor3f(1, 1, 1);
		mFont->drawString(x1 + mTextPositionX, y1 + mTextPositionY, mText.c_str());
	}
	glDisable(GL_TEXTURE_2D); // TODO: this is bypass for problem in GLFont (texture not turned off after print)
}
