
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



};


int main() {


	return 0;
}