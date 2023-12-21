#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<windows.h>
#define _CRT_SECURE_NO_WARNINGS
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

	int getNumarTari()
	{
		return this->numarTari;
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
			this->denumireTari = new string[this->numarTari];
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
		cout << "Are diametrul de: ";
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
			citire.ignore();
			for (int i = 0;i < planeta.numarTari;i++)
			{
				cout << "Cateva tari ar fi" << i + 1 << ": ";
				getline(citire, planeta.denumireTari[i]);
			}
		}
		else
		{
			cout << "Nicio tara." << endl;
			planeta.denumireTari = NULL;
		}
		return citire;
	}

	friend ofstream& operator<<(ofstream& out, const Planeta& planeta)
	{
		out << "Planeta " << planeta.nume << " are diametrul de " << planeta.diametru << " km si " << planeta.numarTari << " tari.";
		out << "\nCateva tari ar fi: ";
		if (planeta.numarTari == 0)
		{
			out << "Nicio tara.";
		}
		else
		{

			for (int i = 0;i < planeta.numarTari - 1;i++)
			{
				out << planeta.denumireTari[i] << ", ";

			}
			out << planeta.denumireTari[planeta.numarTari - 1] << ".";
		}
		out << endl;
		return out;
    }

	friend ifstream& operator>>(ifstream& in, Planeta& planeta)
	{
		in >> planeta.nume;
		in >> planeta.diametru;
		in >> planeta.numarTari;
		if (planeta.denumireTari != NULL)
		{
			delete[]planeta.denumireTari;
		}
		if (planeta.numarTari > 0)
		{
			planeta.denumireTari = new string[planeta.numarTari];
			for (int i = 0;i < planeta.numarTari;i++)
			{
				in >> planeta.denumireTari[i];
			}
		}
		else
		{
			planeta.denumireTari = NULL;
		}
		return in;
	}

	void scrieInFisierBinar(fstream& f)
	{
		int lungimeNume = nume.length() + 1;
		f.write((char*)&lungimeNume, sizeof(int));
		f.write((char*)nume.c_str(), lungimeNume);
		f.write((char*)&diametru, sizeof(float));
		f.write((char*)&numarTari, sizeof(int));
		for (int i = 0; i < numarTari; i++) {
			int lungimeDenumireTara = this->denumireTari[i].length() + 1;
			f.write((char*)&lungimeDenumireTara, sizeof(int));
			f.write(denumireTari[i].c_str(), lungimeDenumireTara);
		}
	}


	void citesteDinFisierBinar(fstream& f)
	{
		int lungimeNume;
		f.read((char*)&lungimeNume, sizeof(int));
		char* bufferNume = new char[lungimeNume];
		f.read((char*)bufferNume, lungimeNume);
		nume = bufferNume;
		delete[] bufferNume;
		f.read((char*)&diametru, sizeof(float));
		f.read((char*)&numarTari, sizeof(int));
		if (denumireTari != 0)
		{
			delete[]denumireTari;
		}
		denumireTari = new string[numarTari];
		for (int i = 0; i < numarTari; i++) {
			int lungimeDenumireTari;
			f.read((char*)&lungimeDenumireTari, sizeof(int));
			char* bufferDenumireTari = new char[lungimeDenumireTari];
			f.read((char*)bufferDenumireTari, lungimeDenumireTari);
			denumireTari[i] = bufferDenumireTari;
			delete[] bufferDenumireTari;
		}
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
	vizualizare << "Planeta " << planeta.getNume() << " are id-ul " << planeta.getId() << ", diametrul de " << planeta.diametru << " km si " << planeta.numarTari << " tari.";
	vizualizare << "\nCateva tari ar fi: ";
	if (planeta.numarTari == 0)
	{
		vizualizare << "Nicio tara.";
	}
	else
	{

		for (int i = 0;i < planeta.numarTari-1;i++)
		{
			vizualizare << planeta.denumireTari[i] << ", ";

		}
		vizualizare << planeta.denumireTari[planeta.numarTari - 1]<<".";
	}
	vizualizare << endl;
	return vizualizare;
}

ostream& green(ostream& out)
{
	HANDLE standardOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(standardOutput, FOREGROUND_GREEN);
	return out;
}

class SmartPlanet: public Planeta
{
private:
	int varstaTehnologie;
	char* denumireTehnologie;
public:

	SmartPlanet() : Planeta()
	{
		this->varstaTehnologie = 0;
		this->denumireTehnologie = new char[strlen("Tehnologie necunoscuta") + 1];
		strcpy_s(this->denumireTehnologie, strlen("Tehnologie necunoscuta") + 1, "Tehnologie necunoscuta");
	}

	SmartPlanet(int vartsaTehnologie, const char* denumireTehnologie, string nume, float diametru, int numarTari, string* denumireTari) :Planeta(2, nume, diametru, numarTari, denumireTari)
	{
		this->varstaTehnologie = varstaTehnologie;
		this->denumireTehnologie = new char[strlen(denumireTehnologie) + 1];
		strcpy_s(this->denumireTehnologie, strlen(denumireTehnologie) + 1, denumireTehnologie);
	}

	SmartPlanet(int varstaTehnologie, const char* denumireTehnologie) : Planeta(3, "Marte", 6779)
	{
		this->varstaTehnologie = varstaTehnologie;
		this->denumireTehnologie = new char[strlen(denumireTehnologie) + 1];
		strcpy_s(this->denumireTehnologie, strlen(denumireTehnologie) + 1, denumireTehnologie);
	}

	SmartPlanet(const SmartPlanet& sp) : Planeta(sp)
	{
		this->varstaTehnologie = sp.varstaTehnologie;
		this->denumireTehnologie = new char[strlen(sp.denumireTehnologie) + 1];
		strcpy_s(this->denumireTehnologie, strlen(sp.denumireTehnologie) + 1, sp.denumireTehnologie);
	}

	SmartPlanet operator=(const SmartPlanet& sp)
	{
		if (this != &sp)
		{
			Planeta::operator=(sp);
			this->varstaTehnologie = sp.varstaTehnologie;
			if (this->denumireTehnologie != NULL)
			{
				delete[]this->denumireTehnologie;
			}
			this->denumireTehnologie = new char[strlen(sp.denumireTehnologie) + 1];
			strcpy_s(this->denumireTehnologie, strlen(sp.denumireTehnologie) + 1, sp.denumireTehnologie);
		}
		return *this;
	}

	~SmartPlanet()
	{
		if (this->denumireTehnologie != NULL)
		{
			delete[]this->denumireTehnologie;
		}
	}

	void setVarstaTehnologie(int varstaTehnologie)
	{
		if (varstaTehnologie > 0)
		{
			this->varstaTehnologie = varstaTehnologie;
		}
	}

	int getVarstaTehnologie()
	{
		return this->varstaTehnologie;
	}

	void setDenumireTehnologie(const char* denumire)
	{
		if (strlen(denumire) > 0)
		{
			if (this->denumireTehnologie != NULL)
			{
				delete[]this->denumireTehnologie;
			}
			this->denumireTehnologie = new char[strlen(denumire) + 1];
			strcpy_s(this->denumireTehnologie, strlen(denumire)+1, denumire);
		}
	}

	void InvechireaTehnologiei(int ani)
	{
		varstaTehnologie += ani;
	}

	friend ostream& operator<<(ostream& out, const SmartPlanet& sp)
	{
		out << "Planeta Smart: " << (Planeta)sp << endl;
		out << "Varsta Tehnologiei: " << sp.varstaTehnologie << endl;
		out << "Numele Tehnologiei: " << sp.denumireTehnologie << " " << endl;
		return out;
	}

	friend istream& operator>>(istream& in, SmartPlanet& sp)
	{
		cout << "Planeta Smart: ";
		in >> (Planeta&)sp;
		cout << "Varsta tehnologiei: ";
		in >> sp.varstaTehnologie;
		if (sp.denumireTehnologie != NULL)
		{
			delete[]sp.denumireTehnologie;
		}
		cout << "Denumirea tehnologiei: ";
		char buffer[30];
		in >> buffer;
		sp.denumireTehnologie = new char[strlen(buffer) + 1];
		strcpy_s(sp.denumireTehnologie, strlen(buffer) + 1, buffer);
		return in;
	}

};

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
			this->compozitie = new string[this->numarElemente];
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
		cout << "Are temperatura de: ";
		citire >> stea.temperatura;
		cout << "Si o raza de: ";
		citire >> stea.raza;
		cout << "In compozitia ei se afla elemente in numar de: ";
		citire >> stea.numarElemente;
		if (stea.compozitie != NULL)
		{
			delete[]stea.compozitie;
		}
		if (stea.numarElemente > 0)
		{
			stea.compozitie = new string[stea.numarElemente];
			citire.ignore();
			for (int i = 0;i < stea.numarElemente;i++)
			{
				cout << "Cateva elemente ar fi" << i + 1 << ": ";
				getline(citire, stea.compozitie[i]);
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

	friend ofstream& operator<<(ofstream& out, const Stea& stea)
	{
		out << "Steaua " << stea.nume << " are temperatura de " << stea.temperatura << " Kelvin si o raza de " << stea.raza << " unitati solare." << "\nIn compozitia stelei se regasesc " << stea.numarElemente << " elemente.";
		out << "\nCateva elemente ar fi: ";
		if (stea.numarElemente == 0)
		{
			out << "Niciun element.";
		}
		else
		{

			for (int i = 0;i < stea.numarElemente - 1;i++)
			{
				out << stea.compozitie[i] << ", ";
			}
			out << stea.compozitie[stea.numarElemente - 1]<<".";
		}
		out << endl;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Stea& stea)
	{
		in >> stea.nume;
		in >> stea.temperatura;
		in >> stea.raza;
		in >> stea.numarElemente;
		if (stea.compozitie != NULL)
		{
			delete[]stea.compozitie;
		}
		if (stea.numarElemente > 0)
		{
			stea.compozitie = new string[stea.numarElemente];
			for (int i = 0;i < stea.numarElemente;i++)
			{
				in >> stea.compozitie[i];
			}
		}
		else
		{
			stea.compozitie = NULL;
		}
		return in;
	}

	void scrieInFisierBinar(fstream& f)
	{
		int lungimeNume = nume.length() + 1;
		f.write((char*)&lungimeNume, sizeof(int));
		f.write((char*)nume.c_str(), lungimeNume);
		f.write((char*)&temperatura, sizeof(float));
		f.write((char*)&raza, sizeof(float));
		f.write((char*)&numarElemente, sizeof(int));
		for (int i = 0; i < numarElemente; i++)
		{
			int lungimeCompozitie = this->compozitie[i].length() + 1;
			f.write((char*)&lungimeCompozitie, sizeof(int));
			f.write(compozitie[i].c_str(), lungimeCompozitie);
		}
	}

	void cietsteDinFisierBinar(fstream& f)
	{
	    int lungimeNume;
		f.read((char*)&lungimeNume, sizeof(int));
		char* bufferNume = new char[lungimeNume];
		f.read((char*)bufferNume, lungimeNume);
		nume = bufferNume;
		delete[]bufferNume;
		f.read((char*)&temperatura, sizeof(float));
		f.read((char*)&raza, sizeof(float));
		f.read((char*)&numarElemente, sizeof(int));
		if(compozitie!=0)
		{
			delete[]compozitie;
		}
		compozitie = new string[numarElemente];
		for (int i = 0; i < numarElemente; i++)
		{
			int lungimeCompozitie;
			f.read((char*)&lungimeCompozitie, sizeof(int));
			char* bufferCompozitie = new char[lungimeCompozitie];
			f.read((char*)bufferCompozitie, lungimeCompozitie);
			compozitie[i] = bufferCompozitie;
			delete[]bufferCompozitie;
		}
	}

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
	vizualizare << "Steaua " << stea.getNume() << " are id-ul " << stea.getId() << ", temperatura de " << stea.temperatura << " Kelvin si o raza de " << stea.raza << " unitati solare." << "\nIn compozitia stelei se regasesc "<<stea.numarElemente<<" elemente.";
	vizualizare << "\nCateva elemente ar fi: ";
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
		vizualizare << stea.compozitie[stea.numarElemente - 1]<<".";
	}
	vizualizare << endl;
	return vizualizare;
}

ostream& red(ostream& out)
{
	HANDLE standardOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(standardOutput, FOREGROUND_RED);
	return out;
}

//relatie de "has a" cu clasa stea
class Constelatie {
private:
	string denumire;
	int varstaConstelatie;
	float distanta;
	int nrStele;
	Stea* stele;
public:
	
	Constelatie()
	{
		this->denumire = "NoName";
		this->varstaConstelatie = 0;
		this->distanta = 0.0;
		this->nrStele = 0;
		this->stele = NULL;
	}

	Constelatie(string nume, int varsta, float distanta, int nr, Stea* stele) : denumire(nume), varstaConstelatie(varsta), distanta(distanta), nrStele(nr)
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


	Constelatie(const Constelatie& constelatie)
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

	Constelatie operator=(const Constelatie& constelatie)
	{
		if (this != &constelatie)
		{
			this->denumire = constelatie.denumire;
			this->varstaConstelatie = constelatie.varstaConstelatie;
			this->distanta = constelatie.distanta;
			this->nrStele = constelatie.nrStele;
			if (this->stele != NULL)
			{
				delete[]this->stele;
			}
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
		return *this;
	}

	~Constelatie()
	{
		if (this->stele != NULL)
		{
			delete[]this->stele;
		}
	}

	void setDenumire(string denumire)
	{
		if (denumire.length() > 3)
		{
			this->denumire = denumire;
		}
	}

	string getDenumire()
    const {
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
	vizualizare << "Constelatia " << constelatie.getDenumire() << " are varsta de " << constelatie.varstaConstelatie << " miliarde de ani si o distanta de " << constelatie.distanta << " ani lumina." << "\nIn aceasta constelatie se regasesc " << constelatie.nrStele << " stele.";
	vizualizare << "\nCateva stele ar fi: ";
	if (constelatie.nrStele == 0)
	{
		vizualizare << "Nicio stea.";
	}
	else
	{

		for (int i = 0;i < constelatie.nrStele-1;i++)
		{
			vizualizare << constelatie.stele[i] << endl;

		}
		vizualizare << constelatie.stele[constelatie.nrStele - 1];
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
		cout << "Are un numar de tipuri de stele: ";
		citire >> galaxie.numarTipuriStele;
		if (galaxie.denumireTipuriStele != NULL)
		{
			delete[]galaxie.denumireTipuriStele;
		}
		if (galaxie.numarTipuriStele > 0)
		{
			galaxie.denumireTipuriStele = new string[galaxie.numarTipuriStele];
			citire.ignore();
			for (int i = 0;i < galaxie.numarTipuriStele;i++)
			{
				cout << "Cateva tipuri de stele ar fi" << i + 1 << ": ";
				getline(citire, galaxie.denumireTipuriStele[i]);
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

	friend ofstream& operator<<(ofstream& out, const Galaxie& galaxie)
	{
		out << "Galaxia " << galaxie.nume << " contine " << galaxie.numarTipuriStele << " stele.";
		out << "\nCateva tipuri de stele ar fi: ";
		if (galaxie.numarTipuriStele == 0)
		{
			out << "Niciun tip de stele.";
		}
		else
		{

			for (int i = 0;i < galaxie.numarTipuriStele - 1;i++)
			{
				out << galaxie.denumireTipuriStele[i] << ", ";

			}
			out << galaxie.denumireTipuriStele[galaxie.numarTipuriStele - 1]<<".";
		}
		out << endl;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Galaxie& galaxie)
	{
		in >> galaxie.nume;
		in >> galaxie.numarTipuriStele;
		if (galaxie.denumireTipuriStele != NULL)
		{
			delete[]galaxie.denumireTipuriStele;
		}
		if (galaxie.numarTipuriStele > 0)
		{
			galaxie.denumireTipuriStele = new string[galaxie.numarTipuriStele];
			for (int i = 0;galaxie.numarTipuriStele;i++)
			{
				in >> galaxie.denumireTipuriStele[i];
			}
		}
		else
		{
			galaxie.denumireTipuriStele = NULL;
		}
		return in;
	}
	/*string nume;
	int numarTipuriStele;
	string* denumireTipuriStele;*/

	void scrieInFisierBinar(fstream& f) 
	{
        int lungimeNume = nume.length() + 1;
		f.write((char*)&lungimeNume, sizeof(int));
		f.write((char*)nume.c_str(), lungimeNume);
		f.write((char*)&numarTipuriStele, sizeof(int));
		for (int i = 0; i < numarTipuriStele;i++)
		{
			int lungimeDenumireTipuriStele = this->denumireTipuriStele[i].length() + 1;
			f.write((char*)&lungimeDenumireTipuriStele, sizeof(int));
			f.write(denumireTipuriStele[i].c_str(), lungimeDenumireTipuriStele);
		}
	}

	void citesteDinFisierBinar(fstream& f) 
	{
		int lungimeNume;
		f.read((char*)&lungimeNume, sizeof(int));
		char* bufferNume = new char[lungimeNume];
		f.read((char*)bufferNume, lungimeNume);
		nume = bufferNume;
		delete[]bufferNume;
		f.read((char*)&numarTipuriStele, sizeof(int));
		if (denumireTipuriStele != 0)
		{
			delete[]denumireTipuriStele;
		}
		denumireTipuriStele = new string[numarTipuriStele];
		for (int i = 0;i < numarTipuriStele;i++)
		{
			int lungimeDenumireTipuriStele;
			f.read((char*)&lungimeDenumireTipuriStele, sizeof(int));
			char* bufferDenumireTipuriStele = new char[lungimeDenumireTipuriStele];
			f.read((char*)bufferDenumireTipuriStele, lungimeDenumireTipuriStele);
			denumireTipuriStele[i] = bufferDenumireTipuriStele;
			delete[]bufferDenumireTipuriStele;
		}
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
	vizualizare << "Galaxia " << galaxie.getNume() << " are id-ul " << galaxie.getId() << " si contine " << galaxie.numarTipuriStele << " stele.";
	vizualizare << "\nCateva tipuri de stele ar fi: ";
	if (galaxie.numarTipuriStele == 0)
	{
		vizualizare << "Niciun tip de stele.";
	}
	else
	{

		for (int i = 0;i < galaxie.numarTipuriStele-1;i++)
		{
			vizualizare << galaxie.denumireTipuriStele[i] << ", ";

		}
		vizualizare << galaxie.denumireTipuriStele[galaxie.numarTipuriStele - 1]<<".";
	}
	vizualizare << endl;
	return vizualizare;
}

ostream& blue(ostream& out)
{
	HANDLE standardOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(standardOutput, FOREGROUND_BLUE);
	return out;
}

ostream& intensity(ostream& out)
{
	HANDLE standardOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(standardOutput, FOREGROUND_INTENSITY);
	return out;
}

class GalaxieStralucitoare : public Galaxie
{
private:
	float stralucire;
	int nrAni;
	int* nasteriStelePeAn;
public:

	GalaxieStralucitoare() :Galaxie()
	{
		this->stralucire = 0.0;
		this->nrAni = 0;
		this->nasteriStelePeAn = NULL;
	}

	GalaxieStralucitoare(float stralucire, int nrAni, float* nasteriStelePeAn, string nume, int numarTipuriStele, string* denumireTipuriStele) : Galaxie(2, nume, numarTipuriStele, denumireTipuriStele)
	{
		this->stralucire = stralucire;
		this->nrAni = nrAni;
		if (nrAni != 0)
		{
			this->nasteriStelePeAn = new int[nrAni];
			for (int i = 0; i < this->nrAni; i++)
			{
				this->nasteriStelePeAn[i] = nasteriStelePeAn[i];
			}
		}
		else
		{
			this->nasteriStelePeAn = NULL;
		}
	}
    
	GalaxieStralucitoare(float stralucire) : Galaxie(3, "Fluture")
	{
		this->stralucire = stralucire;
		this->nrAni = 7690;
		this->nasteriStelePeAn = new int[nrAni];
		for (int i = 0;i < this->nrAni;i++)
		{
			this->nasteriStelePeAn[i] = 89;
		}
	}
	

	GalaxieStralucitoare(const GalaxieStralucitoare& gs) :Galaxie(gs)
	{
		this->stralucire = gs.stralucire;
		this->nrAni = gs.nrAni;
		if (this->nrAni > 0)
		{
			this->nasteriStelePeAn = new int[this->nrAni];
			for (int i = 0;this->nrAni;i++)
			{
				this->nasteriStelePeAn[i] = gs.nasteriStelePeAn[i];
			}
		}
		else
		{
			this->nasteriStelePeAn = NULL;
		}
	}

	GalaxieStralucitoare operator=(const GalaxieStralucitoare& gs)
	{
		if (this != &gs)
		{
			Galaxie::operator=(gs);
			this->stralucire = gs.stralucire;
			this->nrAni = gs.nrAni;
			if (this->nasteriStelePeAn != NULL)
			{
				delete[]this->nasteriStelePeAn;
			}
			if (this->nrAni > 0)
			{
				this->nasteriStelePeAn = new int[this->nrAni];
				for (int i = 0;i < this->nrAni;i++)
				{
					this->nasteriStelePeAn[i] = gs.nasteriStelePeAn[i];
				}
			}
			else
			{
				this->nasteriStelePeAn = NULL;
			}
		}
		return *this;
	}

	~GalaxieStralucitoare()
	{
		if (this->nasteriStelePeAn != NULL)
		{
			delete[]this->nasteriStelePeAn;
		}
	}

	void setStralucire(float stralucire) 
    {
		if (stralucire > 0.0)
		{
			this->stralucire = stralucire;
		}
    }

	float getStralucire()
	{
		return this->stralucire;
	}

	int getVarsta()
	{
		return this->nrAni;
	}

	void setVarsta(int numar, int* nasteri)
	{
		if (nrAni > 0)
		{
			this->nrAni = numar;
			if (this->nasteriStelePeAn != NULL)
			{
				delete[]this->nasteriStelePeAn;
			}
			this->nasteriStelePeAn = new int[this->nrAni];
			for (int i = 0;i < nrAni;i++)
			{
				this->nasteriStelePeAn[i] = nasteri[i];
			}
		}
	}

	int* getNasteri()
	{
		return this->nasteriStelePeAn;
	}
	
	friend ostream& operator<<(ostream& out, const GalaxieStralucitoare& gs)
	{
		out << "Galaxia: " << (Galaxie)gs << endl;
		out << "Stralucire: " << gs.stralucire << endl;
		out << "Varsta: " << gs.nrAni;
		out << "\nCate stele apar pe an: ";
		if (gs.nrAni == 0)
		{
			out << "Niciun nascut.";
		}
		else
		{

			for (int i = 0;i < gs.nrAni-1;i++)
			{
				out << gs.nasteriStelePeAn[i] << ", ";

			}
			out << gs.nasteriStelePeAn[gs.nrAni - 1] << ".";
		}
		out << endl;
		return out;
	}

	friend istream& operator>>(istream& in, GalaxieStralucitoare& gs)
	{
		cout << "Galaxia: ";
		in >> (Galaxie&)gs;
		cout << "Stralucirea: ";
		in >> gs.stralucire;
		cout << "Varsta: ";
		in >> gs.nrAni;
		if (gs.nasteriStelePeAn != NULL)
		{
			delete[]gs.nasteriStelePeAn;
		}
		if (gs.nrAni > 0)
		{
			gs.nasteriStelePeAn = new int[gs.nrAni];
			for (int i = 0;i < gs.nrAni;i++)
			{
				cout << "Cate stele apar pe an" << i + 1 << ": ";
				in>> gs.nasteriStelePeAn[i];
			}
		}
		else
		{
			cout << "Nicio nastere." << endl;
			gs.nasteriStelePeAn = NULL;
		}
		return in;
	}


	int calculeazaNasteriInToatal()
	{
		int s = 0;
		if (nrAni > 0)
		{
			for (int i = 0;i < nrAni;i++)
			{
				s++;
			}
		}
		return s;
	}

};

void main()
{
	//Planeta planeta1;
	//cout<<planeta1;

	//string* denumireTari = new string[4];
	//denumireTari[0] = "Islanda";
	//denumireTari[1] = "Elvetia";
	//denumireTari[2] = "Turcia";
	//denumireTari[3] = "Norvegia";
	//Planeta planeta2(2, "Pamant", 12742.0, 4, denumireTari);
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

 //   Stea stea1;
	//cout<<stea1;

	//string* compozitie = new string[2];
	//compozitie[0] = "Hidrogen";
	//compozitie[1] = "Heliu";
	//Stea stea2(2, "Soare", 5778, 696340, 2, compozitie);
	//cout<<stea2;

	//Stea stea3(3, "Antares", 210000);
	//cout<<stea3;

	//cout << "Numarul total de stele: " << Stea::getNumarStele() << endl;

	//cout << "Luminozitatea stelei Anteras: " << getLuminozitate(stea3) << " unitati solare." << endl;


	//Stea stea01(stea1);
	//cout<<stea01;
	//cout << endl;

	//stea3 = stea3;
	//cout<<stea3;

	//stea01.setNume("Arcturus");
	//cout << stea01.getNume() << endl;

	//cout << stea01.getId() << endl;

	//stea01.setTemperatura(4300);
	//cout << stea01.getTemperatura() << endl;

	//stea01.setRaza(17671000);
	//cout << stea01.getRaza() << endl;

	//cout << stea01->getRaza() << endl;

	//string* elemente = new string[7]{ "Nitrogen", "Oxigen", "Heliu", "Hidrogen","Nichel", "Zinc","Fier"};
	//stea01.setElemente(7, elemente);
	//cout << stea01 << endl;

	//cout << "Un prim exemplu de element ar fi: " << stea01.getCompozitie()[0] << endl;
	//cout << "Un alt exemplu de element ar fi: " << stea01.getCompozitie(1) << endl;

	//try {
	//	cout << "Al treilea element din steaua Arcturus: " << stea01[2] << endl;
	//}
	//catch (int ex1) {
	//	cout << "Pozitia este in afara limitelor" << endl;
	//}
	//catch (float ex2) {
	//	cout << "Pozitia este in afara limitelor" << endl;
	//}
	//catch (...) {
	//	cout << "Exceptie necunoscuta";
	//}
	//
 //   cout << "Sirul elementelor din compozitia stelei Arcturus: " << getSirElemente(stea01) << endl;

	////faza 5 cu relatie "has a"
	//Constelatie constelatie1;
	//cout << constelatie1;

	//Stea* stele = new Stea[2];
	//stele[0] = stea1;
	//stele[1] = stea2;
	//Constelatie constelatie2("Ursa Mare", 4, 50.0, 2, stele); //acesta nu este un exemplu real
	//cout << constelatie2;

	//Constelatie constelatie01(constelatie1);
	//cout << constelatie01;
	//cout << endl;

	//Constelatie constelatie3;
	//constelatie3 = constelatie2;
	//cout << constelatie3 << endl;

	//constelatie01.setDenumire("Pisces");
	//cout << constelatie01.getDenumire() << endl;

	//constelatie01.setVarstaConstelatie(5);
	//cout << constelatie01.getVarstaConstelatie() << endl;

	//constelatie01.setDistanta(67.0);
	//cout << constelatie01.getDistanta() << endl;

	//Stea* sstele = new Stea[2] { stea01,stea3 };
	//constelatie01.setStele(2, sstele);
	//cout << constelatie01 << endl;

	//cout << "Prima stea din constelatia Pisces este " << constelatie01.getStele()[0] << endl;

	//constelatie1 += constelatie2;

	//if (constelatie1 == constelatie01) 
	//{
	//	cout << "Cele doua constelatii au un numar egal de stele.";
	//}
	//else
	//{
	//	cout << "Cele doua constelatii au un numar diferit de stele.";
	//}


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
	////faza 4 cu vectori
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

	//faza 6
	//lucru cu fisiere text pentru clasele Planeta, Stea si Galaxie

 //   ofstream f("Astronomie.txt", ios::out);
	//Planeta planeta1;
	//cin >> planeta1;
	//Stea stea1;
	////cin >> stea1;
	//Galaxie galaxie1;
	//cin >> galaxie1;
	//f << planeta1;
	//f << stea1;
	//f << galaxie1;
	//f.close();

	/*Planeta planeta2(2, "Marte", 6779);
	Stea stea2(2, "Antares", 210000);
	Galaxie galaxie2(2, "Fluture");
	ifstream g("Astronimie.txt", ios::in);
	g >> planeta2;
	cout << green << planeta2;
	g >> stea2;
	cout << red << stea2;
	g >> galaxie2;
	cout << blue << galaxie2 << intensity;
	g.close();*/

	//lucru cu fisiere binare pentru clasele Planeta, Stea si Galaxie
	
    //fstream f("Astronomie.dat", ios::out | ios::binary);
	string* denumireTari = new string[4];
	denumireTari[0] = "Islanda";
	denumireTari[1] = "Elvetia";
	denumireTari[2] = "Turcia";
	denumireTari[3] = "Norvegia";
	Planeta planeta(1, "Pamant", 12742.0, 4, denumireTari);

	string* compozitie = new string[2];
	compozitie[0] = "Hidrogen";
	compozitie[1] = "Heliu";
	Stea stea(1, "Soare", 5778, 696340, 2, compozitie);

	string* denumireTipuriStele = new string[3];
	denumireTipuriStele[0] = "Nanosecvente";
	denumireTipuriStele[1] = "Nanogigante";
	denumireTipuriStele[2] = "Supernovele";
	Galaxie galaxie(1, "Andromeda", 3, denumireTipuriStele);

	/*planeta.scrieInFisierBinar(f);
	stea.scrieInFisierBinar(f);
	galaxie.scrieInFisierBinar(f);
	f.close();*/

	fstream g("Astronomie.dat", ios::in | ios::binary);
	planeta.citesteDinFisierBinar(g);
	cout << green << planeta;
    stea.cietsteDinFisierBinar(g);
	cout << red << stea;
	galaxie.citesteDinFisierBinar(g);
	cout << blue << galaxie << intensity;
	g.close();


  }