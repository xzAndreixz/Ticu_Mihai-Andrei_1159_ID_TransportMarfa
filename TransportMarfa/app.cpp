#include <iostream>
#include <cstring>
using namespace std;

class Camion {
private:
	int vitezaMax;
	float* consum;
	char* marca;
	const int nrRoti;
	static int nrCamioane;

public:
	

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

	 ~Camion();
	 Camion(const Camion& copie) : nrRoti(copie.nrRoti){ //nu e obligatoriu sa folosesti this in constructor de copiere dar am vrut eu :)
		 this->vitezaMax = copie.vitezaMax;
		 if (copie.consum != nullptr )  
			 this->consum = new float(*copie.consum);  else this->consum = nullptr;
		 if (copie.marca != nullptr) {
			 this->marca = new char[strlen(copie.marca) + 1];
			 strcpy_s(this->marca, strlen(copie.marca) + 1, copie.marca);
		 }
		 else this->marca = nullptr; //aici nu pui * fiindca daca ai pune ai retine doar primul caracter..de ce? fiindca se pune un pointer catre incepului sirului de caractere
		 nrCamioane++;	
	 }

	 

};
int Camion::nrCamioane = 0;
Camion::~Camion() {
	if (consum != nullptr) {
		delete consum;
		consum = nullptr;
	}

	if (marca != nullptr) {
		delete[] marca;
		marca = nullptr;
	}
}

class Sofer {
private:
	char* nume;
	float* aniExp;
	int varsta;
	const char* catPermis;
	static int nrSoferi;

public:
	
	Sofer() : catPermis("CE") {
		nrSoferi++;
		nume = nullptr; //pot initializa si asa...iar cand am nevoie fac verificare si atribui memorie si pun textul acolo
		aniExp = nullptr;
		nrSoferi++;
	}
	Sofer(const char* numesofer, int varstasofer) :catPermis("CE") {
		this->nume = new char[strlen(numesofer) + 1];
		strcpy_s(this->nume, strlen(numesofer) + 1, numesofer);
		this->aniExp = nullptr;
		this->varsta = varstasofer;
		nrSoferi++;
	}
	Sofer(const char* nume, float aniExp, int varsta, const char* cat) :catPermis(cat) {
		this->nume = new char[strlen(nume) + 1];
		this->aniExp = new float(aniExp);
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->varsta = varsta;
		nrSoferi++;
	}

	static int getNrSoferi() {
		return nrSoferi;
	}

	~Sofer();

	Sofer(const Sofer& copie) :catPermis(copie.catPermis) {
		if (copie.nume != nullptr) {
			nume = new char[strlen(copie.nume) + 1];
			strcpy_s(nume, strlen(copie.nume) + 1, copie.nume);
		}
		else
			nume = nullptr;
		if (copie.aniExp != nullptr)
			aniExp = new float(*copie.aniExp);
		else
			aniExp = nullptr;
		varsta = copie.varsta;
		nrSoferi++;
	}
};
int Sofer::nrSoferi = 0;
Sofer::~Sofer() {
	if (nume != nullptr) {
		delete[] nume;
		nume = nullptr;
	}
	if (aniExp != nullptr) {
		delete aniExp;
		aniExp = nullptr;
	}
}

class Remorca {
private:
	float* capacitate;
	const int nrAxe;
	bool franaProprie;
	char* tipRemorca;
	static int nrRemorci;
	
public:
	
	//declar unele variabile nu doar cele cu "static" folosind lista de initializare a constructorului!!!
	Remorca() : nrAxe(2), capacitate(new float(40.0f)), franaProprie(true) {
		nrRemorci++;
		this->tipRemorca = nullptr;
		nrRemorci++;
	}
	Remorca(float capacitate, int axe, const char* tip) :nrAxe(axe) {
		this->capacitate = new float(capacitate);
		this->franaProprie = true;
		this->tipRemorca = new char[strlen(tip) + 1];
		strcpy_s(this->tipRemorca, strlen(tip) + 1, tip);
		nrRemorci++;

	}
	Remorca(float capacitate, int axe, bool frana, const char* tipRemorca) : nrAxe(axe) {

		this->capacitate = new float(capacitate);
		this->franaProprie = frana;
		this->tipRemorca = new char[strlen(tipRemorca) + 1];
		strcpy_s(this->tipRemorca, strlen(tipRemorca) + 1, tipRemorca);
		nrRemorci++;
	}
	
	static int getNrRemorci() {
		return nrRemorci;
}
	~Remorca();

	Remorca(const Remorca& copie) : nrAxe(copie.nrAxe), capacitate(nullptr), tipRemorca(nullptr) {  //poti pune si ca aceste atribute sa pointeze catre nimic in caz ca da vreo eroare si nu intra pe else pentru a nu fi neintializate
		if (copie.capacitate != nullptr)
			capacitate = new float(*copie.capacitate);
		else
			capacitate = nullptr;
		franaProprie = copie.franaProprie;
		if (copie.tipRemorca != nullptr) {
			tipRemorca = new char[strlen(copie.tipRemorca) + 1];
			strcpy_s(tipRemorca, strlen(copie.tipRemorca) + 1, copie.tipRemorca);
		}
		else
			tipRemorca = nullptr;
		nrRemorci++;
	}
};
int Remorca::nrRemorci = 0;
Remorca::~Remorca() {
	if (capacitate != nullptr) {
		delete capacitate;
		capacitate = nullptr;
	}
}




int main() {
		/*
	Camion c1(100, 35.5f, "Volvo", 8);
	Camion c2 = c1;
	Camion c3(c1);
	Sofer s1("Andrei", 5.5f, 28, "CE");
	Sofer s2 = s1;
	Sofer s3(s1);
	Remorca r1(42.3f, 3, true, "Cisterna");
	Remorca r2 = r1;
	Remorca r3(r1);

	cout << "=== TEST CONSTRUCTORI ===" << endl;
	
	cout << endl;
	cout << "Camion c1:" << endl;
	cout << "  Viteza: " << c1.vitezaMax << endl;
	cout << "  Consum: " << *c1.consum << endl;
	cout << "  Marca: " << c1.marca << endl;
	cout << "  Nr. roti: " << c1.nrRoti << endl;

	cout << endl;
	cout << "Camion c2:" << endl;
	cout << "  Viteza: " << c2.vitezaMax << endl;
	cout << "  Consum: " << *c2.consum << endl;
	cout << "  Marca: " << c2.marca << endl;
	cout << "  Nr. roti: " << c2.nrRoti << endl;

	cout << endl;
	cout << "Camion c3:" << endl;
	cout << "  Viteza: " << c3.vitezaMax << endl;
	cout << "  Consum: " << *c3.consum << endl;
	cout << "  Marca: " << c3.marca << endl;
	cout << "  Nr. roti: " << c3.nrRoti << endl;

	cout << endl;
	cout << "\nSofer s1:" << endl;
	cout << "  Nume: " << s1.nume << endl;
	cout << "  Varsta: " << s1.varsta << endl;
	cout << "  Permis: " << s1.catPermis << endl;

	cout << endl;
	cout << "\nSofer s2:" << endl;
	cout << "  Nume: " << s2.nume << endl;
	cout << "  Varsta: " << s2.varsta << endl;
	cout << "  Permis: " << s2.catPermis << endl;

	cout << "\nSofer s3:" << endl;
	cout << "  Nume: " << s3.nume << endl;
	cout << "  Varsta: " << s3.varsta << endl;
	cout << "  Permis: " << s3.catPermis << endl;

	cout << endl;
	cout << "\nRemorca r1:" << endl;
	cout << "  Tip: " << r1.tipRemorca << endl;
	cout << "  Capacitate: " << *r1.capacitate << " tone" << endl;
	cout << "  Nr. axe: " << r1.nrAxe << endl;
	cout << endl;
	cout << "\nRemorca r2:" << endl;
	cout << "  Tip: " << r2.tipRemorca << endl;
	cout << "  Capacitate: " << *r2.capacitate << " tone" << endl;
	cout << "  Nr. axe: " << r2.nrAxe << endl;
	cout << endl;
	cout << "\nRemorca r3:" << endl;
	cout << "  Tip: " << r3.tipRemorca << endl;
	cout << "  Capacitate: " << *r3.capacitate << " tone" << endl;
	cout << "  Nr. axe: " << r3.nrAxe << endl;

	*/

	return 0;

}