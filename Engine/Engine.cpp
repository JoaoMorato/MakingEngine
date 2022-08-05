#include <time.h>
#include <vector>
#include "Engine.hpp"
#include "Keyboard.hpp"
#include "Physics.hpp"

float newHzTime;
clock_t lastClock = 0;

std::vector<GameObject*> obs;

bool EngineGame::IsRunnig() { return initialized; }

void EngineGame::Update() {
    if (!initialized) return;
    
    clock_t diff = clock() - lastClock;

    if (diff >= newHzTime) {

        glClear(GL_COLOR_BUFFER_BIT);

        lastClock = clock();
        for each (GameObject * go in obs) {
            go->Update();
        }
        if(mainWindow)
            glfwSwapBuffers(EngineGame::mainWindow);

        Input::ClearKeys();
    }
    glfwPollEvents();
    if (!mainWindow) return;
    if (glfwWindowShouldClose(mainWindow)) {
        StopFireHot();
    }
}

GameObject* EngineGame::AddObject(GameObject* ob) {
    if (!ob) return NULL;
    obs.push_back(ob);
    return ob;
}

bool EngineGame::DestroyObject(unsigned long long id) {
    size_t fim = obs.size() - 1;
    size_t meio = fim / 2;
    size_t ini = 0;
    while (1) {
        if (obs[meio]->getId() == id) {
            delete obs[meio];
            obs.erase((obs.begin()) + meio);
            return 1;
        }
        if (meio == ini) break;
        if (obs[meio]->getId() < id) ini = meio;
        else fim = meio;
        meio = (fim - ini) / 2;
        meio += ini;
    }
    return 0;
}

void EngineGame::DestroyAllObjects() {
    for each (GameObject* go in obs) {
        delete go;
    }
}

V2 EngineGame::GetResolution() {
    return V2(xResolution, yResolution);
}

void EngineGame::ChangeResolution(V2 resol, bool fullscreen) {
    xResolution = (int)resol.x;
    yResolution = (int)resol.y;
    int count;
    GLFWmonitor** mon = glfwGetMonitors(&count);
    if(!count || !fullscreen)
        glfwSetWindowMonitor(EngineGame::mainWindow, NULL, 10, 10, resol.x, resol.y, GLFW_DONT_CARE);
    else
        glfwSetWindowMonitor(EngineGame::mainWindow, mon[0], 10, 10, resol.x, resol.y, GLFW_DONT_CARE);
}

GLFWwindow* EngineGame::CreateWindow(int widht, int height, const char title[]) {
    printf("Creating window...\n");
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    xResolution = widht;
    yResolution = height;
    return glfwCreateWindow(widht, height, title, NULL, NULL);
}

void EngineGame::SetHz(short value) {
    FPS = value;
    if (FPS <= 0) {
        FPS = 0;
        newHzTime = 1.0f;
        return;
    }
    newHzTime = 1000.0f / FPS;
}

void InputCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS)
        Input::KeyPress(key);
    else if (action == GLFW_RELEASE)
        Input::KeyUp(key);
}

void EngineGame::InitializeFireHot(bool debug) {
    if (initialized)
        return;
    Physics::sizeTime = 1;
    if (!debug) {
        mainWindow = CreateWindow(800, 450, "Engine");
        if (!mainWindow) {
            glfwTerminate();
            exit(77);
        }
        
        glfwMakeContextCurrent(mainWindow);
        glfwSetKeyCallback(mainWindow, InputCallback);
    }
    initialized = true;
    SetHz(30);
}

void EngineGame::StopFireHot() {
    DestroyAllObjects();
    initialized = false;
    if(mainWindow)
        glfwDestroyWindow(mainWindow);
}
