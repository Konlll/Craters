#pragma once
#include <string>
using namespace std;
class Krater
{
	float x, y, radius;
	string name;

	public:
		Krater();
		Krater(float, float, float, string);
		float getX();
		float getY();
		float getRadius();
		string getName();
};