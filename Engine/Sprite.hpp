#pragma once
#ifndef _SPRITE_COMPONENT_
#define _SPRITE_COMPONENT_

#include <sstream>
#include "Object.hpp"
#include "Vectors.hpp"
#include "Color.hpp"
#include "Shader.hpp"

class Sprite: public Component {
private:
	unsigned int idImage;
	void SetBytes();
	char* spriteReaded;
	unsigned int sizeBytes = 0;
	Shader sh;
	V3 lastScale;
	void ChangeScale();
public:
	void Start();
	void Update();
	std::string sprite = "liquid.jpg";
	bool rootX = false;
	bool rootY = false;
	unsigned int level = 0;
	~Sprite();
};

#endif // !_SPRITE_COMPONENT_