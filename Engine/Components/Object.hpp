#pragma once
#ifndef _GAME_OBJECT_
#define _GAME_OBJECT_

#include <vector>
#include "Transform.hpp"
#include <type_traits>
#include <stdio.h>

class GameObject;

class Abstract {
public:
	virtual void Start() = 0;
	virtual void Update() = 0;
};

class Component : public Abstract {
public:
	GameObject* gameObject;

	void Start();
	void Update();
	void Destructor();

	Component();
};

class GameObject {
private:
	const unsigned long long id;
	std::vector<Component*> components;
public:
	Transform transform;

	GameObject();
	~GameObject();

	unsigned long long getId();

	void Update();

	template <class T>
	T* AddComponent() {
		T* comp = new T();
		if (!std::is_base_of<Component, T>::value) {
			printf("ERROR TYPEID");
			delete comp;
			return nullptr;
		}
		comp->gameObject = this;
		components.push_back(comp);
		comp->Start();
		return comp;
	}
};

GameObject* InitObj(GameObject* ob);
GameObject* InitObj(const char* ob);

#endif // !_GAME_OBJECT_
