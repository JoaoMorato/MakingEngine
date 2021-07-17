#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <time.h>
#include "firehot.hpp"
#include "Commands.hpp"

float newHzTime;

Game* game;

ref class FireHot {
private:
    static bool initialized = 0;
    static short Hz = 30;
    static short actualFps;
    static unsigned int xResolution = 0;
    static unsigned int yResolution = 0;
    static GLFWwindow* CreateWindow(int, int, const char[]);
public:
    static GLFWwindow* mainWindow;
    static void Update(int);
    static void InitializeFireHot(int, int);
    static void StopFireHot();
    static void SetHz(short);
    static bool IsRunnig();
    static V2 GetResolution();
    static void ChangeResolution(int width, int height);
};

void InputCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS)
        Input::KeyPress(key);
    else if (action == GLFW_RELEASE)
        Input::KeyUp(key);

}

void Update() {
    std::cout << "Update Initialized...\n";
    clock_t lastTime = 0;
    clock_t startTime = clock();
    clock_t diff = 0;
    while (!glfwWindowShouldClose(FireHot::mainWindow) && FireHot::IsRunnig()) {
        diff = clock() - startTime - lastTime;
        if (diff >= newHzTime) {
            glClear(GL_COLOR_BUFFER_BIT);
            lastTime = clock() - startTime;
            if (Input::GetKeyDown(Key::ESCAPE)) {
                glfwSetWindowMonitor(FireHot::mainWindow, NULL, 50, 50, 640, 480, 60);
            }
            if (Input::GetKeyDown(Key::RETURN)) {
                FireHot::StopFireHot();
                break;
            }

            //if (Input::GetKeyDown(Key::C))
            glfwSwapBuffers(FireHot::mainWindow);
            FireHot::Update(diff);
            Input::ClearKeyPress();
            glfwPollEvents();
        }
    }
    std::cout << "\nUpdate Finished...\n";
}

inline bool FireHot::IsRunnig() { return initialized; }

void FireHot::Update(int diff) {
    actualFps = 1000 / diff;
    game->CallUpdate();
}

V2 FireHot::GetResolution() {
    return V2(xResolution, yResolution);
}

void FireHot::ChangeResolution(int x, int y) {
    xResolution = x;
    yResolution = y;
    glfwSetWindowMonitor(FireHot::mainWindow, NULL, 10, 10, x, y, 60);
}

GLFWwindow* FireHot::CreateWindow(int widht, int height, const char title[]) {
    std::cout << "Window created...\n";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    xResolution = widht;
    yResolution = height;
    return glfwCreateWindow(widht, height, title, NULL, NULL);
}

void FireHot::SetHz(short value) {
    Hz = value;
    if (Hz <= 0) {
        Hz = 0;
        newHzTime = 1.0f;
        return;
    }
    newHzTime = 1000.0f / Hz;
}

void FireHot::InitializeFireHot(int width, int height) {
    if (initialized)
        return;
    initialized = true;
    Physics::sizeTime = 1;
    mainWindow = CreateWindow(width, height, "Main");
    if (!mainWindow) {
        glfwTerminate();
        exit(77);
    }
    glfwMakeContextCurrent(mainWindow);
    SetHz(30);
}

void FireHot::StopFireHot() {
    initialized = false;
    glfwDestroyWindow(mainWindow);
}

int main() {

}