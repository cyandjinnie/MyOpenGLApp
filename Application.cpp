#include "Application.h"
#include "Utils/config.h"
#include <functional>
#include "Shaders/ShaderProgram.h"
#include "Input/InputControl.h"

#include "Player/Player.h"
#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform.hpp>

// Static functions implementation

void Application::WindowResizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Application::WindowKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (action)
	{
	case GLFW_PRESS:
		InputControl::GetInstance()->DispatchOnKeyPressed(
			EventKeyboard( (EventKeyboard::KeyCodes)key )
		);
		break;
	case GLFW_RELEASE:
		InputControl::GetInstance()->DispatchOnKeyReleased(
			EventKeyboard( (EventKeyboard::KeyCodes)key )
		);
		break;
	default:
		// TODO:

		break;
	}
}

void Application::WindowCursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
	/*int width, height;

	glfwGetWindowSize(
		Application::GetInstance()->GetWindowIndex(),
		&width,
		&height
	);

	glfwSetCursorPos(Application::GetInstance()->GetWindowIndex(), width / 2, height / 2);

	float HorizontalAngle = M_PI;
	float VerticalAngle = 0;

	float speed = 3.0f;
	float mousespeed = 0.005f;

	HorizontalAngle += mousespeed * float(width / 2 - xpos);
	VerticalAngle += mousespeed * float(height / 2 - ypos);

	glm::vec3 direction = glm::vec3(
		cos(VerticalAngle) * sin(HorizontalAngle),
		sin(VerticalAngle),
		cos(VerticalAngle) * cos(HorizontalAngle)
	);*/
}

Application* Application::GetInstance()
{
	static Application instance;
	return &instance;
}

// Member functions

GLFWwindow* Application::GetWindowIndex() const
{
	return this->window;
}

void Application::SetWindowAspectRatio(float windowaspectratio)
{
	this->WindowAspectRatio = windowaspectratio;
}

float Application::GetWindowAspectRatio() const
{
	return this->WindowAspectRatio;
}

Application::Application()
{
}

Application::~Application()
{
	glfwTerminate();
}

bool Application::Init(const char* applicationname)
{
	if (!this->CreateAppWindow(applicationname, Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT))
	{
		return false;
	}

	glfwSetKeyCallback(
		this->window, 
		Application::WindowKeyCallback
	);

	glfwSetFramebufferSizeCallback(
		this->window,
		Application::WindowResizeCallback
	);

	glfwSetWindowAspectRatio(this->window, 16, 9);

	return true;
}

bool Application::CreateAppWindow(const char* title, u_int width, u_int height)
{
	if (!glfwInit())
	{
		MessageBox(NULL, L"glfwInit failed", L"Error", MB_OK);
		return false;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x anti-aliasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Мы не хотим старый OpenGL

	this->window = glfwCreateWindow(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, title, NULL, NULL);

	if (NULL == this->window)
	{
		MessageBox(NULL, L"glfwCreateWindow failed", L"Error", MB_OK);
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(this->window);


	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		MessageBox(NULL, L"glewInit failed", L"Error", MB_OK);
		return false;
	}

	return true;
}

void Application::Run()
{



	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	float vertices[] =
	{
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
	     1.0f,-1.0f,-1.0f,
	 	 1.0f, 1.0f,-1.0f,
	 	 1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
	 	 1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		 1.0f,-1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		 1.0f,-1.0f,-1.0f,
		 1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f,-1.0f,
		 1.0f, 1.0f, 1.0f,
		 1.0f,-1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		 1.0f,-1.0f, 1.0f
	};

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	ShaderProgram Program("Shaders/shader1.vert", "Shaders/shader1.frag");

	int MVPLocationID = glGetUniformLocation(Program.GetID(), "MVP");

	glm::mat4 Projection = glm::perspective(
		glm::radians(45.0f),
		16.0f / 9.0f,
		0.1f,
		100.0f
	);

	glm::mat4 View = glm::lookAt(
		glm::vec3(4, 3, -3), // Camera is at (4,3,-3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	glm::mat4 Model = glm::mat4(1.0f);
	glm::mat4 MVP = Projection * View * Model;

	int vertexColorLocation = glGetUniformLocation(Program.GetID(), "ourColor");

	float timeValue;
	float greenValue;

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	while (!glfwWindowShouldClose(this->window))
	{
		///////////////////////////////////////////////////////////////////////////////////////////
		// Render loop

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		timeValue = glfwGetTime();
		greenValue = (sin(timeValue * 3.0f) / 5.0f) + 0.5f;

		Program.Bind();

		glUniform4f(vertexColorLocation, 0.0f, greenValue, greenValue, 1.0f);
		glUniformMatrix4fv(MVPLocationID, 1, GL_FALSE, &MVP[0][0]);

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, VAO);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		glDrawArrays(GL_TRIANGLES, 0, 6*6);

		glDisableVertexAttribArray(0);

		////////////////////////////////////////////////////////////////////////////////////////////
		// Check and call events, swap buffers

		glfwSwapBuffers(this->window);
		glfwPollEvents();
	}
}