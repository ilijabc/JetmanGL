#ifndef BMFONT_H
#define BMFONT_H

#define BMFONT_CHAR_COUNT 256

class BMFont
{
public:
    BMFont(const char *file_name);
    virtual ~BMFont();
    int getStringWidth(const char *text) const;

private:
    void parseAngelCodeFont(const char *file_name);

public:
	char fontName[256];
	struct
	{
		char 	face[256];
		int 	size;
		int		bold;
		int 	italic;
		char	charset[256];
		int		unicode;
		int		stretchH;
		int		smooth;
		int		aa;
		int		padding[4];
		int		spacing[2];
		int		outline;
	} info;
	struct
	{
		int		lineHeight;
		int		base;
		int		scaleW;
		int		scaleH;
		int		pages;
		int		packed;
		int		alphaChnl;
		int		redChnl;
		int		greenChnl;
		int		blueChnl;
	} common;
	struct
	{
		int		id;
		char	file[256];
	} pages[8];
	struct
	{
		int		id;
		int		x;
		int		y;
		int		width;
		int		height;
		int		xoffset;
		int		yoffset;
		int		xadvance;
		int		page;
		int		chnl;
		int		kernings[BMFONT_CHAR_COUNT];
	} chars[BMFONT_CHAR_COUNT];
	int chars_count;
	int kernings_count;
};

#endif // BMFONT_H
