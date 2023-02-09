#include "Engine.hpp"

#include <glad/glad.h>

#include "rendering/VertexArray.hpp"

VertexArray *va;

Engine::Engine(InputManager *inp)
 : shouldQuit(false),
  inputManager(inp)
{
	va = new VertexArray({-0.25f, -0.25f, 0.1f,
						  0.25f, -0.25f, 0.1f,
						  0.25f, 0.25f, 0.1f,
						  -0.25f, 0.25f, 0.1f
						 }, {0, 1, 2, 2, 3, 0});

	glClearColor(1.0, 1.0, 0.0, 1.0);
}

Engine::~Engine() {
	delete va;
}

void Engine::update() {
	//input.update();
	scriptManager.update();
	if(currentScene != nullptr) currentScene->update();
}

void Engine::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	va->render();

	glFlush();
}