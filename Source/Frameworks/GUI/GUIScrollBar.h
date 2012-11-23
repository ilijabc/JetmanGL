/*
 * GUIScrollBar.h
 *
 *  Created on: 23.11.2012.
 *      Author: idjukic
 */

#ifndef GUISCROLLBAR_H_
#define GUISCROLLBAR_H_

#include "GUIControl.h"

class GUIScrollBar: public GUIControl
{
public:
	enum Orientation
	{
		e_verticalOrientation = 0,
		e_horizontalOrientation
	};
public:
	GUIScrollBar(GUIControl *parent);
	virtual ~GUIScrollBar();
	//callbacks
	virtual void onDraw(GLView *view);
	virtual void onMouseDown(int x, int y);
	virtual void onMouseUp(int x, int y);
	virtual void onMouseMove(int x, int y);
	//setters
	inline void setOrientation(Orientation o) { mOrientation = o; }
	//getters
	inline Orientation getOrientation() const { return mOrientation; }

private:
	int mScrollPos;
	bool mIsClicked;
	Orientation mOrientation;
};

#endif /* GUISCROLLBAR_H_ */
