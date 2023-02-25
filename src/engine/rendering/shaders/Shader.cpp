#include "Shader.hpp"
#include <glad/glad.h>
#include "utility/Files.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include <stdio.h>
#include <stdlib.h>

Shader::Shader(const char *vertexFilename, const char *fragmentFilename) {
	auto [vtBuf, vtLen] = read_file(vertexFilename, "r"); // calls malloc
	auto [frBuf, frLen] = read_file(fragmentFilename, "r"); // calls malloc

	// todo support multiple shaders?

	uint32_t vertex = glCreateShader(GL_VERTEX_SHADER);
	uint32_t fragment = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertex, 1, (char**)&vtBuf, NULL);
	glShaderSource(fragment, 1, (char**)&frBuf, NULL);

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

Shader::~Shader() {
	glDeleteProgram(this->prgmId);
}

void Shader::bind() {
	glUseProgram(this->prgmId);
}

void Shader::unbind() {
	glUseProgram(0);
}

void Shader::setUniform1i(const char *name, int value)
{
	glUniform1i(getUniform(name), value);
}

void Shader::setUniform1f(const char *name, float value)
{
	glUniform1f(getUniform(name), value);
}

void Shader::setUniform2f(const char *name, glm::vec2& vector)
{
	glUniform2f(getUniform(name), vector.x, vector.y);
}

void Shader::setUniform3f(const char *name, glm::vec3& vector)
{
	glUniform3f(getUniform(name), vector.x, vector.y, vector.z);
}

void Shader::setUniformMat4f(const char *name, glm::mat4& matrix)
{
	glUniformMatrix4fv(getUniform(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

// We can cache for improved speed
int Shader::getUniform(const char *name)
{
	uint32_t hash = hash_str(name);
	if(this->uniformCache.contains(hash)) return this->uniformCache[hash];

	int location = glGetUniformLocation(this->prgmId, name);
	if(location == -1)
		printf("Cant find uniform %s!\n", name);

	this->uniformCache[hash] = location;
	return location;
}
