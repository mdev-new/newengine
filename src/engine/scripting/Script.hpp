#pragma once

#include "lexer/Lexer.hpp"
#include "parser/Parser.hpp"

class Script {
public:
	Script(const char *filename);
	~Script();

	void run(int lines);
	char *name;

private:
	Lexer lexer;
	Parser parser;
};
