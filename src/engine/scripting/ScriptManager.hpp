#pragma once

#include "Script.hpp"
#include <vector>
#include <map>
#include <cstdint>
#include <memory>

class ScriptManager {
public:
	void addScript(Script *s);
	void update();
private:
	std::vector<std::shared_ptr<Script>> scripts;
};
