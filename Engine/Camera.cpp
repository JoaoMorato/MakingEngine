#include "Camera.hpp"
#include <GLFW/glfw3.h>

inline long double Mod(long double valor) {
	return valor < 0 ? valor * -1 : valor;
}

void Camera::Start() {
	V2 res = SystemEngine::GetResolution();
	glViewport(0, 0, res.x, res.y);
	glClearColor(colorDepth.R, colorDepth.G, colorDepth.B, colorDepth.A);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Camera::Update() {
	//glfwSwapBuffers();
}

void Camera::LookAt(V3 target) {
	float posX = target.x - gameObject->transform.position.x;
	float posY = target.y - gameObject->transform.position.y;
	float posZ = target.z - gameObject->transform.position.z;
	V3 dir = V3(posX, posY, posZ);
	
	dir = dir / dir.Module();
	V3 Z = dir * -1;
	V3 X = V3::Up() * Z;
	X = X / X.Module();
	V3 Y = Z * X;
	Y = Y / Y.Module();
	float totalXZ = posX * posX + posZ * posZ;
	float resultXZ = sqrt(totalXZ);
	float numX = Mod(gameObject->transform.position.x - target.x);
	if (gameObject->transform.position.z > 0)
		numX *= -1;
	gameObject->transform.angle.y = acos(numX / resultXZ) * 180 / System::Math::PI;
}