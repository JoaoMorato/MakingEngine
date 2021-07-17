#pragma once
#include <iostream>
#include "firehot.hpp"
#include "Commands.hpp"

//GameObject

GameObject::GameObject() :id(clock()) {
    transform = AddComponent(new Transform());
}

void GameObject::Update() {
    for (size_t i = 0; i < components.size(); i++) {
        components[i]->Update();
    }
}

inline long GameObject::getId() { return this->id; }

template <class T>
T* GameObject::AddComponent(T* comp) {
    components.push_back(comp);
    comp->id = &this->id;
    comp->gameObject = &this;
    comp->Start();
    return comp;
}

//Component
void Component::Start(){}
void Component::Update(){}
///inline GameObject* Component::gameObject() { return game->GetObject(this->id); }

//Transform

void Transform::Start() {}

void Transform::Update() {}

long double RadToDegrees(long double radius) {
    return radius * 180 / Math::PI;
}

long double DegreesToRad(long double degrees) {
    return degrees * Math::PI / 180;
}

//SystemEngine
V2 SystemEngine::GetResolution() { return V2(width, height); }
void SystemEngine::SetResolution(int x, int y) { 
    width = x;
    height = y;
}

std::vector<GameObject*> obs;

//Game
GameObject* Game::GetObject(long id) {
    for each (GameObject * g in obs) {
        if (g->getId() == id)
            return g;
    }
}

GameObject* Game::Instantiate(GameObject* ob) {
    obs.push_back(ob);
    return obs.back();
}

void Game::CallUpdate() {
    for each (GameObject * o in obs) {
        o->Update();
    }
}
