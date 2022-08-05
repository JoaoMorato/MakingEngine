#include "Vectors.hpp"
#include <math.h>

//Vector 2
V2::V2() {
    this->x = 0;
    this->y = 0;
}

V2::V2(float x, float y) {
    this->x = x;
    this->y = y;
}

V2 V2::operator + (V2 num) {
    return V2(num.x + x, num.y + y);
}

V2 V2::operator - (V2 num) {
    return V2(num.x - x, num.y - y);
}

V2 V2::operator * (long double num) {
    return V2(x * num, num * y);
}

V2 V2::operator * (V2 num) {
    return V2(x * num.x, num.y * y);
}

V2 V2::operator / (long double num) {
    return V2(x / num, y / num);
}

bool V2::operator == (V2 num) {
    if (x == num.x && y == num.y)
        return true;
    return false;
}

bool V2::operator != (V2 num) {
    return !(num == V2(x, y));
}

V2 V2::Zero() {
    return V2(0, 0);
}

V2 V2::One() {
    return V2(1, 1);
}

V2 V2::Up() {
    return V2(0, 1);
}

V2 V2::Right() {
    return V2(1, 0);
}

V2 V2::Front() {
    return V2(0, 0);
}

long double V2::Module() {
    return sqrt(x * x + y * y);
}

//Vector 3
V3::V3() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

V3::V3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

V3 V3::operator + (V3 num) {
    return V3(num.x + x, num.y + y, num.z + z);
}

V3 V3::operator - (V3 num) {
    return V3(num.x - x, num.y - y, num.z - z);
}

V3 V3::operator * (long double num) {
    return V3(x * num, num * y, num * z);
}

V3 V3::operator * (V3 num) {
    return V3(x * num.x, num.y * y, num.z * z);
}

V3 V3::operator / (long double num) {
    return V3(x / num, y / num, z / num);
}

bool V3::operator == (V3 num) {
    if (x == num.x && y == num.y && z == num.z)
        return true;
    return false;
}

bool V3::operator != (V3 num) {
    return !(num == V3(x, y, z));
}

V3 V3::Zero() {
    return V3(0, 0, 0);
}

V3 V3::One() {
    return V3(1, 1, 1);
}

V3 V3::Up() {
    return V3(0, 1, 0);
}

V3 V3::Right() {
    return V3(1, 0, 0);
}

V3 V3::Front() {
    return V3(0, 0, 1);
}

long double V3::Module() {
    return sqrt(x * x + y * y + z * z);
}