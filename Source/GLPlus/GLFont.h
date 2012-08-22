#ifndef GLFONT_H
#define GLFONT_H

#include "GLTexture.h"
#include "GLMath.h"
#include "BMFont.h"
#include <string>
#include <list>

class GLFont
{
public:
	GLFont(const char* file_name);
	virtual ~GLFont();

	void drawString(float x, float y, const char *text) const;
	void beginText(float x1, float y1, float x2, float y2, int valign = 0);
	void drawText(const char *text, int halign = 0);
	void endText();

	inline int getStringWidth(const char *text) const { return bmfont.getStringWidth(text); };
	inline const GLTexture *getTexture(int page) const { return pages[page].texture; };

private:
	void parseAngelCodeFont(const char *file_name);
	void loadFontTextures();

private:
    BMFont bmfont;
	struct
	{
		GLTexture *texture;
	} pages[8];
	struct
	{
		GLRect rect;
	} chars[BMFONT_CHAR_COUNT];

	//
	//draw text
	//
public:
	struct TextLine
	{
		TextLine(const char *_text, int _halign, int _width, int _lines)
		{
			text = _text;
			halign = _halign;
			width = _width;
			lines = _lines;
		}
		std::string text;
		int			halign;
		int			width;
		int 		lines;
	};
	static GLRect				textRect;
	static int					textVAlign;
	static std::list<TextLine>	textLines;
	static int					textWidth;
	static int					textHeight;
};

#endif // GLFONT_H
