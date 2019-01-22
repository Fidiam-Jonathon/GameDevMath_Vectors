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
	/*
	Vector p1(0.0, -1.0);
	Vector e1(1.0, 1.0);
	Vector e2(2.0, -1.0);

	Vector pe1 = (p1 - e1);
	Vector pe2 = (p1 - e2);

	std::cout << "p1 - e1 length: " << pe2.length() << std::endl;
	std::cout << "p1 - e2 length: " << pe1.length() << std::endl;

	Vector startingPosition(0, 1);
	Vector doubleStartingPosition = startingPosition * 2;
	Vector halfStartingPosition = startingPosition / 2;

	std::cout << "starting length: " << startingPosition.length() << std::endl;
	std::cout << "doubled length: " << doubleStartingPosition.length() << std::endl;
	std::cout << "halfed length: " << halfStartingPosition.length() << std::endl;


	Vector i(3, 4);
	Vector p(1, 2);
	Vector pi = i - p;

	Vector normalized = pi.normalize();
	std::cout << "pi: " << pi << std::endl;
	std::cout << "pi length: " << pi.length() << std::endl;
	std::cout << "pi normal: " << normalized << std::endl;
	std::cout << "pi normal length: " << normalized.length() << std::endl;

	Vector r(4, 0);
	Vector d(0, -5);

	Vector v = r + d;
	std::cout << "r: " << r.getX() << " " << r.getY() << std::endl;
	std::cout << "d: " << d.getX() << " " << d.getY() << std::endl;
	std::cout << "r + d: " << v.getX() << " " << v.getY() << std::endl;

	Vector player(0, 1);
	Vector enemy(-1, 0.5);
	float directionEnemyIsFacing = dotProduct(player, enemy);
	std::cout << "player vector: " << player << std::endl;
	std::cout << "enemy vector: " << enemy << std::endl;
	std::cout << "player length: " << player.length() << std::endl;
	std::cout << "enemy length: " << enemy.length() << std::endl;
	std::cout << "player view: " << player.normalize() << std::endl;
	std::cout << "enemy view: " << enemy.normalize() << std::endl;
	std::cout << "dotproduct of Player and Enemy: " << directionEnemyIsFacing << std::endl;
	*/
	glfwInit();
	
	Vector mPosition(0, 0);
	Vector mVelocity(2, 2);
	Vector gravity(0, -2);
	double previousTime = 0;
	double currentTime = glfwGetTime();
	bool keepGoing = true;

	std::cout << "current position: " << mPosition << std::endl;
	std::cout << "current velocity: " << mVelocity << std::endl;
	
		while (keepGoing) {
		previousTime = currentTime;
		currentTime = glfwGetTime();
		double deltaTime = currentTime - previousTime;
		if (deltaTime > 0.15) {
			deltaTime = 0.15;
		}
		std::cout << "current position : " << mPosition << std::endl;
		std::cout << "current velocity: " << mVelocity << std::endl;
		Vector newPosition = updatePosition(mPosition, mVelocity, deltaTime);
		Vector newVelocity = updateVelocity(mVelocity, gravity, deltaTime);
		std::cout << "new position: " << newPosition << std::endl;
		std::cout << "new veloicty: " << newVelocity << std::endl;
		std::cout << std::endl;
		mPosition = newPosition;
		mVelocity = newVelocity;
		if (mVelocity.getY() <= 0.0) {
			keepGoing = false;
		}
		Sleep(2000);
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



