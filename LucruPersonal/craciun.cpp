
#include <iostream>
#include <string>

using namespace std;

class Craciun {
protected:
	string oras;
	double buget;
	int nrCadouri;
	bool areTarg;
public:

	//Constructori!
	Craciun() {
		this->oras = "Nedeclarat";
		this->buget = 0;
		this->nrCadouri = 0;
		areTarg = 0;
	}
	Craciun(string oras, double buget, int nrCadouri, bool areTarg) {
		this->oras = oras;
		this->buget = buget;
		this->nrCadouri = nrCadouri;
		this->areTarg = areTarg;

	}
	Craciun(const Craciun& copie) {
		this->oras = copie.oras;
		this->buget = copie.buget;
		this->nrCadouri = copie.nrCadouri;
		this->areTarg = copie.areTarg;
	}
	
	Craciun& operator=(const Craciun& egal) {
		if (this != &egal) {
			this->oras = egal.oras;
			this->buget = egal.buget;
			this->nrCadouri = egal.nrCadouri;
			this->areTarg = egal.areTarg;
		}
		return *this;
	}

	//get-eri si set-eri
	string getOras() {
		return this->oras;
	}
	double getBuget() {
		return this->buget;
	}
	int getNrCadouri() {
		return this->nrCadouri;
	}
	/*const string getAreTarg() {   //o incercare de returnare, depinde cum vreo sa o folosim
		if (this->areTarg)
			return "Are targ";
		else
			return "Nu are";
	}*/
	bool getAreTarg() {
		return this->areTarg;
	}
	void setOras(string oras) {
		this->oras = oras;
	}
	void setBuget(double buget) {
		this->buget = buget;
	}
	void setNrCadouri(int nrCadouri) {
		this->nrCadouri = nrCadouri;
	}
	void setAreTarg(bool x) {
		this->areTarg = x;
	}

	void afisare() {
		if (this->areTarg) {
			cout << "\nOras: " << this->oras;
			cout << "\nBuget: " << this->buget;
			cout << "\nNr. cadouri: " << this->nrCadouri;
		}
		else {
			cout << "\nOrasul nu are targ de Craciun";
		}
	}

};

class CraciunCraiova : public Craciun {
private:
	int nrInstalatiiLuminoase;
	bool mergLaTarg;
public:
	CraciunCraiova() : Craciun("Craiova", 0, 0, 0), nrInstalatiiLuminoase(0), mergLaTarg(0){}
	CraciunCraiova(double buget, int nrCadouri, int nrInstalatiiLuminoase, bool mergLaTarg) : Craciun("Craiova", buget, nrCadouri, 1) {
		this->nrInstalatiiLuminoase = nrInstalatiiLuminoase;
		this->mergLaTarg = mergLaTarg;
	}

	int getNrInstalatiiLuminoase() {
		return this->nrInstalatiiLuminoase;
	}

	bool getMergLaTarg() {
		return this->mergLaTarg;
	}

	void afisare() {
		Craciun::afisare();
		if (this->mergLaTarg) {
			cout << "\nNr. de instalatii de Craciun: " << this->nrInstalatiiLuminoase;
		}
		else {
			cout << "\nNu merg la targ";
		}
	}


};


int main() {

	Craciun c1;
	c1.afisare();
	cout << endl;
	Craciun c2("Bucuresti", 2000, 12, 1);
	c2.afisare();
	

	cout << endl << endl;
	CraciunCraiova craiova(1500, 10, 7, 1);


	return 0;
}
