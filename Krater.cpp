#include "Krater.h"
#include <string>
using namespace std;
Krater::Krater(float x, float y, float radius, string name) {
	this->x = x;
	this->y = y;
	this->radius = radius;
	this->name = name;
}

float Krater::getX() {
	return this->x;
}

float Krater::getY() {
	return this->y;
}

float Krater::getRadius() {
	return this->radius;
}

string Krater::getName() {
	return this->name;
}