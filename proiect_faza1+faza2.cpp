#include<iostream>
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

	void afisarePlaneta()
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
	}

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
	{
		return this->nume;
	}

	const int getId()
	{
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

	void setNumarTari(int numarTari, string* denumire)
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

	string* getDenumireTari()
	{
		return this->denumireTari;
	}
	
	string getDenumireTari(int index)
	{
		if (index >= 0 && index < this->numarTari)
		{
			return this->denumireTari[index];
		}
	}

	friend float getVolum(const Planeta& planeta);
	friend string getSirTari(const Planeta& planeta);
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
		numarStele++;
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
			numarStele++;
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
		numarStele++;
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

	void afisareStea()
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
	}

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
	{
		return this->nume;
	}

	const int getId()
	{
		return this->id;
	}

	void setTemperatura(float temperatura)
	{
		if (temperatura > 0)
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
		if (raza > 0)
		{
			this->raza = raza;
		}
	}

	float getRaza()
	{
		return this->raza;
	}

	void setNumarElemente(int numarElemente, string* comp)
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
		numarGalaxii++;
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
			numarGalaxii++;
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
		numarGalaxii++;
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

	void afisareGalaxie()
	{
		cout << "Galaxia " << nume << " are id-ul " << id << " si contine " << numarTipuriStele << " stele." << endl;
		cout << "Denumirile stelelor din galaxie sunt: ";
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
	}

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
	{
		return this->nume;
	}

	const int getId()
	{
		return this->id;
	}

	void setNumarTipuriStele(int numarTipuriStele, string* denumire)
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

	string* getDenumireTipuriStele()
	{
		return this->denumireTipuriStele;
	}

	string getDenumireTipuriStele(int index)
	{
		if (index >= 0 && index < this->numarTipuriStele)
		{
			return this->denumireTipuriStele[index];
		}
	}

	friend long getMasaTotala(const Galaxie& galaxie);
	friend string getSirTipuriStele(const Galaxie& galexie);
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

void main()
{
	Planeta planeta1;
	planeta1.afisarePlaneta();

	string* denumireTari = new string[4];
	denumireTari[0] = "Islanda";
	denumireTari[1] = "Elvetia";
	denumireTari[2] = "Turcia";
	denumireTari[3] = "Norvegia";
	Planeta* pPlaneta2 = new Planeta(2, "Pamant", 12742, 4, denumireTari);
	pPlaneta2->afisarePlaneta();
	
	Planeta planeta3(3, "Marte", 6779);
	planeta3.afisarePlaneta();

	cout << "Numarul total de planete: " << Planeta::getNumarPlanete() << endl;

	cout << "Volumul planetei Marte: " << getVolum(planeta3) << " unitati cubice." << endl;


	Planeta planeta01(planeta1);
	planeta01.afisarePlaneta();
	cout << endl;
    
	planeta3 = planeta3;
	planeta3.afisarePlaneta();

	planeta01.setNume("Mercur");
	cout << planeta01.getNume() << endl;

	cout << planeta01.getId() << endl;

	planeta01.setDiametru(4879.4);
	cout << planeta01.getDiametru() << endl;

	string* tari = new string[3]{ "Calidora", "Heliospica", "Mercuria" }; //acestea sunt denumiri fictive
	planeta01.setNumarTari(3, tari);
	planeta01.afisarePlaneta();

	cout << *planeta01.getDenumireTari() << endl;
	cout << planeta01.getDenumireTari()[1] << endl;
	cout << planeta01.getDenumireTari(1) << endl;
	
	delete[]tari;

	cout << "Sirul tarilor de pe planeta Mercur: " << getSirTari(planeta01)<<endl;

    Stea stea1;
	stea1.afisareStea();

	string* compozitie = new string[2];
	compozitie[0] = "Hidrogen";
	compozitie[1] = "Heliu";
	Stea* pStea2=new Stea(2, "Soare", 5778, 696340, 2, compozitie);
	pStea2->afisareStea();

	Stea stea3(3, "Antares", 210000);
	stea3.afisareStea();

	cout << "Numarul total de stele: " << Stea::getNumarStele() << endl;

	cout << "Luminozitatea stelei Anteras: " << getLuminozitate(stea3) << " unitati solare." << endl;


	Stea stea01(stea1);
	stea01.afisareStea();
	cout << endl;

	stea3 = stea3;
	stea3.afisareStea();

	stea01.setNume("Arcturus");
	cout << stea01.getNume() << endl;

	cout << stea01.getId() << endl;

	stea01.setTemperatura(4300);
	cout << stea01.getTemperatura() << endl;

	stea01.setRaza(17671000);
	cout << stea01.getRaza() << endl;

	string* elemente = new string[7]{ "Nitrogen", "Oxigen", "Heliu", "Hidrogen","Nichel", "Zinc","Fier"};
	stea01.setNumarElemente(7, elemente);
	stea01.afisareStea();

	cout << *stea01.getCompozitie() << endl;
	cout << stea01.getCompozitie()[1] << endl;
	cout << stea01.getCompozitie(1) << endl;

	delete[]elemente;

	cout << "Sirul elementelor din compozitia stelei Arcturus: " << getSirElemente(stea01) << endl;

	Galaxie galaxie1;
	galaxie1.afisareGalaxie();

	string* denumireTipuriStele = new string[3];
	denumireTipuriStele[0] = "Nanosecvente";
	denumireTipuriStele[1] = "Nanogigante";
	denumireTipuriStele[2] = "Supernovele";
	Galaxie* pGalaxie2 = new Galaxie(2, "Andromeda", 3, denumireTipuriStele);
    pGalaxie2->afisareGalaxie();

	Galaxie galaxie3(3, "Fluture");
	galaxie3.afisareGalaxie();

	cout << "Numarul total de galaxii: " << Galaxie::getNumarGalaxii() << endl;

	cout << "Masa totala a Andromedei: " << getMasaTotala(galaxie3) << " kg." << endl;


	Galaxie galaxie01(galaxie1);
	galaxie01.afisareGalaxie();
	cout << endl;

	galaxie3 = galaxie3;
	galaxie3.afisareGalaxie();

	galaxie01.setNume("Compasul");
	cout << galaxie01.getNume() << endl;

	cout << galaxie01.getId() << endl;

	string* tipuriStele = new string[5]{ "Pitice rosii", "Pitice albe", "Gigante rosii", "Gigante portocalii", "Gigante albastre"};
	galaxie01.setNumarTipuriStele(5, tipuriStele);
	galaxie01.afisareGalaxie();

	cout << *galaxie01.getDenumireTipuriStele() << endl;
	cout << galaxie01.getDenumireTipuriStele()[1] << endl;
	cout << galaxie01.getDenumireTipuriStele(1) << endl;

	delete[]tipuriStele;

	cout << "Sirul tipurilor de stele din prima galaxie: " << getSirTipuriStele(galaxie01) << endl;
  }
