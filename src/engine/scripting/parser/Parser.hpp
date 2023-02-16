#pragma once

#include "scripting/lexer/Lexer.hpp"
#include <memory>

class Parser {
public:
	Parser(Lexer *lexer);

private:
	std::unique_ptr<Lexer> lexer;
};
