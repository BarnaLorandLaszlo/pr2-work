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
	//vektor dekral�l�s (a h�rom csak egy kezd��rt�k, b�rmilyen nagy lehet a vektor m�ter. Dinamikusan szerkezthet�.
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
			// vektor �rt�k hozz�ad�s 
			jegyek.push_back(szam);
			cout << "akar m�g egyet? (y/n)" << endl;
			cin >> bet;
			i++;

		} while (bet == 'y');
	}
	// vektor m�ret lek�r�s
	cout << "Jegyek szama " << jegyek.size() << endl;

	cout << "Osztalyzatok: " << endl;
	for (i = 0; i < jegyek.size(); i++)
	{
	// vektor i-edik elem�nek a lek�r�se
		cout << jegyek.at(i) << ", ";
	}

	// t�rl�s
	jegyek.pop_back();
	cout << endl << "Osztalyzatok: " << endl;
	for (i = 0; i < jegyek.size(); i++)
	{
		cout << jegyek.at(i) << ", ";
	}
	// kett� k�z� besz�r�s
	jegyek.insert(jegyek.begin() + 1, 1);
	cout << endl << "Osztalyzatok: " << endl;
	for (i = 0; i < jegyek.size(); i++)
	{
		cout << jegyek.at(i) << ", ";
	}
}