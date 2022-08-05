#pragma once
#ifndef _ENGINE_GAME_
#define _ENGINE_GAME_

#include <GLFW/glfw3.h>
#include "Components\Object.hpp"
#include "Components\Vectors.hpp"

ref class EngineGame {
private:
    static bool initialized = 0;
    static short FPS;
    static unsigned int xResolution;
    static unsigned int yResolution;
    static GLFWwindow* CreateWindow(int, int, const char[]);
public:
    static GLFWwindow* mainWindow = NULL;
    static void Update();
    static void InitializeFireHot(bool debug);
    static void StopFireHot();
    static void SetHz(short);
    static bool IsRunnig();
    static V2 GetResolution();
    static void ChangeResolution(V2 resol, bool fullscreen);
    static GameObject* AddObject(GameObject*);
    static bool DestroyObject(unsigned long long id);
    static void DestroyAllObjects();
};

#endif // !_ENGINE_GAME_