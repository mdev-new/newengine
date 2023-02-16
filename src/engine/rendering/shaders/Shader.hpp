#pragma once

#include <stdint.h>

class Shader {
public:
	Shader(const char *vtFilename, const char *frFilename);

	void bind();
	void unbind();

private:
	uint32_t prgmId;
};
