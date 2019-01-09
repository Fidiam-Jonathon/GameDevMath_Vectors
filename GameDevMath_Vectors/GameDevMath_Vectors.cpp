// GameDevMath_Vectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "vector.h"
#include <iostream>

int main()
{
	Vector p1(0.0, -1.0);
	Vector e1(1.0, 1.0);
	Vector e2(2.0, -1.0);

	Vector pe1 = (p1 - e1);
	Vector pe2 = (p1 - e2);

	std::cout << "p1 - e1 length: " << pe2.lengthSqr() << std::endl;
	std::cout << "p1 - e2 length: " << pe1.lengthSqr() << std::endl;

	Vector startingPosition(3, 4);
	Vector doubleStartingPosition = startingPosition * 2;
	Vector halfStartingPosition = startingPosition / 2;

	std::cout << "starting length: " << startingPosition.length() << std::endl;
	std::cout << "doubled length: " << doubleStartingPosition.length() << std::endl;
	std::cout << "halfed length: " << halfStartingPosition.length() << std::endl;

	Vector p3(3, 4);
	Vector p4(1, 2);
	Vector pDiff = p3 - p4;
	
	Vector normalized = pDiff.normalize();

	std::cout << "pDiff: " << pDiff.getX() << " " << pDiff.getY() << std::endl;
	std::cout << "normalized: " << normalized.length() << std::endl;

	Vector r(4, 0);
	Vector d(0, -5);

	Vector v = r + d;
	std::cout << "r: " << r.getX() << " " << r.getY() << std::endl;
	std::cout << "d: " << d.getX() << " " << d.getY() << std::endl;
	std::cout << "r + d: " << v.getX() << " " << v.getY() << std::endl;

	Vector player(0, 1);
	Vector enemy(0, 1);
	float directionEnemyIsFacing = dotProduct(player, enemy);

	std::cout << "dotproduct of Player and Enemy: " << directionEnemyIsFacing << std::endl;
	return 0;
}



