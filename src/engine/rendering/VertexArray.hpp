#pragma once
#include "global.hpp"

#include <cstdint>
#include <vector>

constexpr int VERTEX_ATTRIB = 0;
constexpr int TCOORD_ATTRIB = 1;

class VertexArray
{
public:
	VertexArray(std::vector<float> vertices, std::vector<char> indices, std::vector<float> texCoords = {});
	void bind();
	void unbind();
	void render();

private:
	uint32_t vao, vbo, ibo, tbo;
	int count;
};