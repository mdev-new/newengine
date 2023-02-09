#include "InputManager.hpp"

InputManager::InputManager(std::queue<int> * pressedKeys, std::unordered_set<int> * heldKeys, MouseStatus *status)
: mouseStatus(status),
  pressedKeys(pressedKeys),
  heldKeys(heldKeys)
{
}

//InputManager::