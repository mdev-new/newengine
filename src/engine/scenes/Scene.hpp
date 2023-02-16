#pragma once

#include "entities/Entity.hpp"
#include <vector>
#include <memory>

class Scene {
public:
	void update();
	void render();

private:
	std::vector<std::unique_ptr<Entity>> entities;
};
