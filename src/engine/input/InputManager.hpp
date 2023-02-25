#pragma once
#include "Global.hpp"

#include <queue>
#include <unordered_set>

class ENGINEAPI InputManager {
public:
	struct MouseStatus {
		short mX;
		short mY;
		char wheel;
		char click;
	};

	short mouseXPos() { return this->mouseStatus->mX; }
	short mouseYPos() { return this->mouseStatus->mY; }

	InputManager(std::queue<int> * pressedKeys, std::unordered_set<int> * heldKeys, MouseStatus *status);

private:
	std::queue<int> *pressedKeys;
	std::unordered_set<int> * heldKeys;
	MouseStatus *mouseStatus;
};
