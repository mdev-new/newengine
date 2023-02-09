#pragma once
#include "global.hpp"

#include "scenes/Scene.hpp"
#include "scripting/ScriptManager.hpp"
#include "input/InputManager.hpp"

// Initialization of this depends on:
// 1. OpenGL context
// 2. loaded GLAD

class Engine {
public:

	Engine(InputManager *inp);
	~Engine();

	void update();
	void render();

	bool shouldQuit;

private:
	//InputSystem input;
	Scene *currentScene;
	InputManager *inputManager;
	ScriptManager scriptManager;
};