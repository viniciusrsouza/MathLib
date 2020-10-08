#pragma once

#ifdef MATHLIB_EXPORTS
#define VECTOR_3D_API __declspec(dllexport)
#else
#define VECTOR_3D_API __declspec(dllimport)
#endif

#include <iostream>

namespace MathLib {
    class VECTOR_3D_API Vector3D {
    public:
        float x, y, z;

        /**
         * Default constructor, initialize x, y and z with 0.
         */
        Vector3D();

        /**
         * Copy constructor, load the values of x, y and z from
         * the vector u to the new instance.
         * @param u: source vector
         */
        Vector3D(const Vector3D& u) = default;

        /**
         * Explicit constructor, initialize the vector with the
         * provided x, y and z values.
         * @param nX: initial x.
         * @param nY: initial y.
         * @param nZ: initial z.
         */
        Vector3D(float nX, float nY, float nZ);

        /**
         * assigns a vector to another by reassigning
         * the x, y and z values.
         * @param u: source vector.
         * @return [this] after reassignment.
         */
        Vector3D& operator=(const Vector3D& u);

        /**
         * asserts equality of vectors by asserting
         * equality of both vectors' x, y and z.
         * @param u: vector to be compared.
         * @return
         */
        bool operator==(const Vector3D& u) const;

        /**
         * Negate a vector by negating all of its values.
         * @return [this] negated.
         */
        Vector3D operator-() const;

        /**
         * transform a vector into a zero vector.
         */
        void zero();

        /**
         * Binary minus, subtracts two vectors.
         * @return [this] - [u]
         */
        Vector3D operator-(const Vector3D& u) const;

        /**
         * Binary plus, adds two vectors.
         * @return [this] + [u]
         */
        Vector3D operator+(const Vector3D& u) const;

        /**
         * Binary scalar multiplication,
         * multiplies a vector by a scalar.
         * @return [this] * [c]
         */
        Vector3D operator*(float c) const;

        /**
         * Binary scalar division,
         * divides a vector by a scalar.
         * @return [this] / [c]
         */
        Vector3D operator/(float c) const;

        /**
         * Add-assignment, assigns to [this]
         * [this] + [u].
         * @return [this]
         */
        Vector3D operator+=(const Vector3D& u);

        /**
         * Minus-assignment, assigns to [this]
         * [this] - [u].
         * @return [this]
         */
        Vector3D operator-=(const Vector3D& u);

        /**
         * Scalar multiplication assignment, assigns to [this]
         * [this] * [c].
         * @return [this]
         */
        Vector3D operator*=(float c);

        /**
         * Scalar division assignment, assigns to [this]
         * [this] / [c].
         * @return [this]
         */
        Vector3D operator/=(float c);

        /**
         * @return Dot product between [this] and [u].
         */
        float dot(const Vector3D& u) const;

        /**
         * @return Cross product between [this] and [u].
         */
        Vector3D cross(const Vector3D& u) const;

        /**
         * @return Magnitude (length) of [this].
         */
        float magnitude() const;

        /**
         * @return a normalized vector of [this].
         */
        Vector3D normalize() const;

        /**
         * @return distance of [this] (this / ||this||).
         */
        float distance(const Vector3D& u) const;

        std::string str() const;
    };

    /**
     * Scalar multiplication operator to allow left scalar
     * notation.
     */
    VECTOR_3D_API inline Vector3D operator*(float c, Vector3D& u);

    /**
     * toString operator override
     */
    VECTOR_3D_API inline std::ostream& operator<<(std::ostream& Str, Vector3D& v);

    // Const zero vector.
    VECTOR_3D_API const Vector3D ZeroVector;
}