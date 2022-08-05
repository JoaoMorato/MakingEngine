#include "Object.hpp"
#include <time.h>
#include <stdlib.h>
#include "..\Engine.hpp"

Component::Component() {}

void Component::Start() {}

void Component::Update() {}

void Component::Destructor() {}

GameObject::GameObject() : id(time(NULL)) {
    transform = Transform();
}

GameObject::~GameObject() {
    for each (Component* c in components) {
        c->Destructor();
        delete c;
    }
    components.clear();
}

void GameObject::Update() {
    for (size_t i = 0; i < components.size(); i++) {
        components[i]->Update();
    }
}

unsigned long long GameObject::getId() { return this->id; }
/*
template <class T>
T* GameObject::AddComponent() {
    T* comp = new T();
    Component* newComp = &comp;
    newComp->gameObject = this;
    components.push_back(newComp);
    newComp->Start();
    return comp;
}*/

GameObject* InitObj(GameObject* ob) {
    EngineGame::AddObject(ob);
    return ob;
}

//Terminar de fazer
GameObject* InitObj(const char* ob) {
    size_t size = 0;
    while (ob[size]) size++;
    if (ob[size - 2] != 'o' || ob[size - 1] != 'b' || ob[size] != 'j') return NULL;

    GameObject* obj = NULL;
    EngineGame::AddObject(obj);
    return obj;
}

