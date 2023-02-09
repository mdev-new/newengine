#pragma once
#include "global.hpp"

#include "Script.hpp"
#include <vector>
#include <map>
#include <cstdint>

class ScriptManager {
public:
	void addScript(Script *s);
	void update();
private:
	std::map<Script*, uint32_t> scripts; // the hash is there for stopping the script using some sort of killScript command, hope future me doesnt get confused again
};