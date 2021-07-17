#pragma once
#ifndef _FIREHOT_
#define _FIREHOT_

#ifndef UNICODE
#define UNICODE
#endif 

#include "Commands.hpp"
#include <vector>

using namespace System;

class GameObject;



long double RadToDegrees(long double radius);
long double DegreesToRad(long double degrees);

class SystemEngine {
private:
	static unsigned int width;
	static unsigned int height;

public:
	static void SetResolution(int width, int height);

	static V2 GetResolution();
};

ref class Physics {
public:
	static int sizeTime = 1;
};

class Abstract {
public:
	virtual void Start() = 0;
	virtual void Update() = 0;
};

class Component: public Abstract {
public:
	long id;
	void Start();
	void Update();

	GameObject* gameObject = NULL;
};

class Transform:public Component {
public:
	V3 position;
	V3 angle;
	V3 scale;

	Transform() {
		position = V3::Zero();
		angle = V3::Zero();
		scale = V3::One();
	}

	void Start();
	void Update();

};

class Color {
public:
	float R;
	float G;
	float B;
	float A;

	Color() {
		this->R = 1;
		this->G = 1;
		this->B = 1;
		this->A = 1;
	}

	Color(float red, float green, float blue, float alpha) {
		this->R = red;
		this->G = green;
		this->B = blue;
		this->A = alpha;
	}
};

class GameObject {
private:
	const long id;
	std::vector<Component*> components;
public:
	Transform* transform = NULL;

	GameObject();

	long getId();

	void Update();

	template <class T>
	T* AddComponent(T*);
};

class Game {
public:
	void CallUpdate();

	GameObject* Instantiate(GameObject* ob);

	GameObject* GetObject(long id);
};

#endif // !_FIREHOT_