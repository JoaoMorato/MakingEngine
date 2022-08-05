#pragma once
#ifndef _VECTORS_COMPONENT_
#define _VECTORS_COMPONENT_


class V2 {
public:
	float x;
	float y;

	V2();

	V2(float, float);

	static V2 Zero();
	static V2 One();
	static V2 Up();
	static V2 Right();
	static V2 Front();
	long double Module();

	//Operators
	V2 operator + (V2 num);
	V2 operator - (V2 num);
	V2 operator * (long double num);
	V2 operator * (V2 num);
	V2 operator / (long double num);
	bool operator == (V2 num);
	bool operator != (V2 num);
};

class V3 {
public:
	float x;
	float y;
	float z;

	V3();

	V3(float, float, float);

	static V3 Zero();
	static V3 One();
	static V3 Up();
	static V3 Right();
	static V3 Front();
	long double Module();

	//Operators
	V3 operator + (V3 num);
	V3 operator - (V3 num);
	V3 operator * (long double num);
	V3 operator * (V3 num);
	V3 operator / (long double num);
	bool operator == (V3 num);
	bool operator != (V3 num);
};

#endif // !_VECTORS_COMPONENT_