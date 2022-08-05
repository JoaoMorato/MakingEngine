#include "Shader.hpp"
#include <iostream>

void Shader::SetVertices(V3 *_vertices, int lenght) {
	size = lenght;
	std::cout << "Size: " << size;
	vertices = new V3[size];
	vertices = _vertices;
	return;
}

unsigned int Shader::GetSize() {
	return size;
}