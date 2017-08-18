#include	"Application.h"
#include	"config.h"

#include	<functional>

// Static functions implementation

void Application::WindowResizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Application::WindowKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		glfwSetWindowShouldClose(window, true);
		break;
	default:

		break;
	}
}

void Application::WindowCursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
	// TODO:
}

// Application member function implementation

Application::Application() : applicationName("Untitled")
{
}

Application::Application(const char* title) : applicationName(title)
{
}

Application::~Application()
{
	glfwTerminate();
}


bool Application::Init()
{
	if (!this->CreateAppWindow(this->applicationName.c_str(), Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT))
	{
		return false;
	}

	glfwSetKeyCallback(this->window, Application::WindowKeyCallback);

	return true;
}

void Application::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

void Application::Run()
{
	while (!glfwWindowShouldClose(this->window))
	{
		///////////////////////////////////////////////////////////////////////////////////////////
		// Render loop
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);




		////////////////////////////////////////////////////////////////////////////////////////////
		// Check and call events, swap buffers
		glfwSwapBuffers(this->window);
		glfwPollEvents();
	}
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

	glViewport(0, 0, width, height);

	glfwSetFramebufferSizeCallback(this->window, Application::WindowResizeCallback);

	return true;
}