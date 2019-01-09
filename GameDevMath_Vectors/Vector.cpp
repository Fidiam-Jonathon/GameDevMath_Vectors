#include "pch.h"
#include "Vector.h"

float Vector::length() const {
	float length = sqrt(x*x + y * y);
	return length;
}

float Vector::lengthSqr() const  {
	float length = (x * x) + (y * y);
	return length;
}

void Vector::addVector(Vector v1) {
	x += v1.getX();
	y += v1.getY();
}

Vector Vector::operator=(const Vector& v1) {
	Vector retVal(v1);
	return retVal;
}

Vector operator-(const Vector& v1, const Vector& v2){
	float x = v1.getX() - v2.getX();
	float y = v1.getY() - v2.getY();

	Vector retVal(x, y);
	return retVal;
}

Vector Vector::operator*(float speed) const{
	
	Vector scaled(this->getX() * speed, this->getY() * speed);
	return scaled;
}

Vector operator*(const Vector& v1, const Vector& v2) {
	Vector retVal((v1.getX() * v2.getX()), (v1.getY() * v2.getY()));
	return retVal;
}
Vector Vector::operator/(float speed) const{

	Vector scaled(this->getX() / speed, this->getY() / 2);
	return scaled;
}

Vector Vector::normalize() const{
	float unitX = this->getX() / this->length();
	float unitY = this->getY() / this->length();

	Vector normalize(unitX, unitY);
	return normalize;
}

Vector operator+(const Vector& v1, const Vector& v2){
	float x = v1.getX() + v2.getX();
	float y = v1.getY() + v2.getY();

	Vector retVal(x, y);
	return retVal;
}

float dotProduct(const Vector& source, const Vector & destination){
	Vector sourceToDestination = destination - source;
	sourceToDestination.normalize();

	float dotProduct = (source.getX() * sourceToDestination.getX()) +
		(source.getY() * sourceToDestination.getY());
	return dotProduct;
}
