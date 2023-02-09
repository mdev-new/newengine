#include "ScriptManager.hpp"
#include "utility/Hashing.hpp"

void ScriptManager::addScript(Script *s) {
	this->scripts[s] = hash_str(s->name);
}

void ScriptManager::update() {
	for (auto const& [script, name] : this->scripts) {
		script->run(10);
	}
}