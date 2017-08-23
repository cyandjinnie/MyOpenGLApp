#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <GL\glew.h>

class Texture
{
public:
	Texture(const char* filename, GLuint size, GLuint texturesize);
	~Texture();

	bool loadFromFile(const char* filename, GLuint size, GLuint texturesize);

	void Bind() const;
	void Unbind() const;

private:
	GLuint TextureID;
	GLuint Size;
	GLuint TextureSize;
};

#endif