#include "ScriptManager.hpp"
#include "utility/Hashing.hpp"

#include "Script.hpp"

#include <memory>

void ScriptManager::addScript(Script *s) {
	this->scripts.push_back(std::shared_ptr<Script>(s));
}

void ScriptManager::update() {
	for (auto const& script : this->scripts) {
		script->run(10);
	}
}
