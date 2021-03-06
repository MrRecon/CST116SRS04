// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
//#include <limits>

int main()
{
	const double PI = 4.0 * atan(1.0); //Precise PI gathered from http://www.dreamincode.net/forums/topic/186421-c-calculating-sides-of-triangles/
	const int Leave{0}, AAA{ 1 }, AAS{ 2 }, ASA{ 3 }, SAS{ 4 }, SSA{ 5 }, SSS{ 6 };
	double aaaAngle1{}, aaaAngle2{}, aaaAngle3{}, aaaSide1{}, aaaSide2{};
	double aasAngle1{}, aasAngle2{}, aasAngle3{}, aasSide1{}, aasSide2{}, aasSide3{};
	double asaAngle1{}, asaAngle2{}, asaAngle3{}, asaSide1{}, asaSide2{}, asaSide3{};
	double sasAngle1{}, sasAngle2{}, sasAngle3{}, sasSide1{}, sasSide2{}, sasSide3{};
	double ssaAngle1{}, ssaAngle2{}, ssaAngle3{}, ssaAngle4{}, ssaAngle5{}, ssaSide1{}, ssaSide2{}, ssaSide3{}, ssaSide4{};
	double sssAngle1{}, sssAngle2{}, sssAngle3{}, sssSide1{}, sssSide2{}, sssSide3{};
	int configuration_type{};

	label:
	std::cout << "Numarically choose from the following list: \n \n {0}Leave Program \n {1}AAA \n {2}AAS \n {3}ASA \n {4}SAS \n {5}SSA \n {6}SSS \n" << std::endl;
	std::cout << "Choose your number: ";
	std::cin >> configuration_type;
	assert(configuration_type == 1 || 2 || 3 || 4 || 5 || 6);
	
	switch (configuration_type)
	{
	case AAA:

		std::cout << "Great choice, please enter required info.\n" << std::endl;
		std::cout << "Enter angle 1 (degrees): "; std::cin >> aaaAngle1;
		std::cout << "Enter angle 2 (degrees): "; std::cin >> aaaAngle2;

		aaaAngle3 = 180 - (aaaAngle1 + aaaAngle2);
		aaaSide1 = (sin(aaaAngle1 * PI / 180)) / (sin(aaaAngle3 * PI / 180));
		aaaSide2 = (sin(aaaAngle2 * PI / 180)) / (sin(aaaAngle3 * PI / 180));

		if (aaaAngle3 <= 0)
		{
			std::cout << "Can't solve this one, lets try another";
			goto label; //Almost ALL documentation urges against this but you cant restart a switch statement without encapsulating it in a while/for loop that i know of.
		}
		else
		{
			std::cout << "Angle 3 is = " << std::setw(3) << aaaAngle3 << " degrees" << std::endl;
			std::cout << "\nTriangle is proportional.";
			std::cout << "\nFor example, if one side is 1\nSecond side equals " << aaaSide1 << "\nThird side equals " << aaaSide2 << std::endl; //From Simon
		}

		break;

	case AAS:
		std::cout << "Great choice, please enter required info.\n" << std::endl;

		std::cout << "Enter angle 1 (degrees): ";
		std::cin >> aasAngle1;
		std::cout << "Enter angle 2 (degrees): ";
		std::cin >> aasAngle2;
		std::cout << "Enter side length: ";
		std::cin >> aasSide1;

		aasAngle3 = 180 - (aasAngle1 + aasAngle2);
		aasSide2 = (sin(aasAngle2 * PI / 180)) * (aasSide1) / (sin(aasAngle1 * PI / 180));
		aasSide3 = (sin(aasAngle3 * PI / 180)) * (aasSide1) / (sin(aasAngle1 * PI / 180));

		if (aasAngle3 <= 0 || aasSide1 <= 0)
		{
			std::cout << "Can't solve this one, lets try another" << std::endl;
			goto label;
		}
		else
		{
			std::cout << "Angle 3 is = " << aasAngle3 << "degrees";
			std::cout << "\nSecond side = " << aasSide2;
			std::cout << "\nThird side = " << aasSide3;
		}

		break;

	case ASA:
		std::cout << "Great choice, please enter required info.\n" << std::endl;
		std::cout << "Enter angle 1 (degrees): ";
		std::cin >> asaAngle1;
		std::cout << "Enter side length: ";
		std::cin >> asaSide1;
		std::cout << "Enter angle 2 (degrees): ";
		std::cin >> asaAngle2;


		asaAngle3 = 180 - (asaAngle1 + asaAngle2);
		asaSide2 = (sin(asaAngle1 * PI / 180)) * (asaSide1) / (sin(asaAngle3 * PI / 180));
		asaSide3 = (sin(asaAngle2 * PI / 180)) * (asaSide1) / (sin(asaAngle3 * PI / 180));

		if (asaAngle3 <= 0 || asaSide1 <= 0)
		{
			std::cout << "Can't solve this one, lets try another" << std::endl;
			goto label;
		}
		else
		{
			std::cout << "\nAngle 3 is = " << asaAngle3 << " degrees.";
			std::cout << "\nSecond side = " << asaSide2;
			std::cout << "\nThird side = " << asaSide3;
		}
		break;

	case SAS:
		std::cout << "Great choice, please enter required info.\n" << std::endl;
		std::cout << "Enter first side length: ";
		std::cin >> sasSide1;
		std::cout << "Enter angle 1 (degrees): ";
		std::cin >> sasAngle1;
		std::cout << "Enter second side length: ";
		std::cin >> sasSide2;

		sasSide3 = sqrt((sasSide1 * sasSide1 + sasSide2 * sasSide2) - (2 * sasSide1 * sasSide2 * cos(sasAngle1 * PI / 180)));
		sasAngle2 = (asin((sin(sasAngle1 * PI / 180))*(sasSide1) / (sasSide3))) * 180 / PI;
		sasAngle3 = 180 - (sasAngle1 + sasAngle2);

		if (sasSide1 <= 0 || sasSide2 <= 0 || sasAngle1 <= 0)
		{
			std::cout << "Can't solve this one, lets try another" << std::endl;
			goto label;
		}
		else
		{
			std::cout << "\nSide 3 is = " << sasSide3;
			std::cout << "\nSecond angle = " << sasAngle2 << " degrees.";
			std::cout << "\nThird angle = " << sasAngle3 << " degrees.";
		}
		break;

	case SSA:
		std::cout << "Great choice, please enter required info.\n" << std::endl;
		std::cout << "Enter first side length: ";
		std::cin >> ssaSide1;
		std::cout << "Enter second side length: ";
		std::cin >> ssaSide2;
		std::cout << "Enter angle 1 (degrees): ";
		std::cin >> ssaAngle1;

		ssaAngle2 = (asin((sin(ssaAngle1 * PI / 180)) * (ssaSide2) / (ssaSide1))) * 180 / PI;
		ssaAngle3 = 180 - (ssaAngle1 + ssaAngle2);
		ssaSide3 = (sin(ssaAngle3 * PI / 180)) * (ssaSide1) / (sin(ssaAngle1 * PI / 180));
		ssaAngle4 = 180 - ssaAngle2;
		ssaAngle5 = 180 - (ssaAngle1 + ssaAngle4);
		ssaSide4 = (sin(ssaAngle5 * PI / 180)) * (ssaSide1) / (sin(ssaAngle1 * PI / 180));

		if (ssaSide1 <= 0 || ssaSide2 <= 0 || ssaAngle1 <= 0)
		{
			std::cout << "Can't solve this one, lets try another" << std::endl;
			goto label;
		}
		else
		{
			std::cout << "\nFirst Solution:";
			std::cout << "\nSide 3 is = " << ssaSide3;
			std::cout << "\nSecond angle = " << ssaAngle2 << " degrees.";
			std::cout << "\nThird angle = " << ssaAngle3 << " degrees.";
		}
		if (ssaAngle1 + ssaAngle4 + ssaAngle5 > 180 || ssaSide4 <= 0)
		{
			std::cout << "\n\nSorry, no second solution.";
		}
		else
		{
			std::cout << "\n\nSecond Solution:";
			std::cout << "\nThird side equals " << ssaSide4;
			std::cout << "\nSecond angle equals " << ssaAngle4 << " degrees.";
			std::cout << "\nThird angle equals " << ssaAngle5 << " degrees.";
		}
		break;

	case SSS:
		std::cout << "Great choice, please enter required info.\n" << std::endl;
		std::cout << "Enter first side length: ";
		std::cin >> sssSide1;
		std::cout << "Enter second side length: ";
		std::cin >> sssSide2;
		std::cout << "Enter third side length: ";
		std::cin >> sssSide3;

		sssAngle1 = acos((sssSide1 * sssSide1 + sssSide2 * sssSide2 - sssSide3 * sssSide3) / (2 * sssSide1 * sssSide2)) * 180 / PI;
		sssAngle2 = acos((sssSide2 * sssSide2 + sssSide3 * sssSide3 - sssSide1 * sssSide1) / (2 * sssSide2 * sssSide3)) * 180 / PI;
		sssAngle3 = 180 - (sssAngle1 + sssAngle2);

		if (sssSide1 <= 0 || sssSide2 <= 0 || sssSide3 <= 0)
		{
			std::cout << "Unsolvable";
		}
		else
		{
			std::cout << "\nFirst angle = " << sssAngle1 << " degrees.";
			std::cout << "\nSecond angle = " << sssAngle2 << " degrees.";
			std::cout << "\nThird angle = " << sssAngle3 << " degrees.";
		}
		break;

	case Leave:
		std::cout << "Thank you!";
		break;
	}

	return 0;

}
	

