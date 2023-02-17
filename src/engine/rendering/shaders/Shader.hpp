#pragma once

#include <stdint.h>
#include <unordered_map>
#include "utility/Hashing.hpp"

#include <glm/glm.hpp>

class Shader {
public:
	Shader(const char *vtFilename, const char *frFilename);
	~Shader();

	void bind();
	void unbind();

	void setUniform1i(const char *name, int value);
	void setUniform1f(const char *name, float value);
	void setUniform2f(const char *name, glm::vec2& vector);
	void setUniform3f(const char *name, glm::vec3& vector);
	void setUniformMat4f(const char *name, glm::mat4& matrix);
	int getUniform(const char *name);

private:
	uint32_t prgmId;
	std::unordered_map<uint32_t, uint32_t, Hasher> uniformCache;
};
