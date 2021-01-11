#pragma once
#ifdef MATHLIB_EXPORTS
#define TRANSFORM_API __declspec(dllexport)
#else
#define TRANSFORM_API __declspec(dllimport)
#endif

#include <math.h>
#include "Vector3D.h"

namespace MathLib {
	/**
	* projeta o vetor [source] no vetor [target]
	*/
	TRANSFORM_API Vector3D project(Vector3D source, Vector3D target);
	TRANSFORM_API float** transpose_3x3(float** matrix);
}