#pragma once

#include "scenes/Scene.hpp"
#include "scripting/ScriptManager.hpp"
#include "input/InputManager.hpp"

#include <utility>

// Initialization of this depends on:
// 1. gl context

class Engine {
public:

	Engine(InputManager *inp, std::pair<int, int> size);
	~Engine();

	void update();
	void render();

	void setSize(std::pair<int, int> size);

	bool shouldQuit;

private:
	Scene *currentScene;
	InputManager *inputManager;
	ScriptManager scriptManager;
};
