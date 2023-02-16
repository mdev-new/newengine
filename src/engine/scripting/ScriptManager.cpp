#include "ScriptManager.hpp"
#include "utility/Hashing.hpp"

#include "Script.hpp"

#include <memory>

void ScriptManager::addScript(Script *s) {
	this->scripts[std::shared_ptr<Script>(s)] = hash_str(s->name);
}

void ScriptManager::update() {
	for (auto const& [script, name] : this->scripts) {
		script->run(10);
	}
}
