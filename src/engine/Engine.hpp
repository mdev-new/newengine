#pragma once
#include "global.hpp"

#include "scenes/Scene.hpp"

class Engine {
public:

	Engine();
	//~Engine();

	void update();
	void render();

	bool shouldQuit();

private:
	//InputSystem input;
	Scene *currentScene;
};