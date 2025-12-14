#include <iostream>
#include <string>

using namespace std;

class cadou {

private:
	string denumire;
	float pret;
	float greutate;
public:
	string getDenumire() {
		return this->denumire;
	}
	float getPret() {
		return this->pret;
	}
	float getGreutate() {
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

	friend ostream& operator<<(ostream& out, const cadou& c) {
		if (c.pret > 0) {
			out << "Cadou: " << c.denumire << endl;
			out << "Pret minim: " << c.pret << " lei" << endl;
			out << "Greutate: " << c.greutate << " kg" << endl;
		}
		else {
			out << "Cadoul nu este initializat!";
		}
		return out;

	}
};


int main() {

	cadou c1;
	cadou c2("Omnitrix", 149.5, 0.2);
	cout << c1 << endl << c2;

	return 0;
}
