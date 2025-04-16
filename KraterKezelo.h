#pragma once
#include "Krater.h"
#include <vector>

using namespace std;
class KraterKezelo
{
	vector<Krater> craters;

	public:
		KraterKezelo();
		vector<Krater> getCreaters();
		void readFromFile(string filename);
		vector<string> split(string characters, char separator);
		Krater findCrater(string name);
		Krater findMaxRadius();
};

