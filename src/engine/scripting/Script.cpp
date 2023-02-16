#include "Script.hpp"

#include <string.h>
#include <stdlib.h>

Script::Script(const char *fname)
	:name(strdup(fname)),
	 lexer(fname),
	 parser(&this->lexer)
{

}

Script::~Script() {
	free(this->name);
}

void Script::run(int lines) {}
