#include "GLFont.h"
#include <stdio.h>
#include <string.h>

GLRect GLFont::textRect;
int GLFont::textVAlign;
std::list<GLFont::TextLine>	GLFont::textLines;
int GLFont::textWidth;
int GLFont::textHeight;

GLFont::GLFont(const char* file_name) : bmfont(file_name)
{
	int n;
	//init
	for (int i = 0; i < 8; i++)
	{
		pages[i].texture = NULL;
	}
	for (int i = 0; i < BMFONT_CHAR_COUNT; i++)
	{
		chars[i].rect.x1 = 0;
		chars[i].rect.y1 = 0;
		chars[i].rect.x2 = 0;
		chars[i].rect.y2 = 0;
	}
	loadFontTextures();
}


GLFont::~GLFont()
{
}


void GLFont::drawString(float x, float y, const char *text) const
{
	float advx_sum = 0;
	float advy_sum = 0;
	int last_page = -1;

	for (const char *pc = text; *pc; pc++)
	{
		int c = *pc;
		int page = bmfont.chars[c].page;
		float w = bmfont.chars[c].width;
		float h = bmfont.chars[c].height;
		float xo = x + bmfont.chars[c].xoffset;
		float yo = y + bmfont.chars[c].yoffset; //+ (common.base - common.lineHeight);

		xo += advx_sum;
		yo += advy_sum;

		if (page != last_page)
		{
			if (last_page > -1)
			{
				pages[last_page].texture->pop();
				glEnd();
			}
			pages[page].texture->push();
			glBegin(GL_QUADS);
			last_page = page;
		}

		//draw char
		glTexCoord2f(chars[c].rect.x1, chars[c].rect.y2); glVertex2f(xo, h+yo);
		glTexCoord2f(chars[c].rect.x1, chars[c].rect.y1); glVertex2f(xo, yo);
		glTexCoord2f(chars[c].rect.x2, chars[c].rect.y1); glVertex2f(xo+w, yo);
		glTexCoord2f(chars[c].rect.x2, chars[c].rect.y2); glVertex2f(xo+w, yo+h);

		//advance
		advx_sum += bmfont.chars[c].xadvance;
		if (*(pc + 1))
			advx_sum += bmfont.chars[c].kernings[(int)*(pc + 1)];
		//new line
		if (c == '\n')
		{
			advx_sum = 0;
			advy_sum += bmfont.common.lineHeight;
		}
	}

	if (last_page > -1)
	{
		pages[last_page].texture->pop();
		glEnd();
	}
}


void GLFont::beginText(float x1, float y1, float x2, float y2, int valign)
{
	textRect.x1 = x1;
	textRect.y1 = y1;
	textRect.x2 = x2;
	textRect.y2 = y2;
	textVAlign = valign;
	textWidth = 0;
	textHeight = 0;
}


void GLFont::drawText(const char *text, int halign)
{
	int width = getStringWidth(text);
	int lines = 1;
	if (textWidth < width)
		textWidth = width;
	for (const char *pc = text; *pc; pc++)
	{
		if (*pc == '\n')
			lines++;
	}
	textLines.push_back(TextLine(text, halign, width, lines));
	textHeight += lines * bmfont.common.lineHeight;
}


void GLFont::endText()
{
	std::list<TextLine>::iterator line;
	float x,y;
	float cx = (textRect.x1 + textRect.x2) / 2;
	float cy = (textRect.y1 + textRect.y2) / 2;
	//valign
	if (textVAlign == -1)
		y = textRect.y1;
	else if (textVAlign == 0)
		y = cy - textHeight / 2;
	else if (textVAlign == 1)
		y = textRect.y2 - textHeight;
	for (line = textLines.begin(); line != textLines.end(); line++)
	{
		//halign
		if (line->halign == -1)
			x = textRect.x1;
		else if (line->halign == 0)
			x = cx - line->width / 2;
		else if (line->halign == 1)
			x = textRect.x2 - line->width;
		//draw
		drawString(x, y, line->text.c_str());
		y += line->lines * bmfont.common.lineHeight;
	}
	textLines.clear();
}

void GLFont::loadFontTextures()
{
	char path[256] = "";
	char tex_name[256];
	char *pch = strrchr(bmfont.fontName, '/');
	int n = pch - bmfont.fontName + 1;
	if (pch)
	{
		strncpy(path, bmfont.fontName, n);
		path[n] = 0;
	}
	//load textures
	for (int i = 0; i < bmfont.common.pages; i++)
	{
		strcpy(tex_name, path);
		strcat(tex_name, bmfont.pages[i].file);
		pages[i].texture = new GLTexture(tex_name);
	}
	//build char rects
	for (int i = 0; i < BMFONT_CHAR_COUNT; i++)
	{
        chars[i].rect.x1 = (float)bmfont.chars[i].x / (float)bmfont.common.scaleW;
        chars[i].rect.y1 = (float)bmfont.chars[i].y / (float)bmfont.common.scaleH;
        chars[i].rect.x2 = (float)(bmfont.chars[i].x + bmfont.chars[i].width) / (float)bmfont.common.scaleW;
        chars[i].rect.y2 = (float)(bmfont.chars[i].y + bmfont.chars[i].height) / (float)bmfont.common.scaleH;
	}
}
