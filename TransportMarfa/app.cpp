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
		nrCamioane++;

	}
	Camion(float consum, const char* marca): nrRoti(6) {
		this->vitezaMax = 90;
		this->consum = new float(consum);
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		nrCamioane++;


	}
	Camion(int viteza, float consum,const char* marca, int nrRoti) :nrRoti(nrRoti) {
		this->vitezaMax = viteza;
		this->consum = new float(consum);
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		nrCamioane++;

	}

	 static int getNrCamioane() {
		return nrCamioane;
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
	Sofer(const char* nume, float aniExp, int varsta, const char* cat) :catPermis(cat) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->varsta = varsta;
		
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
	Remorca(float capacitate, int axe, bool frana, const char* tipRemorca) : nrAxe(axe) {

		this->capacitate = new float(capacitate);
		this->franaProprie = frana;
		this->tipRemorca = new char[strlen(tipRemorca) + 1];
		strcpy_s(this->tipRemorca, strlen(tipRemorca) + 1, tipRemorca);

	}
	

};
int Remorca::nrRemorci = 0;





int main() {

	Camion tir01(90, 58.5, "Man tip 1", 8);
	cout << "Datele camionului\nViteza maxima: " << tir01.vitezaMax << "\nConsum: " << *tir01.consum << "\nMarca & model: " << tir01.marca << "\nNr. roti: " << tir01.nrRoti;
	cout << endl << endl;
	Camion tir02(90, 45, "Mercedes tip 1", 8);
	cout << "Datele camionului\nViteza maxima: " << tir02.vitezaMax << "\nConsum: " << *tir02.consum << "\nMarca & model: " << tir02.marca << "\nNr. roti: " << tir02.nrRoti;
	cout << "\nNumar total camioane: " << Camion::getNrCamioane();
	cout << endl << endl;
	Camion tir03(90, 40, "Volvo tip 1", 8);
	cout << "Datele camionului\nViteza maxima: " << tir03.vitezaMax << "\nConsum: " << *tir03.consum << "\nMarca & model: " << tir03.marca << "\nNr. roti: " << tir03.nrRoti;
	cout << "\nNumar total camioane: " << Camion::getNrCamioane();
	cout << endl;
	Remorca rem01(40, 8,true, "Cisterna");

	cout << "\n\nDatele remorci\nCapacitatea: " << *rem01.capacitate << "\nNr. axe: " << rem01.nrAxe << "\nFrana:  ";
	if (rem01.franaProprie) cout << "Are frana prorpie";
	cout << "\nTip remorca: " << rem01.tipRemorca;


	return 0;

}