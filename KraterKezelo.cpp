#include "KraterKezelo.h"
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;


KraterKezelo::KraterKezelo(){}

vector<Krater> KraterKezelo::getCraters() {
	return this->craters;
}

vector<string> KraterKezelo::split(string characters, char separator) {
	vector<string> returnVector;
	string currentWord;
	for (char character : characters) {
		if (character == separator) {
			returnVector.push_back(currentWord);
			currentWord = "";
		}
		else {
			currentWord += character;
		}
	}
	returnVector.push_back(currentWord);

	return returnVector;
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

float KraterKezelo::distance(float x1, float y1, float x2, float y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

vector<string> KraterKezelo::cratersWithNoIntersection(Krater crater) {
	vector<string> returnVector;
	for (Krater currentCrater : this->craters) {
		if (this->distance(crater.getX(), crater.getY(), currentCrater.getX(), currentCrater.getY()) > crater.getRadius() + currentCrater.getRadius()) {
			returnVector.push_back(currentCrater.getName());
		}
	}
	return returnVector;
}

vector<string> KraterKezelo::cratersWithIntersection() {
	vector<string> returnVector;
	for (int i = 0; i < this->craters.size(); ++i) {
		for (int j = i + 1; j < this->craters.size(); ++j) {
			Krater crater1 = this->craters[i];
			Krater crater2 = this->craters[j];
			float biggerRadius = crater1.getRadius() > crater2.getRadius() ? crater1.getRadius() : crater2.getRadius();
			float smallerRadius = crater1.getRadius() > crater2.getRadius() ? crater2.getRadius() : crater1.getRadius();
			if (this->distance(crater1.getX(), crater1.getY(), crater2.getX(), crater2.getY()) < biggerRadius - smallerRadius &&
				find(returnVector.begin(), returnVector.end(), crater1.getName() + ";" + crater2.getName()) == returnVector.end() &&
				find(returnVector.begin(), returnVector.end(), crater2.getName() + ";" + crater1.getName()) == returnVector.end()) {
				returnVector.push_back(crater1.getName() + ";" + crater2.getName());
			}
		}
	}
	return returnVector;
}

void KraterKezelo::outputArea() {
	ofstream file;
	file.open("terulet.txt");
	for (Krater crater : this->craters) {
		file << fixed << setprecision(2) << pow(crater.getRadius(), 2) * 3.14 << "\t" + crater.getName() << endl;
	}
	file.close();
}