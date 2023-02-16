#include "Shader.hpp"
#include <glad/glad.h>
#include "utility/Files.hpp"

#include <stdlib.h>

Shader::Shader(const char *vertexFilename, const char *fragmentFilename) {
	auto [vtBuf, vtLen] = read_file(vertexFilename, "r"); // calls malloc
	auto [frBuf, frLen] = read_file(fragmentFilename, "r"); // calls malloc

	// todo support multiple shaders?

	uint32_t vertex = glCreateShader(GL_VERTEX_SHADER);
	uint32_t fragment = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertex, 1, &vtBuf, NULL);
	glShaderSource(fragment, 1, &frBuf, NULL);

	free(vtBuf);
	free(frBuf);

	glCompileShader(vertex);
	glCompileShader(fragment);

	// todo error check
	this->prgmId = glCreateProgram();
	glAttachShader(this->prgmId, vertex);
	glAttachShader(this->prgmId, fragment);
	glLinkProgram(this->prgmId);
	glValidateProgram(this->prgmId);

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::bind() {
	glUseProgram(this->prgmId);
}

void Shader::unbind() {
	glUseProgram(0);
}
