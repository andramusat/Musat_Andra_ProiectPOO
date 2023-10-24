#include<iostream>
using namespace std;
//DOMENIUL ASTRONOMIE
class Planeta 
{
public:
	const int id;
	static int numarPlanete;
	string nume;
	float diametru;
	int numarTari;
    string* denumireTari;
	
	Planeta():id(1) 
	{
		this->nume = "NoName";
		this->diametru = 0;
		this->numarTari = 0;
		this->denumireTari = NULL;
		numarPlanete++;
    }
	
    Planeta(int id, string nume, float diametru, int numarTari, string* denumireTari) : id(id), nume(nume), diametru(diametru), numarTari(numarTari)
	{

			this->denumireTari = new string[numarTari];
			for (int i = 0;i < numarTari; i++)
			{
				this->denumireTari[i] = denumireTari[i];
			}
			numarPlanete++;
	}
	
	Planeta(int id, string nume, float diametru) :id(id)
	{
		this->nume = nume;
		this->diametru = diametru;
		this->numarTari = 0;
		this->denumireTari = NULL;
		numarPlanete++;
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
		return numarPlanete;
	}

	float calculeazaVolum()
	{
		//volumul planetei folosind formula sferei
		float raza = diametru / 2;
		return (4.0/3.0)*3.14159*raza*raza*raza;
	}
};

int Planeta::numarPlanete = 0;

class Stea
{
public:
	const int id;
	static int numarStele;
	string nume;
	float temperatura;
	float raza;
	int numarElemente;
	string* compozitie; 

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
		this->compozitie = new string[numarElemente];
		for (int i = 0; i < numarElemente; i++)
		{
			this->compozitie[i] = compozitie[i];
		}
		numarStele++;
	}

	Stea(int id, string nume, float temperatura) :id(id)
	{
		this->nume = nume;
		this->temperatura = temperatura;
		this->raza = 0;
		this->numarElemente = 0;
		this->compozitie = NULL;
		numarStele++;
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
		return numarStele;
	}

	float calculeazaLuminozitate()
	{
		//luminozitatea unei stele
		return 4 * 3.14159 * raza * raza * temperatura * temperatura * temperatura;
	}
};

int Stea::numarStele = 0;


class Galaxie
{
public:
	const int id;
	static int numarGalaxii;
	string nume;
	int numarTipuriStele;
	string* denumireTipuriStele;

	Galaxie() : id(1)
	{
		this->nume = "NoName";
		this->numarTipuriStele = 0;
		this->denumireTipuriStele = NULL;
		numarGalaxii++;
	}

	Galaxie(int id, string nume, int numarTipuriStele, string* denumireTipuriStele): id(id), nume(nume), numarTipuriStele(numarTipuriStele)
	{

			this->denumireTipuriStele = new string[numarTipuriStele];
			for (int i = 0; i < numarTipuriStele; i++)
			{
				this->denumireTipuriStele[i] = denumireTipuriStele[i];
			}
		numarGalaxii++;
	}

	Galaxie(int id, string nume) :id(id)
	{
		this->nume = nume;
		this->numarTipuriStele = 0;
		this->denumireTipuriStele = NULL;
		numarGalaxii++;
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
		return numarGalaxii;
	}

	long calculeazaMasaTotala()
	{
		//masa totala a galaxiei
		return numarTipuriStele * 2e30; // Presupunem o masa medie a unei stele de 2e30 kg
	}
};

int Galaxie::numarGalaxii = 0;


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

	cout << "Volumul Pamantului: " << pPlaneta2->calculeazaVolum() << " unitati cubice." << endl;

	delete pPlaneta2;


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

	cout << "Luminozitatea Soarelui: " << pStea2->calculeazaLuminozitate() << " unitati solare." << endl;

	delete pStea2;

	Galaxie galaxie1;
	galaxie1.afisareGalaxie();

	string* denumireTipuriStele = new string[3];
	denumireTipuriStele[0] = "Nanosecvente";
	denumireTipuriStele[1] = "Nanogigante";
	denumireTipuriStele[2] = "Supernovele";
	Galaxie* pGalaxie2 = new Galaxie(2, "Andromeda", 3, denumireTipuriStele);
    pGalaxie2->afisareGalaxie();

	Galaxie galaxie3(3, "Ochilor Negri");
	stea3.afisareStea();

	cout << "Numarul total de galaxii: " << Galaxie::getNumarGalaxii() << endl;

	cout << "Masa totala a Andromedei: " << pGalaxie2->calculeazaMasaTotala() << " kg." << endl;

	delete pGalaxie2;
  }