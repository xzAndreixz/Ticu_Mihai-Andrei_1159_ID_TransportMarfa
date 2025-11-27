#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


using namespace std;

class Laptop {

public:

	Laptop() : id(++nrLaptopuri) {

		this->pret = 0;
		this->model = nullptr;
		this->stocare = 0;
		this->tip = "Nu este declarat";
	}

	Laptop(float pret, const char* model, float stocare, string tip) : id(++nrLaptopuri) {

		this->pret = pret;
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
		this->stocare = stocare;
		this->tip = tip;
	}

	float getPret() {
		return this->pret;
	}
	char* getModel() {
		return this->model;
	}
	float getStocare() {
		return this->stocare;
	}
	string getTip() {
		return this->tip;
	}

	void setPret(float pret) {
		this->pret = pret;
	}
	void setModel(const char* model) {
		if (this->model != nullptr) {
			delete[] this->model;
			this->model = nullptr;
		}
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}
	void setTip(string tip) {
		this->tip = tip;
	}
	void setStocare(float stocare) {
		this->stocare = stocare;
	}

	void afisareObiect() {
		cout << "ID: " << this->id;
		cout << endl;
		if (this->pret)
			cout << "Pret: " << this->pret;
		else
			cout << "Pret: Nu este declarat";
		cout << endl;
		if (this->model)
			cout << "Model: " << this->model;
		else
			cout << "Model: Nu este declarat";
		cout << endl;

		if (this->stocare)
			if(this->stocare<1000)
			cout << "Stocare: " << this->stocare <<" GB";
			else
				cout << "Stocare: " << this->stocare/1000 << " TB";
		else
			cout << "Stocare: Nu este declarat";
		cout << endl;
		cout << "Tip: " << this->tip;
		cout << endl;
		cout << endl;


	}

	

		//------------- OPERATORII -------------------------
	Laptop& operator=(const Laptop& egal) {
		if (this != &egal) {
			if (this->model != nullptr) {
				delete[] this->model;
				this->model = nullptr;
			}
			this->pret = egal.pret;
			this->model = new char[strlen(egal.model) + 1];
			strcpy_s(this->model, strlen(egal.model) + 1, egal.model);
			this->stocare = egal.stocare;
			this->tip = egal.tip;
		}
		return *this;
	}
	
	bool operator<(const Laptop& maiMic) {
		return this->stocare < maiMic.stocare;
	}
	bool operator>(const Laptop& maiMare)const {
		return this->stocare > maiMare.stocare;
	}
	Laptop& operator+=(int x) {
		this->pret += x;
		return *this;
	}
	void operator-=(float x) {
		this->pret -= x;
	}

	Laptop& operator++() {
		 ++this->pret;
		 return *this;
	}
	//sau 
	int operator--() {
		return ++this->pret;
	}

	bool operator<=(const Laptop& comp) {
		return this->stocare <= comp.stocare;
	}
	bool operator!=(const Laptop& comp) {
		return this->stocare != comp.stocare;
	}
	bool operator==(const Laptop& comp) {
		return this->stocare == comp.stocare;
	}

	char& operator[](int index) {

		return this->model[index];
	}
	void operator()(float x) {
		this->pret += x;
	}

	friend ostream& operator<<(ostream& out, const Laptop& l) {
		out << "ID: " << l.id << endl;
		out << "Pret: " << l.id << endl;
	}

	//--------------------- OPERATORII -------------------

	Laptop(const Laptop& copie) : id(++nrLaptopuri) {
		this->pret = copie.pret;
		if (this->model != nullptr) {
			delete[] this->model;
			this->model = nullptr;
		}
		this->model = new char[strlen(copie.model) + 1];
		strcpy(this->model, copie.model);
		this->stocare = copie.stocare;
		this->tip = copie.tip;

	}


private:
	const int id;
	float pret;
	char* model;
	float stocare;
	string tip;

	static int nrLaptopuri;

};
int Laptop::nrLaptopuri = 0;

int main() {

	Laptop l1(5000, "Acer", 750, "Gaming");
	l1.afisareObiect();
	Laptop l2;
	l2.setModel("Asus");
	l2.setPret(5499.99);
	l2.setStocare(2000);
	l2.setTip("Gaming");
	l2.afisareObiect();

	if (l2 < l1)
		l1.afisareObiect();
	else
		l2.afisareObiect();
	
	l2 += 1000;
	l2.afisareObiect();
	l2 -= 499.99;
	l2.afisareObiect();

	++l2;
	l2.afisareObiect();
	l2(200);
	l2.afisareObiect();

	return 0;
}
