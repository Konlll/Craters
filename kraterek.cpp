#include <iostream>
#include "KraterKezelo.h"
#include <vector>;
#include <string>;
using namespace std;

int main()
{
	KraterKezelo handler = KraterKezelo();
	handler.readFromFile("felszin_tpont.txt");
	
	cout << "2. feladat" << endl << "A kraterek szama: " << handler.getCraters().size() << endl;
	
	cout << "3. feladat" << endl << "Kerem egy krater nevet: ";
	string crater;
	getline(cin, crater);
	Krater found = handler.findCrater(crater);
	if (found.getName().length() != 0) {
		cout << "A(z) " + found.getName()
			+ " kozeppontja X=" << found.getX()
			<< " Y=" << found.getY()
			<< " sugara R=" << found.getRadius() << endl;
	}
	else {
		cout << "Nincs ilyen nevu krater!";
	}

	Krater biggestRadiusCrater = handler.findMaxRadius();
	cout << "4. feladat" << endl << "A legnagyob krater neve es sugara: " + biggestRadiusCrater.getName() + " " << biggestRadiusCrater.getRadius();

	cout << "6. feladat" << endl << "Kerem egy krater nevet: ";
	getline(cin, crater);
	Krater found2 = handler.findCrater(crater);
	if (found2.getName().length() != 0) {
		vector<string> cratersWithNoIntersection = handler.cratersWithNoIntersection(found2);
		if (cratersWithNoIntersection.size() != 0) {
			string result;
			for (string name : cratersWithNoIntersection) {
				result += name + ", ";
			}
			cout << endl << "Nincs kozos resze: " + result.substr(0, result.length() - 2);
		}
	}

	cout << "7. feladat" << endl;
	vector<string> cratersWithIntersection = handler.cratersWithIntersection();
	for (string intersection : cratersWithIntersection) {
		vector<string> data = handler.split(intersection, ';');
		cout << "A(z) " + data[0] + " krater tartalmazza a(z) " + data[1] + " kratert." << endl;
	}

	handler.outputArea();
}