#pragma once
#include "firehot.hpp"

class Shader {
private:
	unsigned int size;
	V3 *vertices;
public:
	unsigned int GetSize();
	void SetVertices(V3 *_vertices, int lenght);
};