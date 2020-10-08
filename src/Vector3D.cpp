//
// Created by viniciusrsouza on 20/05/2020.
//
#include "pch.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include "Vector3D.h"

using namespace MathLib;

Vector3D::Vector3D() : x(0), y(0), z(0) {}

Vector3D::Vector3D(float nX, float nY, float nZ) : x(nX), z(nZ), y(nY) {}

Vector3D& Vector3D::operator=(const Vector3D& u) {
    x = u.x;
    y = u.y;
    z = u.z;
    return *this;
}

bool Vector3D::operator==(const Vector3D& u) const {
    return x == u.x && y == u.y && z == u.z;
}

Vector3D Vector3D::operator-() const {
    return Vector3D(-x, -y, -z);
}

void Vector3D::zero() {
    x = y = z = 0.0f;
}

Vector3D Vector3D::operator-(const Vector3D& u) const {
    return Vector3D(x - u.x, y - u.y, z - u.z);
}

Vector3D Vector3D::operator+(const Vector3D& u) const {
    return Vector3D(x + u.x, y + u.y, z + u.z);
}

Vector3D Vector3D::operator*(const float c) const {
    return Vector3D(c * x, c * y, c * z);
}

Vector3D Vector3D::operator/(const float c) const {
    return Vector3D(x / c, y / c, z / c);
}

Vector3D Vector3D::operator-=(const Vector3D& u) {
    x -= u.x;
    y -= u.y;
    z -= u.z;
    return *this;
}

Vector3D Vector3D::operator+=(const Vector3D& u) {
    x += u.x;
    y += u.y;
    z += u.z;
    return *this;
}

Vector3D Vector3D::operator*=(float c) {
    x *= c;
    y *= c;
    z *= c;
    return *this;
}

Vector3D Vector3D::operator/=(float c) {
    x /= c;
    y /= c;
    z /= c;
    return *this;
}

float Vector3D::dot(const Vector3D& u) const {
    return x * u.x + y * u.y + z * u.z;
}

Vector3D Vector3D::cross(const Vector3D& u) const {
    return Vector3D(
        y * u.z - z * u.y,
        z * u.x - x * u.z,
        x * u.y - y * u.x
    );
}

float Vector3D::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vector3D Vector3D::normalize() const {
    float m = std::sqrt(x * x + y * y + z * z);
    if (m != 0) {
        return Vector3D(x / m, y / m, z / m);
    }
    return Vector3D();
}

float Vector3D::distance(const Vector3D& u) const {
    Vector3D d = Vector3D(x - u.x, y - u.y, z - u.z);
    return std::sqrt(d.x * d.x + d.y * d.y + d.z * d.z);
}

std::string Vector3D::str() const {
    std::stringstream sstm;
    sstm << "(" << x << ", " << y << ", " << z << ")";
    return sstm.str();
}

inline Vector3D operator*(float c, Vector3D& u) {
    return u * c;
}

inline std::ostream& operator<<(std::ostream& Str, Vector3D& v) {
    std::cout << "printando";
    Str << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}