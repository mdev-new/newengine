#include "Lexer.hpp"

#include "utility/Files.hpp"

#include <tuple>
#include <stdlib.h>

Lexer::Lexer(const char *filename) {

	std::tie((void*&)this->buffer, this->bufferLen) = read_file(filename, "r");

}

Lexer::~Lexer() {
	free(this->buffer);
}
