#include	"Utils/MyLib.h"
#include	"Utils/Exceptions.h"

#include	<string>
#include	<stdio.h>
#include	<Windows.h>
#include	<memory>
#include	<fstream>

GLuint MyLib::LoadShader(const char* filepath, MyLib::ShaderType type)
{
	GLuint ShaderID;
	GLint Result = GL_FALSE;
	int InfoLogLength;

	switch (type)
	{
	case ShaderType::Fragment:
		ShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		break;
	case ShaderType::Vertex:
		ShaderID = glCreateShader(GL_VERTEX_SHADER);
		break;
	case ShaderType::Geometry:
		ShaderID = glCreateShader(GL_GEOMETRY_SHADER);
		break;
	default:
		// ERROR?
		break;
	}

	std::string ShaderCode;
	std::string Line;
	std::ifstream MyFile(filepath);

	if (MyFile)
	{
		while (MyFile.good())
		{
			getline(MyFile, Line);
			ShaderCode += Line + '\n';
		}
	}
	else
	{
		MessageBox(NULL, L"File not found", L"Error", MB_OK);
		throw MyException("File not found");
	}

	MessageBox(NULL, L"Compiling shader", L"OK", MB_OK);

	char const * SourcePointer = ShaderCode.c_str();

	glShaderSource(ShaderID, 1, &SourcePointer, 0);
	glCompileShader(ShaderID);

	glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(ShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);

	if (InfoLogLength > 0)
	{
		std::auto_ptr<GLchar> cResult(new GLchar[InfoLogLength + 1]);
		glGetShaderInfoLog(ShaderID, InfoLogLength, NULL, cResult.get());

		FILE* dumpFile = fopen("../dump.txt", "w");
		fwrite(cResult.get(), sizeof(char), InfoLogLength, dumpFile);
		fclose(dumpFile);

		switch (type)
		{
		case ShaderType::Vertex:
			MessageBox(NULL, L"Compiling error: Vertex", L"Error", MB_OK);
			break;
		case ShaderType::Fragment:
			MessageBox(NULL, L"Compiling error: Fragment", L"Error", MB_OK);
			break;
		case ShaderType::Geometry:
			MessageBox(NULL, L"Compiling error: Geometry", L"Error", MB_OK);
		}

		throw MyException("COMPILING ERROR");
	}

	MessageBox(NULL, L"Compiled successfully", L"OK", MB_OK);

	return ShaderID;
}