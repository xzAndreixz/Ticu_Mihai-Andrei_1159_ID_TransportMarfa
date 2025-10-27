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
		this->vitezaMax = 90;
		this->consum = new float(38.5f);
		this->marca = new char[15]; //aloc 15 caractere pentru marca de tir
		strcpy_s(this->marca, 15, "Nedeclarata");

	}
	Camion(float consum, const char* marca): nrRoti(6) {
		this->vitezaMax = 90;
		this->consum = new float(consum);
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);

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
	Sofer(const char* numesofer, int varstasofer) :catPermis("CE") {
		this->nume = new char[strlen(numesofer) + 1];
		strcpy_s(this->nume, strlen(numesofer) + 1, numesofer);
		this->aniExp = nullptr;
		this->varsta = varstasofer;
	}

};
int Sofer::nrSoferi = 0;

class Remorca {
public:
	float* capacitate;
	const int nrAxe;
	bool franaProprie;
	char* tipRemorca;
	static int nrRemorci;

	//declar unele variabile nu doar cele cu "static" folosind lista de initializare a constructorului!!!
	Remorca() : nrAxe(2), capacitate(new float(40.0f)), franaProprie(true) {
		nrRemorci++;
		this->tipRemorca = nullptr;

	}
	
	Remorca(float capacitate, int axe, const char* tip) :nrAxe(axe) {
		this->capacitate = new float(capacitate);
		this->franaProprie = true;
		this->tipRemorca = new char[strlen(tip) + 1];
		strcpy_s(this->tipRemorca, strlen(tip) + 1, tip);



	}

};
int Remorca::nrRemorci = 0;





int main() {

	Camion man01(58.5, "Man Tip 1");

	cout << man01.marca<<endl;
	cout << *man01.consum; 

	cout << endl << endl;
	Sofer sofoer01("Mihai Andrei", 27);
	cout << "Soferul " << sofoer01.nume << " are " << sofoer01.varsta << " ani!"<<endl;
	Remorca	remorca01(49.5, 4, "Cisterna");
	cout << "\nDate remorca\nCapacitate: " << *remorca01.capacitate << "\nNr. axe: " << remorca01.nrAxe << "\nTip: " << remorca01.tipRemorca << "\n";

	

	return 0;

}