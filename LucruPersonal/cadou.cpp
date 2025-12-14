#include <iostream>
#include <string>

using namespace std;

class cadou {

private:
	string denumire;
	float pret;
	float greutate;
public:
	string getDenumire() const{
		return this->denumire;
	}
	float getPret() const{
		return this->pret;
	}
	float getGreutate() const{
		return this->greutate;
	}

	void setDenumire(string denumire) {
		this->denumire = denumire;
	}
	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
		else {
			cout << "Pretul trebuie sa fie pozitiv!";
		}
	}
	void setGreutate(float greutate) {
		if(greutate>0)
		{
			this->greutate = greutate;
		}
		else {
			cout << "Greutatea trebuie sa fie pozitiva!";
		}
	}
	cadou() {
		this->denumire = "Nespecificat";
		this->pret = 0;
		this->greutate = 0;
	}

	cadou(string denumire, float pret, float greutate) {
		this->denumire = denumire;
		this->pret = pret;
		this->greutate = greutate;
	}


	virtual void afisare() const {
		if (pret > 0) {
			cout << "Cadou: " << denumire << endl;
			cout << "Pret minim: " << pret << " lei" << endl;
			cout << "Greutate: " << greutate << " kg" << endl;
		}
		else {
			cout << "Cadoul nu este initializat!" << endl;
		}
	}


};

class Romania : public cadou {
private:
	double taxa;

public:
	Romania(string denumire, float pret, float greutate)
		: cadou(denumire, pret, greutate), taxa(15.0) {
	}

	float calculeazaPretFinal() const {
		float p = getPret();
		return p + p * taxa / 100;
	}


	void afisare() const override {
		cadou::afisare();
		cout << "Tara: Romania" << endl;
		cout << "Taxa introducere: " << taxa << "%" << endl;
		cout << "Pret final: " << calculeazaPretFinal() << " lei" << endl;
	}



};




int main() {

	cadou c("Omnitirx", 100, 0.2);
	Romania r("Omnitrix RO", 100, 0.2);

	c.afisare();
	cout << endl;
	r.afisare();
	

	return 0;
}
