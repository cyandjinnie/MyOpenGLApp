#ifndef __SHADER_PROGRAM_H__
#define __SHADER_PROGRAM_H__

#include <string>
#include <GL/glew.h>

class ShaderProgram
{
public:
	ShaderProgram();
	ShaderProgram(const ShaderProgram&) = delete;
	ShaderProgram(const char* vertex_filepath, const char* fragment_filepath);
	virtual ~ShaderProgram();

	void Bind();
	void Unbind();

	enum ShaderType
	{
		Vertex,
		Fragment,
		Geometry
	};

	void LoadShaders(const char* vertex_filepath, const char* fragment_filepath);
	GLuint GetID() const;

private:
	bool Linked = false;
	GLuint ProgramID;

	GLuint LoadSingleShader(const char* filepath, ShaderType type);
};

#endif