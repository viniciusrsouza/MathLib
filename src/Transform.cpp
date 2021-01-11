#include "pch.h"
#include "Vector3D.h"
#include "Transform.h"

using namespace MathLib;

Vector3D MathLib::project(Vector3D source, Vector3D target) {
	return target * (source.dot(target) / target.dot(target));
}

float** MathLib::transpose_3x3(float** matrix) {
	return new float* [] {
		new float[] { matrix[0][0], matrix[1][0], matrix[2][0] },
		new float[] { matrix[0][1], matrix[1][1], matrix[2][1] },
		new float[] { matrix[0][2], matrix[1][2], matrix[2][2] }
	};
}