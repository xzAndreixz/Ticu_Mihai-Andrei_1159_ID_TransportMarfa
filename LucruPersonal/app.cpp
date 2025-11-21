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


	return 0;
}
