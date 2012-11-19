/*
 * GUIControl.h
 *
 *  Created on: Nov 17, 2012
 *      Author: Ilija
 */

#ifndef GUICONTROL_H_
#define GUICONTROL_H_

#include "GLPlus/GLView.h"
#include "GLPlus/GLFont.h"
#include <list>
#include <string>

class GUIForm;

class GUIControl
{
public:
	GUIControl(GUIControl *parent, int type);
	virtual ~GUIControl();
	//callbacks
	virtual void onDraw(GLView *view) { }
	virtual void onClick() { }
	//setters
	void setPosition(int left, int top, int width = -1, int height = -1);
	inline void setVisible(bool visible) { mVisible = visible; }
	inline void setEnabled(bool enabled) { mEnabled = enabled; }
	void setText(const char *text);
	inline void setStateFlags(int flags) { mStateFlags = flags; }
	inline void setFont(GLFont *font) { mFont = font; }
	//getters
	inline GUIControl *getParent() const { return mParent; }
	inline GUIForm *getForm() const { return mForm; }
	inline int getType() const { return mType; }
	inline int getLeft() const { return mLeft; }
	inline int getTop() const { return mTop; }
	inline int getWidth() const { return mWidth; }
	inline int getHeight() const { return mHeight; }
	inline const char *getText() const { return mText.c_str(); }
	inline int getStateFlags() const { return mStateFlags; }
	inline GLFont *getFont() const { return mFont; }
	//control
	GUIControl *pickControl(int x, int y);

protected:
	void drawControl(GLView *view);

protected:
	GUIControl *mParent;
	std::list<GUIControl*> mControlList;
	GUIForm *mForm;
	int mType;
	int mLeft;
	int mTop;
	int mWidth;
	int mHeight;
	bool mVisible;
	bool mEnabled;
	std::string mText;
	int mStateFlags;
	GLFont *mFont;
};

#endif /* GUICONTROL_H_ */
