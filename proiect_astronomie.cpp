#include<iostream>
#include<string>
using namespace std;
//DOMENIUL ASTRONOMIE
class Planeta 
{
private:
	const int id;
	static int numarPlanete;
	string nume;
	float diametru;
	int numarTari;
    string* denumireTari;
public:

	Planeta():id(1) 
	{
		this->nume = "NoName";
		this->diametru = 0;
		this->numarTari = 0;
		this->denumireTari = NULL;
    }
	
    Planeta(int id, string nume, float diametru, int numarTari, string* denumireTari) : id(id), nume(nume), diametru(diametru), numarTari(numarTari)
	{
		if (numarTari != 0)
		{
			this->denumireTari = new string[numarTari];
			for (int i = 0;i < numarTari; i++)
			{
				this->denumireTari[i] = denumireTari[i];
			}
		}
		else
		{
			this->denumireTari = NULL;
		}
	}
	
	Planeta(int id, string nume, float diametru) :id(id)
	{
		this->nume = nume;
		this->diametru = diametru;
		this->numarTari = 0;
		this->denumireTari = NULL;
	}

	Planeta(const Planeta& planeta) : id(planeta.id)
	{
		this->nume = planeta.nume;
		this->diametru = planeta.diametru;
		this->numarTari = planeta.numarTari;
		if (numarTari != 0)
		{
			this->denumireTari = new string[numarTari];
			for (int i = 0;i < numarTari;i++)
			{
				this->denumireTari[i] = planeta.denumireTari[i];
			}
		}
		else
		{
			this->denumireTari = NULL;
		}
	}

	Planeta operator=(const Planeta& planeta)
	{
		if (this != &planeta)
		{
			this->nume = planeta.nume;
			this->diametru = planeta.diametru;
			this->numarTari = planeta.numarTari;
			if (this->denumireTari != NULL)
			{
				delete[]this->denumireTari;
			}
			if (numarTari != 0)
			{
				this->denumireTari = new string[numarTari];
				for (int i = 0;i < numarTari;i++)
				{
					this->denumireTari[i] = planeta.denumireTari[i];
				}
			}
			else
			{
				this->denumireTari = NULL;
			}
		}
		return *this;
	}

	~Planeta() 
	{
		if (this->denumireTari != NULL)
		{
			delete[]this->denumireTari;
		}
	}

	/*void afisarePlaneta()
	{
	cout << "Planeta " << nume << " are id-ul "<<id<<", diametrul de " << diametru << " si " << numarTari << " tari."<<endl;
	cout <<"Cateva tari ar fi: ";
	if (numarTari == 0)
	{
		cout << "Nicio tara.";
	}
	else 
	{

		for (int i = 0;i < numarTari;i++)
		{
			cout << denumireTari[i] << ", ";

		}
	}
	cout << endl;
	}*/

	static int getNumarPlanete()
	{
		return Planeta::numarPlanete;
	}

	static void setNumarPlanete(int numar)
	{
		if (numar > 0)
		{
			Planeta::numarPlanete = numar;
		}
	}

	void setNume(string nume)
	{
		if (nume.length() > 3)
		{
			this->nume = nume;
		}
	}

	string getNume() 
	const{
		return this->nume;
	}

	const int getId()
	const{
		return this->id;
	}

	void setDiametru(float diametru)
	{
		if (diametru > 0)
		{
			this->diametru = diametru;
		}
	}
	
	float getDiametru()
	{
		return this->diametru;
	}

	void setTari(int numarTari, string* denumire)
	{
		if (numarTari > 0)
		{
			this->numarTari = numarTari;
			if (this->denumireTari != NULL)
			{
				delete[]this->denumireTari;
			}
			this->denumireTari = new string[numarTari];
			for (int i = 0;i < numarTari;i++)
			{
				this->denumireTari[i] = denumire[i];
			}
		}
	}

	string* getDenumiriTari()
	{
		return this->denumireTari;
	}
	
	string getDenumireTara(int index)
	{
		if (index >= 0 && index < this->numarTari)
		{
			return this->denumireTari[index];
		}
	}

	friend float getVolum(const Planeta& planeta);
	friend string getSirTari(const Planeta& planeta);

	Planeta operator+(const Planeta& planeta)
	{
		Planeta aux = *this;
		aux.numarTari = this->numarTari + planeta.numarTari;
		if (aux.denumireTari != NULL)
		{
			delete[]aux.denumireTari;
		}
		if (aux.numarTari > 0)
		{
			aux.denumireTari = new string[aux.numarTari];
			for (int i = 0;i < this->numarTari;i++)
			{
				aux.denumireTari[i] = denumireTari[i];
			}
			for (int i = this->numarTari;i < aux.numarTari;i++)
			{
				aux.denumireTari[i] = planeta.denumireTari[i - numarTari];
			}
		}
		else
		{
			aux.denumireTari = NULL;
		}
		return aux;
	}

	Planeta& operator++()
	{
	    this->diametru++;
		return *this;
	}

	Planeta operator++(int)
	{
		Planeta copie = *this;
		this->diametru++;
		return copie;
	}

	friend ostream& operator<<(ostream& vizualizare, const Planeta& planeta);
	friend istream& operator>>(istream& citire, Planeta& planeta)
	{
		cout << "Planeta: ";
		citire >> planeta.nume;
		cout << "are diametrul de: ";
		cin >> planeta.diametru;
		cout << "Pe aceasta planeta se regasesc tari in numar de: ";
		citire >> planeta.numarTari;
		if (planeta.denumireTari != NULL)
		{
			delete[]planeta.denumireTari;
		}
		if (planeta.numarTari > 0)
		{
			planeta.denumireTari = new string[planeta.numarTari];
			for (int i = 0;i < planeta.numarTari;i++)
			{
				cout << "Cateva tari ar fi " << i + 1 << ":";
				citire >> planeta.denumireTari[i];
			}
		}
		else
		{
			cout << "Nicio tara." << endl;
			planeta.denumireTari = NULL;
		}
		return citire;
	}
};

int Planeta::numarPlanete = 9;

float getVolum(const Planeta& planeta)
{
	//volumul planetei folosind formula sferei
	float raza = planeta.diametru / 2;
	return (4.0 / 3.0) * 3.14159 * raza * raza * raza;
}

string getSirTari(const Planeta& planeta)
{
	string aux = "";
	for (int i = 0;i < planeta.numarTari;i++)
	{
		aux += planeta.denumireTari[i] + ",";
	}
	return aux;
}

ostream& operator<<(ostream& vizualizare, const Planeta& planeta)
{
	vizualizare << "Planeta " << planeta.getNume() << " are id-ul " << planeta.getId() << ", diametrul de " << planeta.diametru << " si " << planeta.numarTari << " tari." << endl;
	vizualizare << "Cateva tari ar fi: ";
	if (planeta.numarTari == 0)
	{
		vizualizare << "Nicio tara.";
	}
	else
	{

		for (int i = 0;i < planeta.numarTari;i++)
		{
			vizualizare << planeta.denumireTari[i] << ", ";

		}
	}
	vizualizare << endl;
	return vizualizare;
}


class Stea
{
private:
	const int id;
	static int numarStele;
	string nume;
	float temperatura;
	float raza;
	int numarElemente;
	string* compozitie; 
public:

	Stea() : id(1)
	{
		this->nume = "NoName";
		this->temperatura = 0.0;
		this->raza = 0.0;
		this->compozitie = NULL;
	}

	Stea(int id, string nume, float temperatura, float raza, int numarElemente, string* compozitie): id(id), nume(nume), temperatura(temperatura), raza(raza), numarElemente(numarElemente)
	{
		if (numarElemente != 0)
		{
			this->compozitie = new string[numarElemente];
			for (int i = 0; i < numarElemente; i++)
			{
				this->compozitie[i] = compozitie[i];
			}
		}
		else
		{
			this->compozitie = NULL;
		}
	}

	Stea(int id, string nume, float temperatura) :id(id)
	{
		this->nume = nume;
		this->temperatura = temperatura;
		this->raza = 473080000;
		this->numarElemente = 0;
		this->compozitie = NULL;
	}

	Stea(const Stea& stea) : id(stea.id)
	{
		this->nume = stea.nume;
		this->temperatura = stea.temperatura;
		this->raza = stea.raza;
		this->numarElemente = stea.numarElemente;
		if (numarElemente != 0)
		{
			this->compozitie = new string[numarElemente];
			for (int i = 0;i < numarElemente;i++)
			{
				this->compozitie[i] = stea.compozitie[i];
			}
		}
		else
		{
			this->compozitie = NULL;
		}
	}

	Stea operator=(const Stea& stea)
	{
		if (this != &stea)
		{
			this->nume = stea.nume;
			this->temperatura = stea.temperatura;
			this->raza = stea.raza;
      		this->numarElemente = stea.numarElemente;
			if (this->compozitie != NULL)
			{
				delete[]this->compozitie;
			}
			if (numarElemente != 0)
			{
				this->compozitie = new string[numarElemente];
				for (int i = 0;i < numarElemente;i++)
				{
					this->compozitie[i] = stea.compozitie[i];
				}
			}
			else
			{
				this->compozitie = NULL;
			}
		}
		return *this;
	}

	~Stea()
	{
		if (this->compozitie != NULL)
		{
			delete[]this->compozitie;
		}
	}

	/*void afisareStea()
	{
		cout << "Steaua " << nume << " are id-ul " << id << ", temperatura de " << temperatura << " Kelvin si o raza de " << raza << " unitati solare." << endl;
		cout << "Compozitia stelei include: ";
		if (compozitie == NULL)
		{
			cout << "Nicio informatie despre compozitie.";
		}
		else
		{
			for (int i = 0; i < numarElemente; i++)
			{
				cout << compozitie[i] << ", ";
			}
		}
		cout << endl;
	}*/

	static int getNumarStele()
	{
		return Stea::numarStele;
	}

	static void setNumarStele(int numar)
	{
		if (numar > 0)
		{
			Stea::numarStele = numar;
		}
	}

	void setNume(string nume)
	{
		if (nume.length() > 3)
		{
			this->nume = nume;
		}
	}

	string getNume()
	const {
		return this->nume;
	}

	const int getId()
	const {
		return this->id;
	}

	void setTemperatura(float temperatura)
	{
		if (temperatura > 0.0)
		{
			this->temperatura = temperatura;
		}
	}

	float getTemperatura()
	{
		return this->temperatura;
	}

	void setRaza(float raza)
	{
		if (raza > 0.0)
		{
			this->raza = raza;
		}
	}

	float getRaza()
	{
		return this->raza;
	}

	void setElemente(int numarElemente, string* comp)
	{
		if (numarElemente > 0)
		{
			this->numarElemente = numarElemente;
			if (this->compozitie != NULL)
			{
				delete[]this->compozitie;
			}
			this->compozitie = new string[numarElemente];
			for (int i = 0;i < numarElemente;i++)
			{
				this->compozitie[i] = comp[i];
			}
		}
	}

	string* getCompozitie()
	{
		return this->compozitie;
	}

	string getCompozitie(int index)
	{
		if (index >= 0 && index < this->numarElemente)
		{
			return this->compozitie[index];
		}
	}

    friend float getLuminozitate(const Stea& stea);
	friend string getSirElemente(const Stea& stea);

	string& operator[](int pozitie)   
	{
		if (pozitie >= 0 && pozitie < this->numarElemente)
		{
			return this->compozitie[pozitie];
		}
		else throw 404;
	}

	Stea* operator->()
	{
		this->raza = 17671000;
		return this;
	}

	friend ostream& operator<<(ostream& vizualizare, const Stea& stea);
	friend istream& operator>>(istream& citire, Stea& stea)
	{
		cout << "Steaua: ";
		citire >> stea.nume;
		cout << "are temperatura de: ";
		citire >> stea.temperatura;
		cout << "si o raza de: ";
		citire >> stea.raza;
		cout << " In compozitia ei se afla elemente in numar de: ";
		citire >> stea.numarElemente;
		if (stea.compozitie != NULL)
		{
			delete[]stea.compozitie;
		}
		if (stea.numarElemente > 0)
		{
			stea.compozitie = new string[stea.numarElemente];
			for (int i = 0;i < stea.numarElemente;i++)
			{
				cout << "Cateva elemente ar fi " << i + 1 << ":";
				citire >> stea.compozitie[i];
			}
		}
		else
		{
			cout << "Niciun element in compozitie." << endl;
			stea.compozitie = NULL;
		}
		return citire;
	}

	friend class Constelatie;
};

int Stea::numarStele = 0;

float getLuminozitate(const Stea& stea)
{
	//luminozitatea unei stele
	return 4 * 3.14159 * stea.raza * stea.raza * stea.temperatura * stea.temperatura * stea.temperatura;
}

string getSirElemente(const Stea& stea)
{
	string aux = "";
	for (int i = 0;i < stea.numarElemente;i++)
	{
		aux += stea.compozitie[i] + ",";
	}
	return aux;
}

ostream& operator<<(ostream& vizualizare, const Stea& stea)
{
	vizualizare << "Steaua " << stea.getNume() << " are id-ul " << stea.getId() << ", temperatura de " << stea.temperatura << " Kelvin si o raza de " << stea.raza << " unitati solare." << "In compozitia stelei se regasesc "<<stea.numarElemente<<" elemente."<<endl;
	vizualizare << "Cateva elemente ar fi: ";
	if (stea.numarElemente == 0)
	{
		vizualizare << "Niciun element.";
	}
	else
	{

		for (int i = 0;i < stea.numarElemente-1;i++)
		{
			vizualizare << stea.compozitie[i] << ", ";
		}
		vizualizare << stea.compozitie[stea.numarElemente - 1];
	}
	vizualizare << endl;
	return vizualizare;
}

//relatie de "has a" cu clasa stea
class Constelatie {
private:
	const int idConstelatie;
	string denumire;
	int varstaConstelatie;
	float distanta;
	int nrStele;
	Stea* stele;
public:
	
	Constelatie(): idConstelatie(1)
	{
		this->denumire = "NoName";
		this->varstaConstelatie = 0;
		this->distanta = 0.0;
		this->nrStele = 0;
		this->stele = NULL;
	}

	Constelatie(int id, string nume, int varsta, float distanta, int nr, Stea* stele) : idConstelatie(id), denumire(nume), varstaConstelatie(varsta), distanta(distanta), nrStele(nr)
	{
		if (this->nrStele != 0)
		{
			this->stele = new Stea[this->nrStele];
			for (int i = 0; i < this->nrStele; i++)
			{
				this->stele[i] = stele[i];
			}
		}
		else
		{
			this->stele = NULL;
		}
	}


	Constelatie(const Constelatie& constelatie): idConstelatie(constelatie.idConstelatie)
	{
		this->denumire = constelatie.denumire;
		this->varstaConstelatie = constelatie.varstaConstelatie;
		this->distanta = constelatie.distanta;
		this->nrStele = constelatie.nrStele;
		if (nrStele != 0)
		{
			this->stele = new Stea[nrStele];
			for (int i = 0;i < nrStele;i++)
			{
				this->stele[i] = constelatie.stele[i];
			}
		}
		else
		{
			this->stele = NULL;
		}
	}

	~Constelatie()
	{
		if (this->stele != NULL)
		{
			delete[]this->stele;
		}
	}

	const int getIdConstelatie()
	{
		return this->idConstelatie;
	}

	void setDenumire(string denumire)
	{
		if (denumire.length() > 3)
		{
			this->denumire = denumire;
		}
	}

	string getDenumire()
    {
		return this->denumire;
	}

	void setVarstaConstelatie(int varsta)
	{
		if (varsta > 0)
		{
			this->varstaConstelatie = varsta;
		}
	}

	int getVarstaConstelatie()
	{
		return this->varstaConstelatie;
	}

	void setDistanta(float distanta)
	{
		if (distanta > 0.0)
		{
			this->distanta = distanta;
		}
	}

	float getDistanta()
	{
		return this->distanta;
	}

	void setStele(int nrStele, Stea* stele)
	{
		if (nrStele > 0)
		{
			this->nrStele = nrStele;
			if (this->stele != NULL)
			{
				delete[]this->stele;
			}
			this->stele = new Stea[nrStele];
			for (int i = 0;i < nrStele;i++)
			{
				this->stele[i] = stele[i];
			}
		}
	}

	Stea* getStele()
	{
		return this->stele;
	}


	Constelatie operator+=(const Constelatie& constelatie)
	{
		int aux = this->nrStele;
		this->nrStele += constelatie.nrStele;
		Stea* vector = new Stea[this->nrStele];
		for (int i = 0;i < aux;i++)
		{
			vector[i] = this->stele[i];
		}
		for (int i = aux;i < this->nrStele;i++)
		{
			vector[i] = constelatie.stele[i - aux];
		}
		if (this->stele != NULL)
		{
			delete[]this->stele;
		}
		this->stele = vector;
		return *this;
	}


    bool operator==(const Constelatie& altaConstelatie)
	const{
		return this->nrStele == altaConstelatie.nrStele;

	}
	
	friend ostream& operator<<(ostream& vizualizare, const Constelatie& constelatie);

};

ostream& operator<<(ostream& vizualizare, const Constelatie& constelatie)
{
	vizualizare << "Constelatia " << constelatie.denumire <<" cu id-ul "<< constelatie.idConstelatie << " are varsta de " << constelatie.varstaConstelatie << " miliarde de ani si o distanta de " << constelatie.distanta << " ani lumina." << "In aceasta constelatie se regasesc " << constelatie.nrStele << " stele." << endl;
	vizualizare << "Cateva stele ar fi: ";
	if (constelatie.nrStele == 0)
	{
		vizualizare << "Nicio stea.";
	}
	else
	{

		for (int i = 0;i < constelatie.nrStele;i++)
		{
			vizualizare << constelatie.stele[i] << endl;

		}
	}
	vizualizare << endl;
	return vizualizare;
}

class Galaxie
{
private:
	const int id;
	static int numarGalaxii;
	string nume;
	int numarTipuriStele;
	string* denumireTipuriStele;
public:

	Galaxie() : id(1)
	{
		this->nume = "NoName";
		this->numarTipuriStele = 0;
		this->denumireTipuriStele = NULL;
	}

	Galaxie(int id, string nume, int numarTipuriStele, string* denumireTipuriStele): id(id), nume(nume), numarTipuriStele(numarTipuriStele)
	{
		if (numarTipuriStele != 0)
		{
			this->denumireTipuriStele = new string[numarTipuriStele];
			for (int i = 0; i < numarTipuriStele; i++)
			{
				this->denumireTipuriStele[i] = denumireTipuriStele[i];
			}
		}
		else
		{
			this->denumireTipuriStele = NULL;
		}
	}

	Galaxie(int id, string nume) :id(id)
	{
		this->nume = nume;
		this->numarTipuriStele = 0;
		this->denumireTipuriStele = NULL;
	}

	Galaxie(const Galaxie& galaxie) : id(galaxie.id)
	{
		this->nume = galaxie.nume;
		this->numarTipuriStele = galaxie.numarTipuriStele;
		if (numarTipuriStele != 0)
		{
			this->denumireTipuriStele = new string[numarTipuriStele];
			for (int i = 0;i < numarTipuriStele;i++)
			{
				this->denumireTipuriStele[i] = galaxie.denumireTipuriStele[i];
			}
		}
		else
		{
			this->denumireTipuriStele = NULL;
		}
	}

	Galaxie operator=(const Galaxie& galaxie)
	{
		if (this != &galaxie)
		{
			this->nume = galaxie.nume;
			this->numarTipuriStele = galaxie.numarTipuriStele;
			if (this->denumireTipuriStele != NULL)
			{
				delete[]this->denumireTipuriStele;
			}
			if (numarTipuriStele != 0)
			{
				this->denumireTipuriStele = new string[numarTipuriStele];
				for (int i = 0;i < numarTipuriStele;i++)
				{
					this->denumireTipuriStele[i] = galaxie.denumireTipuriStele[i];
				}
			}
			else
			{
				this->denumireTipuriStele = NULL;
			}
		}
		return *this;
	}

	~Galaxie()
	{
		if (this->denumireTipuriStele != NULL)
		{
			delete[]this->denumireTipuriStele;
		}
	}

	/*void afisareGalaxie()
	{
		cout << "Galaxia " << nume << " are id-ul " << id << " si contine " << numarTipuriStele << " stele." << endl;
		cout << "Denumirile tipurilor de stele din galaxie sunt: ";
		if (denumireTipuriStele == NULL)
		{
			cout << "Nicio informatie despre tipurile de stele.";
		}
		else
		{
			for (int i = 0; i < numarTipuriStele; i++)
			{
				cout << denumireTipuriStele[i] << ", ";
			}
		}
		cout << endl;
	}*/

	static int getNumarGalaxii()
	{
		return Galaxie::numarGalaxii;
	}

	static void setNumarGalaxii(int numar)
	{
		if (numar > 0)
		{
			Galaxie::numarGalaxii = numar;
		}
	}

	void setNume(string nume)
	{
		if (nume.length() > 3)
		{
			this->nume = nume;
		}
	}

	string getNume()
	const {
		return this->nume;
	}

	const int getId()
	const {
		return this->id;
	}

	void setTipuriStele(int numarTipuriStele, string* denumire)
	{
		if (numarTipuriStele > 0)
		{
			this->numarTipuriStele = numarTipuriStele;
			if (this->denumireTipuriStele != NULL)
			{
				delete[]this->denumireTipuriStele;
			}
			this->denumireTipuriStele = new string[numarTipuriStele];
			for (int i = 0;i < numarTipuriStele;i++)
			{
				this->denumireTipuriStele[i] = denumire[i];
			}
		}
	}

	string* getDenumiriTipuriStele()
	{
		return this->denumireTipuriStele;
	}

	string getDenumireTipStea(int index)
	{
		if (index >= 0 && index < this->numarTipuriStele)
		{
			return this->denumireTipuriStele[index];
		}
	}

	friend long getMasaTotala(const Galaxie& galaxie);
	friend string getSirTipuriStele(const Galaxie& galexie);

	friend ostream& operator<<(ostream& vizualizare, const Galaxie& galaxie);
	friend istream& operator>>(istream& citire, Galaxie& galaxie)
	{
		cout << "Galaxia: ";
		citire >> galaxie.nume;
		cout << "are un numar de tipuri de stele: ";
		citire >> galaxie.numarTipuriStele;
		if (galaxie.denumireTipuriStele != NULL)
		{
			delete[]galaxie.denumireTipuriStele;
		}
		if (galaxie.numarTipuriStele > 0)
		{
			galaxie.denumireTipuriStele = new string[galaxie.numarTipuriStele];
			for (int i = 0;i < galaxie.numarTipuriStele;i++)
			{
				cout << "Cateva tipuri de stele ar fi " << i + 1 << ":";
				citire >> galaxie.denumireTipuriStele[i];
			}
		}
		else
		{
			cout << "Niciun tip de stea." << endl;
			galaxie.denumireTipuriStele = NULL;
		}
		return citire;
	}

	bool operator!=(const Galaxie& altaGalaxie)
	const{
		return this->numarTipuriStele != altaGalaxie.numarTipuriStele;

	}
};

int Galaxie::numarGalaxii = 0;

long getMasaTotala(const Galaxie& galaxie)
{
	//masa totala a galaxiei
	return galaxie.numarTipuriStele * 2e30; // Presupunem o masa medie a unei stele de 2e30 kg
}

string getSirTipuriStele(const Galaxie& galaxie)
{
	string aux = "";
	for (int i = 0;i < galaxie.numarTipuriStele;i++)
	{
		aux += galaxie.denumireTipuriStele[i] + ",";
	}
	return aux;
}

ostream& operator<<(ostream& vizualizare, const Galaxie& galaxie)
{
	vizualizare << "Galaxia " << galaxie.getNume() << " are id-ul " << galaxie.getId() << " si contine " << galaxie.numarTipuriStele << " stele." << endl;
	vizualizare << "Cateva tipuri de stele ar fi: ";
	if (galaxie.numarTipuriStele == 0)
	{
		vizualizare << "Niciun tip de stele.";
	}
	else
	{

		for (int i = 0;i < galaxie.numarTipuriStele;i++)
		{
			vizualizare << galaxie.denumireTipuriStele[i] << ", ";

		}
	}
	vizualizare << endl;
	return vizualizare;
}

void main()
{
	//Planeta planeta1;
	//cout<<planeta1;

	//string* denumireTari = new string[4];
	//denumireTari[0] = "Islanda";
	//denumireTari[1] = "Elvetia";
	//denumireTari[2] = "Turcia";
	//denumireTari[3] = "Norvegia";
	//Planeta planeta2(2, "Pamant", 12742, 4, denumireTari);
	//cout<<planeta2;
	//
	//Planeta planeta3(3, "Marte", 6779);
	//cout << planeta3;

	//cout << "Numarul total de planete: " << Planeta::getNumarPlanete() << endl;

	//cout << "Volumul planetei Marte: " << getVolum(planeta3) << " unitati cubice." << endl;


	//Planeta planeta01(planeta1);
	//cout<<planeta1;
	//cout << endl;
 //   
	//planeta3 = planeta3;
	//cout<<planeta3;

	//planeta01.setNume("Mercur");
	//cout << planeta01.getNume() << endl;

	//cout << planeta01.getId() << endl;

	//planeta01.setDiametru(4879.4);
	//cout << planeta01.getDiametru() << endl;

	//string* tari = new string[3]{ "Calidora", "Heliospica", "Mercuria" }; //acestea sunt denumiri fictive
	//planeta01.setTari(3, tari);
	//cout << planeta01 << endl;

	//cout << "Un prim exemplu de tara ar fi: " << planeta01.getDenumiriTari()[0] << endl;
	//cout << "Un alt exemplu de tara ar fi: "<< planeta01.getDenumireTara(2) << endl;
	//
	//Planeta planeta02;
	//planeta1 = planeta01 + planeta02;
	//cout<<planeta1;

	//
 //   cout << "Forma initiala a planetei Mercur: " << planeta01 << endl;
 //   Planeta planeta4;
	//planeta4 = ++planeta01;
	//cout << "Forma planetei Mercur dupa preincrementare: " << planeta4 << endl;
	//Planeta planeta5;
	//planeta5 = planeta01++;
	//cout << "Forma planetei Mercur dupa postincrementare: " << planeta5 << endl;

 //   cout << "Sirul tarilor de pe planeta Mercur: " << getSirTari(planeta01)<<endl;

    Stea stea1;
	cout<<stea1;

	string* compozitie = new string[2];
	compozitie[0] = "Hidrogen";
	compozitie[1] = "Heliu";
	Stea stea2(2, "Soare", 5778, 696340, 2, compozitie);
	cout<<stea2;

	Stea stea3(3, "Antares", 210000);
	cout<<stea3;

	cout << "Numarul total de stele: " << Stea::getNumarStele() << endl;

	cout << "Luminozitatea stelei Anteras: " << getLuminozitate(stea3) << " unitati solare." << endl;


	Stea stea01(stea1);
	cout<<stea01;
	cout << endl;

	stea3 = stea3;
	cout<<stea3;

	stea01.setNume("Arcturus");
	cout << stea01.getNume() << endl;

	cout << stea01.getId() << endl;

	stea01.setTemperatura(4300);
	cout << stea01.getTemperatura() << endl;

	stea01.setRaza(17671000);
	cout << stea01.getRaza() << endl;

	cout << stea01->getRaza() << endl;

	string* elemente = new string[7]{ "Nitrogen", "Oxigen", "Heliu", "Hidrogen","Nichel", "Zinc","Fier"};
	stea01.setElemente(7, elemente);
	cout << stea01 << endl;

	cout << "Un prim exemplu de element ar fi: " << stea01.getCompozitie()[0] << endl;
	cout << "Un alt exemplu de element ar fi: " << stea01.getCompozitie(1) << endl;

	try {
		cout << "Al treilea element din steaua Arcturus: " << stea01[2] << endl;
	}
	catch (int ex1) {
		cout << "Pozitia este in afara limitelor" << endl;
	}
	catch (float ex2) {
		cout << "Pozitia este in afara limitelor" << endl;
	}
	catch (...) {
		cout << "Exceptie necunoscuta";
	}
	
    cout << "Sirul elementelor din compozitia stelei Arcturus: " << getSirElemente(stea01) << endl;

	
	Constelatie constelatie1;
	cout << constelatie1;

	Stea* stele = new Stea[2];
	stele[0] = stea1;
	stele[1] = stea2;
	Constelatie constelatie2(2, "Ursa Mare", 4, 50.0, 2, stele); //acesta nu este un exemplu real
	cout << constelatie2;

	Constelatie constelatie01(constelatie1);
	cout << constelatie01;
	cout << endl;

	cout << constelatie01.getIdConstelatie() << endl;

	constelatie01.setDenumire("Pisces");
	cout << constelatie01.getDenumire() << endl;

	constelatie01.setVarstaConstelatie(5);
	cout << constelatie01.getVarstaConstelatie() << endl;

	constelatie01.setDistanta(67.0);
	cout << constelatie01.getDistanta() << endl;

	Stea* sstele = new Stea[2] { stea01,stea3 };
	constelatie01.setStele(2, sstele);
	cout << constelatie01 << endl;

	cout << "Prima stea din constelatia Pisces este " << constelatie01.getStele()[0] << endl;

	constelatie1 += constelatie2;

	if (constelatie1 == constelatie01) 
	{
		cout << "Cele doua constelatii au un numar egal de stele.";
	}
	else
	{
		cout << "Cele doua constelatii au un numar diferit de stele.";
	}
		

	//Galaxie galaxie1;
	//cout << galaxie1;

	//string* denumireTipuriStele = new string[3];
	//denumireTipuriStele[0] = "Nanosecvente";
	//denumireTipuriStele[1] = "Nanogigante";
	//denumireTipuriStele[2] = "Supernovele";
	//Galaxie galaxie2(2, "Andromeda", 3, denumireTipuriStele);
 //   cout<<galaxie2;

	//Galaxie galaxie3(3, "Fluture");
	//cout << galaxie3;
	//cin >> galaxie3;
	//cout << galaxie3;

	//cout << "Numarul total de galaxii: " << Galaxie::getNumarGalaxii() << endl;

	//cout << "Masa totala a galaxiei Fluture: " << getMasaTotala(galaxie3) << " kg." << endl;


	//Galaxie galaxie01(galaxie1);
	//cout << galaxie01;
	//cout << endl;

	//galaxie3 = galaxie3;
	//cout << galaxie3;

	//galaxie01.setNume("Compasul");
	//cout << galaxie01.getNume() << endl;

	//cout << galaxie01.getId() << endl;

	//string* tipuriStele = new string[5]{ "Pitice rosii", "Pitice albe", "Gigante rosii", "Gigante portocalii", "Gigante albastre"};
	//galaxie01.setTipuriStele(5, tipuriStele);
	//cout << galaxie01 << endl;

	//cout << "Un prim exemplu de tip de stea ar fi: " << galaxie01.getDenumiriTipuriStele()[0] << endl;
	//cout << "Un alt exemplu de tip de stea ar fi:" << galaxie01.getDenumireTipStea(3) << endl;

 //   cout << "Sirul tipurilor de stele din prima galaxie: " << getSirTipuriStele(galaxie01) << endl;
	//
	//Galaxie galaxie4;
	//if (galaxie3 != galaxie4)
	//{
	//	cout << "Cele doua galaxii au numar diferit de tipuri de stele.";
	//}
	//else
	//{
	//	cout<< "Cele doua galaxii au acelasi numar de tipuri de stele.";
	//} 
	//
 //   int n;
	//cout << "\nNumar planete: ";
	//cin >> n;
	//Planeta* planete = new Planeta[n];
	//for (int i = 0;i < n;i++)
	//{
	//	cin >> planete[i];
	//}
	//for (int i = 0;i < n;i++)
	//{
	//	cout << planete[i];
	//}
	//delete[]planete;

	//cout << "\nNumar stele: ";
	//cin >> n;
	//Stea* stele = new Stea[n];
	//for (int i = 0;i < n;i++)
	//{
	//	cin >> stele[i];
	//}
	//for (int i = 0;i < n;i++)
	//{
	//	cout << stele[i];
	//}
	//delete[]stele;

	//cout << "\nNumar galaxii: ";
	//cin >> n;
	//Galaxie* galaxii = new Galaxie[n];
	//for (int i = 0;i < n;i++)
	//{
	//	cin >> galaxii[i];
	//}
	//for (int i = 0;i < n;i++)
	//{
	//	cout << galaxii[i];
	//}
	//delete[]galaxii;

	//cout << "\nLiniile si coloanele matricei planeta: ";
	//cin >> n;
	//Planeta** matricePlaneta = new Planeta * [n];
	//for (int i = 0;i < n;i++)
	//{
	//	matricePlaneta[i] = new Planeta[n];
	//	for (int j = 0;j < n;j++)
	//	{
	//		cin >> matricePlaneta[i][j];
	//	}
	//}
	//for (int i = 0;i < n;i++) 
	//{
	//	for(int j = 0;j < n;j++)
	//	{
	//		cout << matricePlaneta[i][j];
	//	}
	//}
	//for (int i = 0;i < n;i++)
	//{
	//	delete[]matricePlaneta[i];
	//}
	//delete[]matricePlaneta;

  }