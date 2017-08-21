#include "ShaderProgram.h"
#include "Utils\Exceptions.h"
#include <fstream>
#include <memory>
#include <windows.h>

ShaderProgram::ShaderProgram() : ProgramID(0), Linked(false)
{
}	

ShaderProgram::ShaderProgram(const char* vertex_filepath, const char* fragment_filepath) :
	Linked(true)
{
	LoadShaders(vertex_filepath, fragment_filepath);
}

ShaderProgram::~ShaderProgram()
{
	if (this->Linked)
	{
		glDeleteProgram(this->ProgramID);
	}
}

void ShaderProgram::Bind()
{
	if (this->Linked)
	{
		glUseProgram(this->ProgramID);
	}
	else
	{
		throw MyException("Bind() on not linked shader program!");
	}
}

void ShaderProgram::Unbind()
{
	if (this->Linked)
	{
		glUseProgram(0);
	}
	else
	{
		throw MyException("Bind() on not linked shader program!");
	}
}

GLuint ShaderProgram::LoadSingleShader(const char* filepath, ShaderType type)
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
	std::ifstream MyFile(filepath, std::ifstream::in);

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
		std::ofstream hey("text.txt");

		/*int len = _MAX_PATH;
		wchar_t pBuf[_MAX_PATH];

		int bytes = GetModuleFileName(NULL, pBuf, len);
		if (bytes == 0)
			return 0;
		else
			MessageBox(NULL, pBuf, L"Check", MB_OK);*/

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

void ShaderProgram::LoadShaders(const char* vertex_filepath, const char* fragment_filepath)
{
	this->ProgramID = glCreateProgram();

	GLuint VertexShader = this->LoadSingleShader(vertex_filepath, ShaderType::Vertex);
	GLuint FragmentShader = this->LoadSingleShader(fragment_filepath, ShaderType::Fragment);

	glAttachShader(ProgramID, VertexShader);
	glAttachShader(ProgramID, FragmentShader);
	glLinkProgram(ProgramID);

	glDeleteShader(VertexShader);
	glDeleteShader(FragmentShader);
}