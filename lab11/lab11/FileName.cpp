#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

struct jatekos
{
	string nev;
	int szul;
	string poszt;
	int meccs, loves, gol;
};
class Labdarugo
{
	int db;
	jatekos* tmb;
public:
	Labdarugo(string filename);
	~Labdarugo();
	void kiir();
	int osszesLoves();
	jatekos legtobbgol();
	void fiatalok();
	jatekos* Egyenlo();

};
int main()
{
	string filename = "jatekosok.txt";
	Labdarugo L(filename);
	L.kiir();
	cout << "Osszes loves: " << L.osszesLoves() << endl;

	jatekos legjobb = L.legtobbgol();
	cout << "Legjobb: " << legjobb.nev << endl;

	L.fiatalok();
	
	jatekos* e = L.Egyenlo();
	cout << endl << e[0].nev << endl;

	return 0;
}

Labdarugo::Labdarugo(string filename)
{
	ifstream be(filename);
		if(be.fail()){
			cout << "Hibas fileolvasas";
			exit(1);
		}
		string sor;
		be >> db;
		tmb = new jatekos[db];
		for (int i = 0; i < db; i++)
		{
			getline(be, tmb[i].nev, ':');
			getline(be, sor, ':');
			tmb[i].szul = stoi(sor);
			getline(be, tmb[i].poszt, ':');

			getline(be, sor, ':');
			tmb[i].meccs = stoi(sor);

			getline(be, sor, ':');
			tmb[i].loves = stoi(sor);

			getline(be, sor);
			tmb[i].gol = stoi(sor);

		}
		be.close();
}

Labdarugo::~Labdarugo()
{
	delete[] tmb;
}

void Labdarugo::kiir()
{
	cout.setf(ios::left);
	cout << setw(12) << "Nev" << setw(6) << "Szul." << setw(8) << "Poszt" << setw(6) << "Meccs" << setw(6) << "Loves" << setw(6) << "Gol" << endl;
	for (int i = 0; i < db; i++)
	{
		cout << setw(12) << tmb[i].nev << setw(6) << tmb[i].szul << setw(8) << tmb[i].poszt << setw(6) << tmb[i].meccs << setw(6) << tmb[i].loves << setw(6) << tmb[i].gol << endl;
	}
}

int Labdarugo::osszesLoves()
{
	int osszes = 0;
	for (int i = 0; i < db; i++)
	{
		osszes = osszes + tmb[i].loves;
	}
	return osszes;
}

jatekos Labdarugo::legtobbgol()
{
	int legjobb = 0;

	for (int i = 1; i < db; i++)
	{
		if (tmb[legjobb].gol < tmb[i].gol)
		{
			legjobb = i;
		}
	}


	return tmb[legjobb];
}

void Labdarugo::fiatalok()
{
	int start = 1995;
	for (int i = 0; i < db; i++)
	{
		if (tmb[i].szul >= start)
		{
			cout << "Fiatal: " << tmb[i].nev << ", " << tmb[i].szul << endl;
		}
	}
}

jatekos* Labdarugo::Egyenlo()
{
	int egynloek = 0;
	jatekos* e = new jatekos [db];
		for (int i = 0; i < db;  i ++)
		{
			for (int  j = 0; j < db; j++)
			{
				if (j != i && tmb[i].gol == tmb[j].gol) {
					e[egynloek] = tmb[i];
					egynloek++;
					
				}
			}

		}

		jatekos* e2 = new jatekos[egynloek];
		for (int i = 0; i < egynloek; i++)
		{
			e2[i] = e[i];

		}
	return e2;
}
