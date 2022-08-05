#pragma once
#ifndef _CAMERA_COMPONENT_
#define _CAMERA_COMPONENT_

#include "..\Object.hpp"
#include "..\..\SystemFirehot.hpp"
#include "Color.hpp"

class Camera :public Component {
private:
	//UI face;
public:
	bool skyBox = false;
	Color colorDepth = Color(0.5f, 0.6f, 0.7f, 1);
	float depth;
	void LookAt(V3 targetPosition);
	void Start();
	void Update();
};


#endif // !_CAMERA_COMPONENT_