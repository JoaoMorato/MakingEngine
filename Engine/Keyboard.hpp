#pragma once
#ifndef _FIRE_KEYBOARD_
#define _FIRE_KEYBOARD_

#include "firehot.hpp"
#include "GLFW/glfw3.h"

#define MAX_KEY_PRESS 10

enum class Key {
	SPACE = 32, APOSTROPHE = 39, COMMA = 44, MINUS, DOT, SLASH,
	A = 65, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R,
	S, T, U, V, W, X, Y, Z, NUM0 = 48, NUM1, NUM2, NUM3, NUM4,
	NUM5, NUM6, NUM7, NUM8, NUM9, SEMICOLON = 59, EQUAL = 61,
	LEFT_BRACKET = 91, BACKSLASH, RIGHT_BRACKET, GRAVE_ACCENT = 96,
	F1 = 290, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15, F16, F17, F18,
	ESCAPE = 256, RETURN, TAB, BACKSPACE, INSERT, DELETE,
	RIGHT_ARROW, LEFT_ARROW, DOWN_ARROW, UP_ARROW,
	PAGE_UP, PAGE_DOWN, HOME, END, CAPSLOCK,
	KEYPAD_0 = 320, KEYPAD_1, KEYPAD_2, KEYPAD_3, KEYPAD_4, KEYPAD_5,
	KEYPAD_6, KEYPAD_7, KEYPAD_8, KEYPAD_9, DECIMAL, DIVIDE, MULTIPLY,
	SUBTRACT, ADD, KEYPAD_ENTER, KEYPAD_EQUAL,
	LEFT_SHIFT = 340, LEFT_CTRL, LEFT_ALT,
	RIGHT_SHIFT = 344, RIGHT_CTRL, RIGHT_ALT, MENU
};

ref class Input {
private:
	static short *keyUp;
	static short *keyDown;
	static short *keys;
public:
static bool GetKey(Key key);
static bool GetKeyDown(Key key);
static bool GetKeyUp(Key key);
static void KeyPress(int);
static void KeyUp(int);
static void ClearKeys();
static void ClearKeyPress();
};



#endif // _FIRE_KEYBOARD_
