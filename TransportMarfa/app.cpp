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
	Camion(const Camion& copie) : nrRoti(copie.nrRoti) { //nu e obligatoriu sa folosesti this in constructor de copiere dar am vrut eu :)
		this->vitezaMax = copie.vitezaMax;
		if (copie.consum != nullptr)
			this->consum = new float(*copie.consum);  else this->consum = nullptr;
		if (copie.marca != nullptr) {
			this->marca = new char[strlen(copie.marca) + 1];
			strcpy_s(this->marca, strlen(copie.marca) + 1, copie.marca);
		}
		else this->marca = nullptr; //aici nu pui * fiindca daca ai pune ai retine doar primul caracter..de ce? fiindca se pune un pointer catre incepului sirului de caractere
		nrCamioane++;
	}

	 ~Camion();
	 //facem get-eri
	 static int getNrCamioane() {
		 cout << "\nNumar total camioane create pana acum: ";
		 return nrCamioane;
	 }
	 int getVitezaMax() {
		 return this->vitezaMax;
	}
	 float getConsum() {
		 if (this->consum != nullptr)
			 return *this->consum;
		 else
			 return 0.0f;
	 }

	 const char* getmarca() {   //Am pus const pentru a putea returna constanta "Nedeclarata!"
		 
		 if (this->marca != nullptr)
			 return this->marca;
		 else 
			 return "Nedeclarat!";
		 
	 }
	 int getNrRoti() const{
		 return this->nrRoti;
	 }

	 //set-eri
	 void setVitezaMax(int vitezaMax) {
		 this->vitezaMax = vitezaMax;
	 }

	 void setConsum(float consum) {   //aici puteam pune si const float* consum
		 if (this->consum != nullptr) {
			 delete this->consum;
			 this->consum = nullptr;
		 }
		 this->consum = new float(consum);
	 }

	 void setMarca(const char* marca) {
		 if (this->marca != nullptr) {
			 delete[] this->marca;
			 this->marca = nullptr;
		 }
		 this->marca = new char[strlen(marca) + 1];
		 strcpy_s(this->marca, strlen(marca) + 1, marca);
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
	if (tipRemorca != nullptr) {
		delete[] tipRemorca;
		tipRemorca = nullptr;
	}
}




int main() {
	
	



	return 0;

}