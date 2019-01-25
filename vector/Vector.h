#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <cmath>
class Vector {
private:
	double x;
	double y;

public:
	Vector(const double x, const double y) {
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
	double getX() const { return x; }
	double getY() const { return y; }
	unsigned int length();
	void addVector(const Vector v1);

	void operator=(const Vector& v1);
	void operator*(const double speed);
	
	void operator/(const double speed);
	void normalize();	
};
Vector operator-(const Vector& v1, const Vector& v2);
Vector operator+(const Vector& v1, const Vector& v2);
Vector operator*(const Vector& v1, const Vector& v2);
Vector operator*(const Vector& v1, const double scale);
float dotProduct(const Vector & source, const Vector & destination);
std::ostream & operator << (std::ostream &out, const Vector &v);
Vector approach(const Vector& goal, const Vector& position, const Vector& delta);
bool operator<(const Vector& left, const Vector& right);
bool operator>(const Vector& left, const Vector& right);
Vector operator-(const Vector& right);
#endif