/*
 * GLUIWidget.cpp
 *
 *  Created on: 16.11.2012.
 *      Author: idjukic
 */

#include "GLUIWidget.h"
#include <stdio.h>

GLUIWidget::GLUIWidget(GLUIWidget *parent, int type)
		: mParent(parent)
		, mLeft(0)
		, mTop(0)
		, mWidth(1)
		, mHeight(1)
		, mDrawFlags(0)
		, mFont(NULL)
{
	if (parent)
	{
		parent->mWidgetList.push_back(this);
		mFont = parent->mFont;
	}
	strcpy(mText, "");
}

GLUIWidget::~GLUIWidget()
{
	// TODO Auto-generated destructor stub
}

void GLUIWidget::onDraw(GLView *view)
{
	float x1 = mLeft;
	float y1 = mTop;
	float x2 = mLeft + mWidth;
	float y2 = mTop + mHeight;
	//fill
	glBegin(GL_QUADS);
	if (mDrawFlags)
		glColor4f(1, 1, 1, 0.2);
	else
		glColor4f(0, 0, 0, 0.5);
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
	//text
	if (mFont)
	{
		glColor3f(1, 1, 1);
		mFont->drawString(x1, y1, mText);
	}
	glDisable(GL_TEXTURE_2D); // TODO: this is bypass for problem in GLFont (texture not turned off after print)
}

void GLUIWidget::onClick()
{

}

void GLUIWidget::onKeyPress(char key)
{

}

GLUIWidget *GLUIWidget::pickWidget(int x, int y)
{
	if (x >= mLeft && x < mLeft + mWidth &&
		y >= mTop && y < mTop + mHeight)
	{
		GLUIWidget *top_child = NULL;
		std::list<GLUIWidget*>::iterator i_widget;
		for (i_widget = mWidgetList.begin(); i_widget != mWidgetList.end(); i_widget++)
		{
			GLUIWidget *child = (*i_widget)->pickWidget(mLeft + x, mTop + y);
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

GLUIWidget *GLUIWidget::createWidget(int type, int left, int top, int width, int height, const char *text)
{
	GLUIWidget *widget = new GLUIWidget(this, type);
	widget->setPosition(left, top);
	widget->setSize(width, height);
	widget->setText(text);
	return widget;
}

void GLUIWidget::drawWidget(GLView *view)
{
	onDraw(view);
	//children
	glPushMatrix();
	glTranslatef(mLeft, mTop, 0);
	std::list<GLUIWidget*>::iterator i_widget;
	for (i_widget = mWidgetList.begin(); i_widget != mWidgetList.end(); i_widget++)
	{
		(*i_widget)->drawWidget(view);
	}
	glPopMatrix();
}
