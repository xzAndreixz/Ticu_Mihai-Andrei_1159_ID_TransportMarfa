#include <iostream>
#include <cstring>
using namespace std;

class Camion {
public:
	int vitezaMax;
	float* consum;
	char* marca;
	const int nrRoti;
	static int nrCamioane;
};

class Sofer {
	char* nume;
	float* aniExp;
	int varsta;
	const char* catPermis;
	static int nrSoferi;

};

class Remorca {
	float* capacitate;
	const int nrAxe;
	bool franaProprie;
	const char* tipRemorca;
	static int nrRemorci;
};

int main() {


	return 0;

}