#pragma once

class Lexer {
public:
	Lexer(const char *filename);
	~Lexer();

private:
	int position;

	struct {
		char *buffer;
		int bufferLen;
	};
};
