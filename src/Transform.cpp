#include "pch.h"
#include "Vector3D.h"
#include "Transform.h"

using namespace MathLib;

Vector3D MathLib::project(Vector3D source, Vector3D target) {
	return target * (source.dot(target) / target.dot(target));
}