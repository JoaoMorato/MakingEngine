#pragma once
#ifndef _TRANSFORM_COMPONENT_
#define _TRANSFORM_COMPONENT_

#include "./Vectors.hpp"

class Transform {
public:
	V3 position;
	V3 angle;
	V3 scale;

	Transform();
};

#endif // !_TRANSFORM_COMPONENT_
