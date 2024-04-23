#include<iostream>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<string>
using namespace std;

class Eredmeny {
public: Eredmeny(){}
	public: int helyezes;
	public: int fo;
	public: string kat;
	public: string sport;
public: Eredmeny(int h, int f, string k, string s)
{
	helyezes = h;
	fo = f;
	kat = k;
	sport = s;
}
};

class Helsinki {
	private: int db;
	private: Eredmeny *tmb[200];
    public: Helsinki(){
		ifstream be("Helsinki.txt");
		int i = 0;
		tmb = new Eredmeny;

		while (!be.eof())
		{
			int h;
			int f;
			string k;
			string s;
			string temp;

			getline(be, temp, ';');
			h = stoi(temp);
			getline(be, temp, ';');
			f = stoi(temp);
			getline(be, k, ';');
			getline(be, s, ';');
			
			
			
			tmb[i] = Eredmeny(h, f, k, s);
			i++;
			
		}

	}
public: Eredmeny getEredmeny(int i) {
	return tmb[i];
}
};
int main()
{
	Helsinki helsinki;
	cout << helsinki.getEredmeny(0).helyezes << endl;
	return 0;
}