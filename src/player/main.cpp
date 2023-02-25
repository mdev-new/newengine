#include <glad/glad.h>
#include <GLFW/glfw3.h>

#ifdef _MSC_VER
	#include <Windows.h>
#endif

#include <cstdio>

#include "engine/Engine.hpp"

#define WINDOW_W 800
#define WINDOW_H 600

std::queue<int> pressedKeys;
std::unordered_set<int> heldKeys;
InputManager::MouseStatus status;

Engine *engine = nullptr;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	engine->setSize({width, height});
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//pressedKeys.
}

#ifdef _MSC_VER
	int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) {
#else
	int main() {
#endif
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(WINDOW_W, WINDOW_H, "NewEngine Game", NULL, NULL);
	if (window == NULL)
	{
		printf("Window cannot be created!\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// engine initializes opengl/glad
	engine = new Engine(new InputManager(&pressedKeys, &heldKeys, &status), {WINDOW_W, WINDOW_H});

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);

	while(!glfwWindowShouldClose(window) && !engine->shouldQuit) {
		glfwSwapBuffers(window);
		engine->update();
		engine->render();
		glfwPollEvents();
	}
	
	glfwTerminate();
}
