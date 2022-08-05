#define GLEW_STATIC
#include <fstream>
#include <iostream>
#include "GL/glew.h"
#include "Sprite.hpp"


std::string lastFile = "";

void Sprite::SetBytes() {
	if (sprite == "") {
		return;
	}
	std::ifstream file;
	file.open(sprite, std::ios::binary);
	if (file.is_open()) {
		file.seekg(0, file.end);
		sizeBytes = file.tellg();
		file.seekg(0, file.beg);

		spriteReaded = new char[sizeBytes];

		file.read(spriteReaded, sizeBytes);
		file.close();
	}
	
}

void Sprite::Update() {
	printf("Update");
	if (lastFile != sprite) {
		lastFile = sprite;
		SetBytes();
	}
	if (lastScale != gameObject->transform.scale)
		ChangeScale();
	if (sizeBytes == 0) {
		return;
	}
	glBindBuffer(GL_ARRAY_BUFFER, idImage);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
	glDrawArrays(GL_QUADS, 0, 4);
}

void Sprite::ChangeScale() {
	float posis[] = {
		-gameObject->transform.scale.x / 2,  gameObject->transform.scale.y / 2,
		-gameObject->transform.scale.x / 2, -gameObject->transform.scale.y / 2,
		 gameObject->transform.scale.x / 2, -gameObject->transform.scale.y / 2,
		 gameObject->transform.scale.x / 2,  gameObject->transform.scale.y / 2
	};
	lastScale = gameObject->transform.scale;
	//printf("%f %f %f %f", posis[0], posis[1], posis[2], posis[3]);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), posis, GL_STATIC_DRAW);
}

void Sprite::Start(){
	glGenBuffers(1, &idImage);
	glBindBuffer(GL_ARRAY_BUFFER, idImage);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
	ChangeScale();
	lastFile = sprite;
	SetBytes();
	
}

Sprite::~Sprite() {
	glDeleteBuffers(1, &idImage);
	delete[] spriteReaded;
}