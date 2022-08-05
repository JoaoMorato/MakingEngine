#pragma once
#ifndef _SYSTEM_FIREHOT_
#define _SYSTEM_FIREHOT_

#include "Components\Vectors.hpp"

ref class SystemEngine {
private:
	static unsigned int width = 0;
	static unsigned int height = 0;

public:
	static void SetResolution(unsigned int width, unsigned int height);
	static V2 GetResolution();
};

#endif // !_SYSTEM_FIREHOT_
