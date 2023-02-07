#include "VertexArray.hpp"

#include <glad/glad.h>

VertexArray::VertexArray(std::vector<float> vertices, std::vector<char> indices, std::vector<float> texCoords)
	: vao(0), vbo(0), tbo(0), ibo(0)
{
	count = indices.size();

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(VERTEX_ATTRIB, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(VERTEX_ATTRIB);

	if(!texCoords.empty()) {
		glGenBuffers(1, &tbo);
		glBindBuffer(GL_ARRAY_BUFFER, tbo);
		glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(float), &texCoords.front(), GL_STATIC_DRAW);
		glVertexAttribPointer(TCOORD_ATTRIB, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(TCOORD_ATTRIB);
	}

	if(count) {
		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(char), &indices.front(), GL_STATIC_DRAW);
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void VertexArray::bind()
{
	glBindVertexArray(vao);
	if(ibo > 0)
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
}

void VertexArray::unbind()
{
	if(ibo > 0)
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void VertexArray::render()
{
	bind();
	if(ibo > 0) glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_BYTE, nullptr);
	else glDrawArrays(GL_TRIANGLES, 0, count);
	unbind();
}