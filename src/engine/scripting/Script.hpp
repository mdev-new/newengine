#pragma once
#include "global.hpp"

class Script {
public:
	Script(const char *filename);
	void run(int lines);
	char *name;
};