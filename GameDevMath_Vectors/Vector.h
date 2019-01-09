#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>
class Vector {
private:
	float x;
	float y;

public:
	Vector(float x, float y) {
		this->x = x;
		this->y = y;
	}

	Vector() {
		x = 0;
		y = 0;
	}

	Vector(const Vector &v1) {
		x = v1.getX();
		y = v1.getY();
	}
	float getX() const { return x; }
	float getY() const { return y; }
	float length() const;
	float lengthSqr() const;
	void addVector(Vector v1);

	Vector operator=(const Vector& v1);
	Vector operator*(float speed) const;
	
	Vector operator/(float speed) const;
	Vector normalize() const;
	float dotProduct(const Vector & source, const Vector & destination)const;
	
};
Vector operator-(const Vector& v1, const Vector& v2);
Vector operator+(const Vector& v1, const Vector& v2);
Vector operator*(const Vector& v1, const Vector& v2);
float dotProduct(const Vector & source, const Vector & destination);
#endif