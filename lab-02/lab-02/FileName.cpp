#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int f = 10;
	int *mut;
	int &fi = f;
	mut = &f;

	cout << "f=" << f << ", fi= " << fi << ". *mut=" << *mut << endl;
	fi = 20;
	cout << "f=" << f << ", fi= " << fi << ". *mut=" << *mut << endl;

	cout << &f << " " << &fi << " " << mut << " " << &mut << " " <<  endl;


	// Vektorok
	//vektor dekralálás (a három csak egy kezdõérték, bármilyen nagy lehet a vektor méter. Dinamikusan szerkezthetõ.
	vector <int> jegyek(3);
	char bet;
	int szam;
	int i;
	for (i = 0; i < 3; i++)
	{

		cout << "Adja meg az " << (i + 1) << ". tanulo jegyet(1-5): ";
		cin >> jegyek[i];

	}

	cout << "akar meg jegyet felvenni? (y/n)" << endl;
	cin >> bet;
	if (bet == 'y')
	{
		do
		{
			cout << "Jegy (1-5): ";
			cin >> szam;
			// vektor érték hozzáadás 
			jegyek.push_back(szam);
			cout << "akar még egyet? (y/n)" << endl;
			cin >> bet;
			i++;

		} while (bet == 'y');
	}
	// vektor méret lekérés
	cout << "Jegyek szama " << jegyek.size() << endl;

	cout << "Osztalyzatok: " << endl;
	for (i = 0; i < jegyek.size(); i++)
	{
	// vektor i-edik elemének a lekérése
		cout << jegyek.at(i) << ", ";
	}

	// törlés
	jegyek.pop_back();
	cout << endl << "Osztalyzatok: " << endl;
	for (i = 0; i < jegyek.size(); i++)
	{
		cout << jegyek.at(i) << ", ";
	}
	// kettõ közé beszúrás
	jegyek.insert(jegyek.begin() + 1, 1);
	cout << endl << "Osztalyzatok: " << endl;
	for (i = 0; i < jegyek.size(); i++)
	{
		cout << jegyek.at(i) << ", ";
	}
}