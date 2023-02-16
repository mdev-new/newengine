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
	std::map<std::shared_ptr<Script>, uint32_t> scripts; // the hash is there for stopping the script using some sort of killScript command, hope future me doesnt get confused again
};
