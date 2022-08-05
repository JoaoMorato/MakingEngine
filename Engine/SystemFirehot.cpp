#include "SystemFirehot.hpp"

V2 SystemEngine::GetResolution() { return V2(width, height); }

void SystemEngine::SetResolution(unsigned int x, unsigned int y) {
    SystemEngine::width = x;
    SystemEngine::height = y;
    //EngineGame::ChangeResolution(x, y);
}