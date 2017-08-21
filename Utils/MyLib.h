#ifndef __MY_LIB_H__
#define __MY_LIB_H__

#include "GL\glew.h"
#include "GLFW\glfw3.h"

namespace MyLib
{
	enum ShaderType
	{
		Vertex,
		Fragment,
		Geometry
	};

	GLuint LoadShader(const char* filepath, ShaderType type);
}

#endif