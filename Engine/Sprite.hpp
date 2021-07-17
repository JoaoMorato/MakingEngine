#pragma once
#include "firehot.hpp"
#include "Shader.hpp"
#include <sstream>

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
	void Update();
	void Start();
	std::string sprite = "liquid.jpg";
	bool rootX = false;
	bool rootY = false;
	unsigned int level = 0;
	~Sprite();
};