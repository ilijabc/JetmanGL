#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include <GL/gl.h>

#define GLPLUS_TEXTURE_EDGE	       	 0x1
#define GLPLUS_TEXTURE_NOMIPMAPS     0x2
#define GLPLUS_TEXTURE_BORDER        0x4
#define GLPLUS_TEXTURE_NEAREST       0x8
#define GLPLUS_TEXTURE_LINEAR        0x10
#define GLPLUS_TEXTURE_COLORKEY      0x20

class GLTexture
{
public:
	GLTexture();
	GLTexture(int w, int h, int flags = 0, float *color = 0);
	GLTexture(const char* file_name, int flags = 0, float *color = 0);
	virtual ~GLTexture();

	void push() const;
	void pop() const;
	void drawImage(float x1, float y1, float x2, float y2, float u1, float v1, float u2, float v2) const;

	//getters
	inline GLuint getTextureId() const { return _textureId; }
	inline int getWidth() const { return _width; }
	inline int getHeight() const { return _height; }
	inline int getBPP() const { return _bpp; }
	inline const char* getFileName() const { return _fileName; }

private:
	GLuint 		_textureId;
	GLsizei 	_width;
	GLsizei 	_height;
	GLint 		_bpp;
	char*		_fileName;
};

#endif // GLTEXTURE_H
