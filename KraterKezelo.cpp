#include "KraterKezelo.h"
#include <fstream>
#include <algorithm>
using namespace std;


KraterKezelo::KraterKezelo(){}

vector<Krater> KraterKezelo::getCreaters() {
	return this->craters;
}

vector<string> KraterKezelo::split(string characters, char separator) {
	vector<string> returnArray;
	string currentWord;
	for (char character : characters) {
		if (character == separator) {
			returnArray.push_back(currentWord);
			currentWord = "";
		}
		else {
			currentWord += character;
		}
	}
	returnArray.push_back(currentWord);

	return returnArray;
}

void KraterKezelo::readFromFile(string filename) {
	ifstream file(filename);
	string row;
	vector<string> splittedData;
	string name;
	while (getline(file, row)) {
		name = "";
		splittedData = this->split(row, '\t');
		this->craters.push_back(Krater(stof(splittedData[0]), stof(splittedData[1]), stof(splittedData[2]), splittedData[3]));
	}
}

Krater KraterKezelo::findCrater(string name) {
	for (Krater crater : this->craters)
	{
		if (crater.getName() == name) {
			return crater;
		}
	}
}

Krater KraterKezelo::findMaxRadius() {
	Krater biggest = this->craters[0];
	for (Krater crater : this->craters) {
		if (biggest.getRadius() < crater.getRadius()) {
			biggest = crater;
		}
	}
	return biggest;
}