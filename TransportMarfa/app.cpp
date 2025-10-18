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

	Camion() : nrRoti(6){ //declari aici fiindca const trebuie declarat inainte de crearea obiectului altfel ar da eroare...nu poti modifica o constanta dupa crearea obiectului!
		vitezaMax = 90;
		consum = new float(38.5f);
		marca = new char[15]; //aloc 15 caractere pentru marca de tir
		strcpy_s(marca, 15, "Nedeclarata");

	}

};

int Camion::nrCamioane = 0;

class Sofer {
public:
	char* nume;
	float* aniExp;
	int varsta;
	const char* catPermis;
	static int nrSoferi;

	Sofer() : catPermis("CE") {
		nrSoferi++;
		nume = nullptr; //pot initializa si asa...iar cand am nevoie fac verificare si atribui memorie si pun textul acolo
		aniExp = nullptr;


	}

};
int Sofer::nrSoferi = 0;

class Remorca {
public:
	float* capacitate;
	const int nrAxe;
	bool franaProprie;
	const char* tipRemorca;
	static int nrRemorci;

	Remorca() : capacitate(new float(10.0f)),nrAxe(2),franaProprie(true), tipRemorca("Prelata") {
		nrRemorci++;
	}
};
int Remorca::nrRemorci = 0;

int main() {

	Camion c1;

	cout << "Introduceti marca: ";
	cin >> c1.marca;


	cout << c1.marca;


	return 0;

}