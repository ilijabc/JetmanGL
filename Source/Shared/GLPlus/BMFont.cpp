#include "BMFont.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

BMFont::BMFont(const char *file_name)
{
	int n;
	//init
	for (int i = 0; i < 8; i++)
	{
		pages[i].id = i;
		strcpy(pages[i].file, "");
	}
	for (int i = 0; i < BMFONT_CHAR_COUNT; i++)
	{
		chars[i].id = i;
		chars[i].x = 0;
		chars[i].y = 0;
		chars[i].width = 0;
		chars[i].height = 0;
		chars[i].xoffset = 0;
		chars[i].yoffset = 0;
		chars[i].xadvance = 0;
		chars[i].page = 0;
		chars[i].chnl = 0;
		memset(chars[i].kernings, 0, sizeof(int) * BMFONT_CHAR_COUNT);
	}
	//copy file name and replace slash
	strcpy(fontName, file_name);
	n = strlen(fontName);
	for (int i = 0; i < n; i++)
	{
		if (fontName[i] == '\\')
			fontName[i] = '/';
	}
	//parse font
	parseAngelCodeFont(file_name);
}

BMFont::~BMFont()
{
    //dtor
}

int BMFont::getStringWidth(const char *text) const
{
	int advx_sum = 0;
	int c = 0;
	int advx = 0;
	for (const char *pc = text; *pc; pc++)
	{
		c = *pc;
		//advance
		advx += chars[c].xadvance;
		if (*(pc + 1))
			advx += chars[c].kernings[(int)*(pc + 1)];
		//new line
		if (c == '\n')
		{
			if (advx > advx_sum)
				advx_sum = advx;
			advx = 0;
		}
	}
	if (advx > advx_sum)
		advx_sum = advx;
	advx_sum += chars[c].width;
	return advx_sum;
}

void BMFont::parseAngelCodeFont(const char *file_name)
{
	char line[300];
	char *tok, *val, *rval;
	FILE *fp = fopen(file_name, "rt");
	if (fp)
	{
		while (!feof(fp))
		{
			fgets(line, 300, fp);
			//
			//info face="EgyptAxt" size=32 bold=0 italic=0 charset="" unicode=1 stretchH=100 smooth=1 aa=1 padding=0,0,0,0 spacing=1,1 outline=0
			//
			if (strstr(line, "info ") == line)
			{
				tok = strtok(line, " \n");
				while (tok)
				{
					if (strstr(tok, "face=") == tok)
					{
						val = strchr(tok, '"') + 1;
						rval = strchr(val + 1, '"');
						strncpy(info.face, val, rval - val);
						info.face[rval - val] = 0; // not null-terminated under windows
					}
					else if (strstr(tok, "size=") == tok)
					{
						info.size = atoi(strchr(tok, '=') + 1);
					}
					else if (strstr(tok, "bold=") == tok)
					{
						info.bold = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "italic=") == tok)
					{
						info.italic = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "charset=") == tok)
					{
						val = strchr(tok, '"') + 1;
						val[strlen(val) - 1] = 0;
						strcpy(info.charset, val);
					}
					else if (strstr(tok, "unicode=") == tok)
					{
						info.unicode = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "stretchH=") == tok)
					{
						info.stretchH = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "smooth=") == tok)
					{
						info.smooth = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "aa=") == tok)
					{
						info.aa = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "padding=") == tok)
					{
						val = strtok(tok + 8, ",");
						for (int i = 0; i < 4; i++)
						{
							info.padding[i] = atoi(val);
							val = strtok(NULL, ",");
						}
					}
					else if (strstr(tok, "spacing=") == tok)
					{
						val = strtok(tok + 8, ",");
						for (int i = 0; i < 2; i++)
						{
							info.spacing[i] = atoi(val);
							val = strtok(NULL, ",");
						}
					}
					else if (strstr(tok, "outline=") == tok)
					{
						info.outline = atoi(strrchr(tok, '=') + 1);
					}
					tok = strtok(NULL, " \n");
				}
			}
			//
			//common lineHeight=32 base=25 scaleW=256 scaleH=256 pages=1 packed=0 alphaChnl=0 redChnl=4 greenChnl=4 blueChnl=4
			//
			else if (strstr(line, "common ") == line)
			{
				tok = strtok(line, " \n");
				while (tok)
				{
					if (strstr(tok, "lineHeight=") == tok)
					{
						common.lineHeight = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "base=") == tok)
					{
						common.base = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "scaleW=") == tok)
					{
						common.scaleW = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "scaleH=") == tok)
					{
						common.scaleH = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "pages=") == tok)
					{
						common.pages = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "packed=") == tok)
					{
						common.packed = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "alphaChnl=") == tok)
					{
						common.alphaChnl = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "redChnl=") == tok)
					{
						common.redChnl = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "greenChnl=") == tok)
					{
						common.greenChnl = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "blueChnl=") == tok)
					{
						common.blueChnl = atoi(strrchr(tok, '=') + 1);
					}
					tok = strtok(NULL, " \n");
				}
			}
			//
			//page id=0 file="EgyptAxt32_0.png"
			//
			else if (strstr(line, "page ") == line)
			{
				tok = strtok(line, " \n");
				int page_id = -1;
				while (tok)
				{
					if (strstr(tok, "id=") == tok)
					{
						page_id = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "file=") == tok)
					{
						val = strchr(tok, '"') + 1;
						rval = strchr(val + 1, '"');
						strncpy(pages[page_id].file, val, rval - val);
						pages[page_id].file[rval - val] = 0; // not null-terminated under windows
					}
					tok = strtok(NULL, " \n");
				}
			}
			//
			//chars count=89
			//
			else if (strstr(line, "chars ") == line)
			{
				tok = strtok(line, " \n");
				while (tok)
				{
					if (strstr(tok, "count=") == tok)
					{
						chars_count = atoi(strrchr(tok, '=') + 1);
					}
					tok = strtok(NULL, " \n");
				}
			}
			//
			//char id=32   x=248   y=19    width=1     height=1     xoffset=0     yoffset=31    xadvance=8     page=0  chnl=15
			//
			else if (strstr(line, "char ") == line)
			{
				tok = strtok(line, " \n");
				int char_id = 0;
				while (tok)
				{
					if (strstr(tok, "id=") == tok)
					{
						char_id = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "x=") == tok)
					{
						chars[char_id].x = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "y=") == tok)
					{
						chars[char_id].y = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "width=") == tok)
					{
						chars[char_id].width = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "height=") == tok)
					{
						chars[char_id].height = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "xoffset=") == tok)
					{
						chars[char_id].xoffset = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "yoffset=") == tok)
					{
						chars[char_id].yoffset = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "xadvance=") == tok)
					{
						chars[char_id].xadvance = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "page=") == tok)
					{
						chars[char_id].page = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "chnl=") == tok)
					{
						chars[char_id].chnl = atoi(strrchr(tok, '=') + 1);
					}
					tok = strtok(NULL, " \n");
				}
			}
			//
			//kernings count=4410
			//
			else if (strstr(line, "kernings ") == line)
			{
				tok = strtok(line, " \n");
				while (tok)
				{
					if (strstr(tok, "count=") == tok)
					{
						kernings_count = atoi(strrchr(tok, '=') + 1);
					}
					tok = strtok(NULL, " \n");
				}
			}
			//
			//kerning first=48  second=48  amount=-1
			//
			else if (strstr(line, "kerning ") == line)
			{
				tok = strtok(line, " \n");
				int first = 0;
				int second = 0;
				while (tok)
				{
					if (strstr(tok, "first=") == tok)
					{
						first = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "second=") == tok)
					{
						second = atoi(strrchr(tok, '=') + 1);
					}
					else if (strstr(tok, "amount=") == tok)
					{
						chars[first].kernings[second] = atoi(strrchr(tok, '=') + 1);
					}
					tok = strtok(NULL, " \n");
				}
			}
		}
		fclose(fp);
	}
}
