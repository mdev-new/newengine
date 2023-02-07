#pragma once
#include "global.hpp"

#include "entities/Entity.hpp"
#include <vector>
#include <memory>

class Scene {
public:
	void update();
	void render();

private:
	std::vector<std::unique_ptr<Entity>> entities;
	//std::vector<Script> scripts;
};