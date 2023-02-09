#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdio>

#include "engine/Engine.hpp"

std::queue<int> pressedKeys;
std::unordered_set<int> heldKeys;
InputManager::MouseStatus status;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//todo pass input onto engine
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "NewEngine Game", NULL, NULL);
	if (window == NULL)
	{
		printf("Window cannot be created!\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// gladloadgl comes from libengine.so
	if(!gladLoadGL()) {
		printf("cannot load gl\n");
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);

	Engine engine(new InputManager(&pressedKeys, &heldKeys, &status));

	while(!glfwWindowShouldClose(window) && !engine.shouldQuit) {
		glfwSwapBuffers(window);
		engine.update();
		engine.render();
		glfwPollEvents();
	}
	
	glfwTerminate();
}