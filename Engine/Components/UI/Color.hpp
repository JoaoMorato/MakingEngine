#pragma once
#ifndef _COLOR_COMPONENT_
#define _COLOR_COMPONENT_

class Color {
public:
	unsigned char R, G, B, A;

	Color();

	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
};

#endif // !_COLOR_COMPONENT_
