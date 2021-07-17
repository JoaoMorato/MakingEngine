#pragma once
#include "firehot.hpp"
#include "Commands.hpp"

class Camera :public Component {
private:
	//UI face;
public:
	bool skyBox = false;
	Color colorDepth = Color(0.5, 0.6, 0.7, 1);
	float depth;
	void LookAt(V3 targetPosition);
	void Start();
	void Update();
};