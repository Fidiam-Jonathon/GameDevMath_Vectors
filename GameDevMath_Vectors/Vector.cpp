#include "pch.h"
#include "Vector.h"

unsigned int Vector::length() {
	return sqrt(x * x + y * y);
}

void Vector::addVector(const Vector v1) {
	x += v1.getX();
	y += v1.getY();
}

void Vector::operator=(const Vector& v1) {
	this->x = v1.getX();
	this->y = v1.getY();
}

Vector operator-(const Vector& v1, const Vector& v2){
	float x = v1.getX() - v2.getX();
	float y = v1.getY() - v2.getY();

	Vector retVal(x, y);
	return retVal;
}

void Vector::operator*(const double speed){
	this->x = this->getX() * speed;
	this->y = this->getY() * speed;
}

Vector operator*(const Vector& v1, const Vector& v2) {
	Vector retVal((v1.getX() * v2.getX()), (v1.getY() * v2.getY()));
	return retVal;
}
void Vector::operator/(double speed){
	this->x = this->x / speed;
	this->y = this->y / speed;
}

void Vector::normalize(){
	this->x = this->x / this->length();
	this->y = this->y / this->length();
}

Vector operator+(const Vector& v1, const Vector& v2){
	float x = v1.getX() + v2.getX();
	float y = v1.getY() + v2.getY();

	Vector retVal(x, y);
	return retVal;
}

float dotProduct(const Vector& source, const Vector & destination){
	Vector sourceView = destination - source;
	Vector destView = source - destination;
	sourceView.normalize();
	destView.normalize();

	float dotProduct = (sourceView.getX() * destView.getX()) + (sourceView.getY() * destView.getY());
	return dotProduct;
}

std::ostream& operator << (std::ostream& out, const Vector& v) {
	out << v.getX() << " " << v.getY();
	return out;
}

Vector operator*(const Vector& v1, const double scale) {
	Vector retVal(v1.getX() * scale, v1.getY() * scale);
	return retVal;
}

bool operator<(const Vector& left, const Vector& right) {
	Vector leftMinusRight = left - right;
	Vector rightMinusLeft = right - left;

	if (leftMinusRight.getX() < rightMinusLeft.getX() ||
		leftMinusRight.getY() < rightMinusLeft.getY()) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>(const Vector& left, const Vector& right) {
	if (left < right) {
		return false;
	}
	else {
		return true;
	}
}


Vector approach(const Vector& goal, const Vector& position, const Vector& delta) {
	Vector retVal(0, 0);
	Vector difference = goal - position;
	if (difference < delta) {
		retVal = difference + delta;
	}
	if (difference < -delta) {
		retVal = difference - delta;
	}
	if (difference.getX() == 0 && difference.getY() == 0) {
		retVal = goal;
	}
	return retVal;
}

Vector operator-(const Vector& right) {
	Vector retVal(-right.getX(), -right.getY());
	return retVal;
}
