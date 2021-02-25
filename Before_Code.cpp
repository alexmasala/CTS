#include <iostream>
#include <string>
using namespace std;
bool fisierDeschis = true;

enum tipAplicatie { aplicatieWeb = 5, aplicatieMobila = 10, aplicatieDesktop = 15 };

class Autoturism
{
public:
	string marca;
	string model;
	int putere;
	double pret;
	char numarInmatriculare[9];

	Autoturism()
	{
		this->marca = "Necunoscuta";
		this->model = "Necunoscut";
		this->putere = 0;
		this->pret = 5000;
	}

	Autoturism(string marca, string model, int putere)
	{
		this->marca = marca;
		this->model = model;
		this->putere = putere;
		this->pret = 5000;
	}

	~Autoturism()
	{
		fisierDeschis = false;
	}

	void discount(int procent)
	{
		if (procent >= 1 && procent <= 50)
		{
			this->pret = this->pret - (this->pret * procent / 100);
			cout << this->pret;
		}
		else
			cout << "Nu a fost introdus corect discountul";
	}

	void seteazaNumarInmatriculare(char numar[])
	{
		strcpy_s(this->numarInmatriculare, 9, numar);
	}

	char* obtineNumarInmatriculare()
	{
		return this->numarInmatriculare;
		//return nullptr;
	}
};

//ATENTIE!!!
//Sunt punctate doar solutiile originale si individuale
//Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//Signatura functiilor nu se poate modifica, doar continului lor

//1. Functia de mai jos primeste drept parametri doua variabile de tip int
//modificati modalitatea de transmitere a parametrilor astfel incat
//cele doua valori sa fie interschimbate la iesirea din functie
//apelul se va face de forma: inerschimbare(x, y)
//unde x si y sunt 2 intregi
void interschimbare(int& valoare1, int& valoare2)
{
	int aux = valoare1;
	valoare1 = valoare2;
	valoare2 = aux;
}

//2. Functia de mai jos returneaza o variabila de tipul enumeratie
//(tipAplicatie, enum definit mai sus)
//modificati enumul astfel incat acesta sa aiba trei valori posibile
//Acestea sunt: 5 - aplicatieWeb, 10 - aplicatieMobila, 15 - aplicatieDesktop
//functia primeste drept parametru un string dintre cele de mai sus
//("aplicatieWeb", "aplicatieMobila", etc) si returneaza valoarea din enum
//corespunzatoare ei
tipAplicatie modificare_enum(string tip)
{
	if (tip == "aplicatieWeb")
		return aplicatieWeb;
	else
		if (tip == "aplicatieMobila")
			return aplicatieMobila;
		else
			if (tip == "aplicatieDesktop")
				return aplicatieDesktop;
	//return (tipAplicatie)0;
}

//3. Modificati constructorul implicit din clasa Autoturism de mai sus
//acesta va initializa marca cu "Necunoscuta", modelul cu "Necunoscut"
//puterea cu 0 si pretul cu 5000

//4. Modificati constructorul cu 3 parametri: marca, model, putere
//acesta va initializa cele 3 atribute cu valorile primite
//pretul va fi setat la fel ca in celalalt constructor ca fiind 5000

//5. Modificati metoda discount pentru a acorda un discount din pret
//discountul este in procente si poate fi intre 1% si 50%
//functia modifica pretul cu valoarea sa dupa aplicarea discountului

//6. Adaugati un destructor in clasa care seteaza variabila globala
//fisierDeschis pe false

//7. Adaugati clasei un atribut nou numit numarInmatriculare
//acesta este un sir de caractere alocat static de lungime maxima 9
//Modificati metodele seteazaNumarInmatriculare si obtineNumarInmatriculare
//astfel incat sa modifice respectiv sa returneze valoarea acestui nou camp

//8. Functia de mai jos primeste drept parametru un vector static de masini
//reprezentand o flota de autoturisme si numarul sau de elemente
//calculati si returnati valoarea totala a flotei de autoturisme
//prin adunarea preturilor masinilor din flota
double calcul_valoare_flota(Autoturism masini[], int nr_masini)
{
	double s = 0;
	for (int i = 0; i < nr_masini; i++)
	{
		s += masini[i].pret;
	}
	return s;
	//return 0;
}

//9. Functia de mai jos primeste drept parametri un vector alocat dinamic 
//de pointeri la Autoturism impreuna cu numarul de elemente.
//Returnati valoarea celei mai scumpe masini din acel vector
double cea_mai_tare_din_parcare(Autoturism** vector, int nr_masini)
{
	double max = vector[0]->pret; // pointeaza la valorea lui vector[0]

	for (int i = 0; i < nr_masini; ++i) {
		if (vector[i]->pret > max) {
			max = vector[i]->pret;
		}
	}
	return max;
	//return 0.0f;
}

//10. Functia de mai jos primeste drept parametri o matrice
//de pointeri la Autoturism impreuna cu numarul de linii si de coloane
//Matricea reprezinta cum sunt dispuse masinile intr-o parcare
//Un element null inseamna ca pe acel loc de parcare nu este nicio masina
//Functia va returna o matrice a locurilor de parcare astfel
//100 90 60
//0 160 75
//0 90 0
//Explicatii: Parcarea are 3 linii si cate 3 locuri de parcare pe fiecare linie
//Pe prima linie sunt parcate 3 masini cu putere de 100, 90 si respectiv 60 cai putere
//pe a doua linie primul loc este neocupat, iar urmatoarele doua locuri
//sunt ocupate de doua masini cu 160, respectiv 75 de cai putere, s.a.m.d.
int** locuri_libere(Autoturism*** matrice, int nrLinii, int nrColoane)
{
	Autoturism a1, a2, a3, a4, a5, a6;
	a1.putere = 200;
	a2.putere = 180;
	a3.putere = 120;
	a4.putere = 320;
	a5.putere = 150;
	a6.putere = 90;

	matrice = new Autoturism * *[nrLinii];
	for (int i = 0; i < nrLinii; i++)
	{
		matrice[i] = new Autoturism * [nrColoane];
	}

	matrice[0][0] = &a1;
	matrice[0][1] = &a2;
	matrice[0][2] = &a3;
	matrice[1][0] = nullptr;
	matrice[1][1] = &a4;
	matrice[1][2] = &a5;
	matrice[2][0] = nullptr;
	matrice[2][1] = &a6;
	matrice[2][2] = nullptr;

	int** vector = new int* [nrLinii];
	for (int i = 0; i < nrLinii; i++)
	{
		vector[i] = new int[nrColoane];
	}

	for (int i = 0; i < nrLinii; i++)
	{
		for (int j = 0; j < nrColoane; j++)
		{
			if (matrice[i][j] == nullptr)
			{
				vector[i][j] = 0;
			}
			else
				vector[i][j] = matrice[i][j]->putere;
		}
	}

	return vector;

	for (int i = 0; i < nrLinii; i++)
	{
		delete[] matrice[i];
	}
	delete[] matrice;

	if (vector != nullptr)
	{
		for (int i = 0; i < nrLinii; i++)
		{
			delete[] vector[i];
		}
		delete[] vector;
	}

	//return nullptr;
}

int main()
{
	//Playgroud
	//Testati aici functiile dorite si folositi debugger-ul pentru eventualele probleme

	//1.
	int x = 99;
	int y = 200;
	interschimbare(x, y);
	cout << "Cerinta 1: ";
	cout << "x = " << x << " " << "y = " << y << endl;

	//2.
	tipAplicatie rezultat0 = modificare_enum("aplicatieWeb");
	cout << "Cerinta 2: ";
	cout << rezultat0;
	cout << " sau ";
	rezultat0 = modificare_enum("aplicatieMobila");
	cout << rezultat0;
	cout << " sau ";
	rezultat0 = modificare_enum("aplicatieDesktop");
	cout << rezultat0 << endl;

	//5.
	Autoturism a;
	a.pret = 9876;
	cout << "Cerinta 5: ";
	a.discount(0);
	cout << " sau ";
	a.discount(51);
	cout << " sau ";
	cout << " Pretul dupa aplicarea discountului este ";
	a.discount(25);
	cout << endl;

	//7.
	Autoturism a0;
	char nrInreg[9] = "B101ABC";
	a0.seteazaNumarInmatriculare(nrInreg);
	char* rezultat = a0.obtineNumarInmatriculare();
	cout << "Cerinta 7: ";
	cout << rezultat << endl;

	//8.
	Autoturism masini[3];
	Autoturism a7, a8, a10;
	a7.pret = 1111.5;
	a8.pret = 2222.5;
	a10.pret = 3333.4;
	masini[0] = a7; masini[1] = a8; masini[2] = a10;
	double rezultat1 = calcul_valoare_flota(masini, 3);
	cout << "Cerinta 8: ";
	cout << rezultat1 << endl;

	//9.
	Autoturism a11, a12, a13;
	a11.pret = 200.5;
	a12.pret = 200.7;
	a13.pret = 154.5;
	Autoturism** vector = new Autoturism * [3];
	vector[0] = &a11; vector[1] = &a12; vector[2] = &a13;
	double rezultat2 = cea_mai_tare_din_parcare(vector, 3);
	cout << "Cerinta 9: ";
	cout << rezultat2 << endl;


	//10.
	Autoturism a1, a2, a3, a4, a5, a6;
	a1.putere = 200;
	a2.putere = 180;
	a3.putere = 120;
	a4.putere = 320;
	a5.putere = 150;
	a6.putere = 90;
	Autoturism*** matrice = new Autoturism * *[3];
	for (int i = 0; i < 3; i++)
	{
		matrice[i] = new Autoturism * [3];
	}
	matrice[0][0] = &a1;
	matrice[0][1] = &a2;
	matrice[0][2] = &a3;
	matrice[1][0] = nullptr;
	matrice[1][1] = &a4;
	matrice[1][2] = &a5;
	matrice[2][0] = nullptr;
	matrice[2][1] = &a6;
	matrice[2][2] = nullptr;

	int** rezultat3 = locuri_libere(matrice, 3, 3);
	cout << "Cerinta 10:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << rezultat3[i][j] << " ";
		}
		cout << endl;
	}
}