#include "Color.hpp"

Color::Color() {
	R = G = B = A = 255;
}

Color::Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
	R = red, G = green;
	B = blue, A = alpha;
}