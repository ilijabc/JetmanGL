/*
 * GLUIWidget.h
 *
 *  Created on: 16.11.2012.
 *      Author: idjukic
 */

#ifndef GLUIWIDGET_H_
#define GLUIWIDGET_H_

#include "GLView.h"
#include "GLFont.h"
#include <list>
#include <string.h>

class GLUIWidget
{
public:
	enum
	{
		e_drawHoverFlag = 0x1,
		e_drawFocusFlag = 0x2,
		e_drawClickedFlag = 0x4
	};
public:
	GLUIWidget(GLUIWidget *parent, int type);
	virtual ~GLUIWidget();
	//callbacks
	virtual void onDraw(GLView *view);
	virtual void onClick();
	virtual void onKeyPress(char key);
	//control
	GLUIWidget *pickWidget(int x, int y);
	GLUIWidget *createWidget(int type, int left, int top, int width = 0, int height = 0, const char *text = NULL);
	//properties
	inline void setPosition(int left, int top) { mLeft = left; mTop = top; };
	inline void setSize(int width, int height) { mWidth = width; mHeight = height; }
	inline void setText(const char *text) { if (text) strcpy(mText, text); else strcpy(mText, ""); }
	inline void setDrawFlags(int flags) { mDrawFlags = flags; }
	inline void setFont(GLFont *font) { mFont = font; }
	//draw
	void drawWidget(GLView *view);
private:
	GLUIWidget *mParent;
	std::list<GLUIWidget*> mWidgetList;
	int mLeft;
	int mTop;
	int mWidth;
	int mHeight;
	char mText[256];
	int mDrawFlags;
	GLFont *mFont;
};

#endif /* GLUIWIDGET_H_ */
