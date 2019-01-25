// GameDevMath_Vectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "vector.h"
#include <iostream>
#include <time.h>
#include <glfw3.h>
#include <Windows.h>

Vector updatePosition(const Vector & currentPosition, const Vector & velocity, const double time);
Vector updateVelocity(const Vector& velocity, const Vector& gravity, const double time);
int main()
{
	glfwInit();
	
	Vector start(0, 0);
	Vector goal(10, 10);

	double currentTime = glfwGetTime();
	bool keepGoing = true;
	
		while (keepGoing) {

		}
	

	return 0;
}

Vector updatePosition(const Vector & currentPosition, const Vector & velocity, const double time) {
	Vector newPosition = currentPosition + (velocity * time);
	return newPosition;
}
Vector updateVelocity(const Vector& velocity, const Vector& gravity, const double time) {
	Vector newVelocity = velocity + (gravity * time);
	return newVelocity;
}



