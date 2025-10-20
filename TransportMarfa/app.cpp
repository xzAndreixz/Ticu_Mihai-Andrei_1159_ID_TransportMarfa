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

	//declar unele variabile nu doar cele cu "static" folosind lista de initializare a constructorului!!!
	Remorca() : nrAxe(2), tipRemorca("Prelata"), capacitate(new float(40.0f)), franaProprie(true) {
		nrRemorci++;

	}
};
int Remorca::nrRemorci = 0;

int transmiterePrinPointer(int a, int b,int* s) {
	*s = a + b;
	return *s;
}

void afisare(int parametru) {
	cout << "Valoarea afisata este: " << parametru;
}

void sumaPrinRefereinta(int a, int b, int& s2) {
	s2 = a + b;
}

void inmultesteValoare(float* valoare, int deCateOri) {
	for (int i = 0; i < deCateOri; i++)
		(*valoare) = (*valoare) * 2;
	cout << "Valoarea noua este: " << *valoare;
}

void dubleaza(float** valoare) {
	(**valoare) = (**valoare) * (**valoare);
	cout << "Valoarea dubla este: " << **valoare;
}

int main() {

	int s = 0, s2 = 0, a = 10;
	float b=56.0;

	cout <<"\nSuma este:"<< transmiterePrinPointer(5, 7, &s);  //am pus &s fiindca functia asteapta o adresa
	cout << endl;
	afisare(a);
	cout << endl;
	sumaPrinRefereinta(15, 21, s2);
	cout << endl;
	afisare(s2);
	cout << endl;

	//daca ai valori alocate dinamic?

	float* p;

	p = new float; //am alocat mem. in heap :)
	delete p;  //eliberam memoria cand nu mai folosim
	p = &b; //aici am retinut adresa lui b ...am eliberat mai sus fiindca daca retineam pentru b si nu elibeream cream un leak(mem. blocata)
			//asadar acea memorie rezervata cu "new float" am eliberato cu delete.
	cout <<"Adresa este:"<<p<<", dar valoarea este: "<<*p;
	cout << endl;
	float val = 5;
	inmultesteValoare(&val, 3);  //functia inmulteste cu 2 si modifica var. globara de cate ori ii dai ca parametru prin int
	//sa folosim si *
	cout << endl;
	inmultesteValoare(p, 3);
	cout << endl;
	dubleaza(&p);  //aici folosesc ** unde prima * dereferentiaza catre valoarea din p adica adresa lui b si a doua steluta dereferentiaza pentru a afla valoarea lui b


	//si astfel am exersat si inteles cele 3 tipuri prin care poti trimite o variabila in C++: valoare, pointer, referinta

	
	cout << b;
	return 0;

}