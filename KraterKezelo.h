#pragma once
#include "Krater.h"
#include <vector>

using namespace std;
class KraterKezelo
{
	vector<Krater> craters;

	private:
		float distance(float x1, float y1, float x2, float y2);

	public:
		KraterKezelo();
		vector<Krater> getCraters();
		void readFromFile(string filename);
		vector<string> split(string characters, char separator);
		Krater findCrater(string name);
		Krater findMaxRadius();
		vector<string> cratersWithNoIntersection(Krater crater);
		vector<string> cratersWithIntersection();
		void outputArea();
};

