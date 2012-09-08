#include "GLTexture.h"
#include "stb_image.h"
#include <GL/glu.h>
#include <GL/glext.h>
#include <string.h>
#include <stdlib.h>


GLTexture::GLTexture()
{
    _textureId = 0;
    _width = 0;
    _height = 0;
    _bpp = 0;
	_fileName = NULL;
}

GLTexture::GLTexture(int w, int h, int flags, float *color)
{
    glGenTextures(1, &_textureId);
    glBindTexture(GL_TEXTURE_2D, _textureId);
    glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    if (flags & GLPLUS_TEXTURE_EDGE)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h,
                 0, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, 0);
    _width = w;
    _height = h;
    _bpp = 4;
	_fileName = NULL;
}

GLTexture::GLTexture(const char *file_name, int flags, float *color)
{
	int img_width = 0;
	int img_height = 0;
	int img_bpp = 0;
    unsigned char* img_data = stbi_load(file_name, &img_width, &img_height, &img_bpp, 4);

    if (img_data)
    {
        GLenum type = (img_bpp == 4) ? GL_RGBA : GL_RGB;
        _width = img_width;
        _height = img_height;
        _bpp = img_bpp;
		_fileName = (char*)malloc(strlen(file_name) + 1);
		strcpy(_fileName, file_name);

		//only 32bit images (for now)
		type = GL_RGBA;
		_bpp = 4;

        glGenTextures(1, &_textureId);
        glBindTexture(GL_TEXTURE_2D, _textureId);

        //edge
        if (flags & GLPLUS_TEXTURE_EDGE)
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        }
        else if (flags & GLPLUS_TEXTURE_BORDER)
        {
            float c[4] = {1,1,1,1};
            glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, c);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        }

        //filter
        if (flags & GLPLUS_TEXTURE_NEAREST)
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        }
        else if (flags & GLPLUS_TEXTURE_LINEAR)
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        }
        else
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        }

        //color key
		#if 0
        if (flags & GLPLUS_TEXTURE_COLORKEY)
        {
            img->replacePixels(ckey, Color::Transparent);
        }
		#endif

        //mipmaps
        if (flags & GLPLUS_TEXTURE_NOMIPMAPS)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, _bpp, _width, _height, 0,
                         type, GL_UNSIGNED_BYTE, img_data);
        }
        else
        {
            gluBuild2DMipmaps(GL_TEXTURE_2D, _bpp, _width, _height,
                              type, GL_UNSIGNED_BYTE, img_data);
        }
    }
	else
	{
		_textureId = 0;
		_width = 0;
		_height = 0;
		_bpp = 0;
		_fileName = NULL;
        printf("%s:%d: error: Loading texture '%s'\n", __FILE__, __LINE__, file_name);
	}
}

GLTexture::~GLTexture()
{
    if (_textureId)
		glDeleteTextures(1, &_textureId);
	if (_fileName)
		free(_fileName);
}

void GLTexture::push() const
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
}

void GLTexture::pop() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}

void GLTexture::drawImage(float x1, float y1, float x2, float y2, float u1, float v1, float u2, float v2) const
{
    GLfloat vert[12] = {
        x1,y1 , x2,y1 , x2,y2 ,
        x2,y2 , x1,y2 , x1,y1 };
    GLfloat texc[12] = {
        u1,v2 , u2,v2 , u2,v1 ,
        u2,v1 , u1,v1 , u1,v2 };

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, vert);
	glTexCoordPointer(2, GL_FLOAT, 0, texc);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_TEXTURE_2D);
}


