#include "Keyboard.hpp"
#include <iostream>

bool Input::GetKey(Key key){
	bool result = false;
	for (int i = 0; i < MAX_KEY_PRESS; i++) {
		if (keys[i] == (int)key) { result = true; break; }
	}
	return result;
}

bool Input::GetKeyDown(Key key) {
	bool result = false;
	for (int i = 0; i < MAX_KEY_PRESS; i++) {
		if (keyDown[i] == (int)key) { result = true; break; }
	}
	return result;
}

bool Input::GetKeyUp(Key key) {
	bool result = false;
	for (int i = 0; i < MAX_KEY_PRESS; i++) {
		if (keyUp[i] == (int)key) { result = true; break; }
	}
	return result;
}

void Input::KeyPress(int key) {
	if (key == -1) return;
	for (size_t i = 0; i < MAX_KEY_PRESS; i++) {
		if (key == keys[i]) return;
	}
	for (size_t i = 0; i < MAX_KEY_PRESS; i++) {
		if (keys[i] == 0) {
			keys[i] = key;
			for (size_t j = 0; j < MAX_KEY_PRESS; j++) {
				if (keyDown[i] == 0) {
					keyDown[i] = key;
					break;
				}
			}
			break;
		}
	}
}

void Input::KeyUp(int key) {
	if (key == -1) return;
	for (size_t i = 0; i < MAX_KEY_PRESS; i++) {
		if (Input::keys[i] == key) {
			Input::keys[i] = 0;
			for (size_t j = 0; j < MAX_KEY_PRESS; j++) {
				if (keyUp[i] == 0) {
					keyUp[i] = key;
					break;
				}
			}
			break;
		}
	}
}

void Input::ClearKeys() {
	keyDown = (short*)malloc(MAX_KEY_PRESS * sizeof(short));
	keyUp = (short*)malloc(MAX_KEY_PRESS * sizeof(short));
	keys = (short*)malloc(MAX_KEY_PRESS* sizeof(short));
	for (size_t i = 0; i < MAX_KEY_PRESS; i++) {
		keys[i] = 0;
		keyUp[i] = 0;
		keyDown[i] = 0;
	}
}

void Input::ClearKeyPress() {
	for (size_t i = 0; i < MAX_KEY_PRESS; i++) {
		keyUp[i] = 0;
		keyDown[i] = 0;
	}
}