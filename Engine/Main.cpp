#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <time.h>
#include <stdio.h>

#include "Components\Object.hpp"
#include "Engine.hpp"
#include "Components.hpp"
#include "Components_UI.hpp"
#include "Keyboard.hpp"

#define DEBUG_MODE 0

void Update() {
    printf("Initializing function(Update)...\n");

    GameObject* obj = new GameObject();
    InitObj(obj);
    //Transform* sp = obj->AddComponent<Transform>();
    Sprite* sp = obj->AddComponent<Sprite>();

    while (EngineGame::IsRunnig()) {
        EngineGame::Update();
        if (Input::GetKeyDown(Key::ESCAPE))
            EngineGame::StopFireHot();
    }
    
    printf("\nUpdate Finished...\n");
}

int main() {
    if (!glfwInit()) {
        printf("Error to initialize glfw!");
        return 1;
    }
    EngineGame::InitializeFireHot(DEBUG_MODE);
    if (!DEBUG_MODE) {
        if (glewInit() != GLEW_OK) {
            printf("Error to initialize glew!");
            return 2;
        }
    }

    Update();
    glfwTerminate();
    return 0;
}