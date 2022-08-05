#include "Keyboard.hpp"
#include <iostream>

#include <vector>

std::vector<short> keys;
std::vector<short> keyDown;
std::vector<short> keyUp;


bool Input::GetKey(Key key){
	for each (short k in keys) {
		if (k == (int)key) {
			return true;
		}
	}
	return false;
}

bool Input::GetKeyDown(Key key) {
	for each (short k in keyDown) {
		if (k == (int)key) {
			return true;
		}
	}
	return false;
}

bool Input::GetKeyUp(Key key) {
	for each (short k in keyUp) {
		if (k == (int)key) {
			return true;
		}
	}
	return false;
}

void Input::KeyPress(int key) {
	if (key == -1) return;
	if (key >= 'a' && key <= 'z') {
		key = 'A' + (key - 'a');
	}
	for (size_t i = 0; i < MAX_KEY_PRESS; i++) {
		if (GetKey((Key)key)) return;
	}
	keys.push_back((short)key);
	keyDown.push_back((short)key);
}

void Input::KeyUp(int key) {
	if (key == -1) return;
	if (key >= 'a' && key <= 'z') {
		key = 'A' + (key - 'a');
	}
	for (size_t i = 0; i < keys.size(); i++) {
		if (keys[i] == (short)key) {
			keys.erase(keys.begin() + i);
			keyUp.push_back((short)key);
		}
	}
}

void Input::ClearKeys() {
	keyUp.clear();
	keyDown.clear();
}