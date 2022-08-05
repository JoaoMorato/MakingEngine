#pragma once
#ifndef _SHADER_COMPONENT_
#define _SHADER_COMPONENT_

#include "Vectors.hpp"

class Shader {
private:
	unsigned int size;
	V3 *vertices;
public:
	unsigned int GetSize();
	void SetVertices(V3 *_vertices, int lenght);
};
#endif // !_SHADER_COMPONENT_