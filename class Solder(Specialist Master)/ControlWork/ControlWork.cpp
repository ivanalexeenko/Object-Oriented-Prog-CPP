#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<typeinfo>
using namespace std;
class Solder {
public:
	char *rang;
	virtual  void GetName()  = 0;
	~Solder() { delete[]rang; }

};
class Specialist:public Solder {
public:
	Specialist() {
		rang = new char[20];
		Class = new char[20];
	}
	char*Class;
	void  GetName()  {
		cin.getline(rang, 20);
	}
	void GetClass() {
		cin.getline(Class, 20);
	}
	void Show() {
		cout << "Solder rang: " << rang << endl << "Solder Class: " << Class << endl;
	}
	~Specialist() {
		//delete[]rang;
		//delete[]Class;
	}
	
};
class Master:public Specialist {
public:
	Master() :Specialist() { level = 0; }
	int level;
	void GetName()  {
		cin >> rang;
	}
	 void GetClass() {
		 cin >> Class;
	}
	 void GetLevel() {
		cin >> level;
	}
	 void Show() {
		 cout << "Solder rang: " << rang << endl << "Solder Class: " << Class << endl << "Solder level: " << level << endl;
	}
	~Master() {
		//delete[]rang;
		//delete[]Class;
	}
		
};

int main() {
	Specialist s1,s2;
	Master m1, m2;
	s1.GetName();
	s1.GetClass();


	s2.GetName();
	s2.GetClass();


	m1.GetName();
	m1.GetClass();
	m1.GetLevel();


	m2.GetName();
	m2.GetClass();
	m2.GetLevel();
	system("cls");
	s1.Show();
	s2.Show();
	m1.Show();
	m2.Show();
	Solder *sarr[4] = { &s1,&m1,&s2,&m2 };
	Specialist *spec[2];
	Master *mas[2];
	int c1 = 0, c2 = 0;
	for (int i = 0; i < 4; i++) {
		if (strcmp(typeid(*sarr[i]).name(), "class Specialist") == 0) {
			spec[c1] = dynamic_cast<Specialist*>(sarr[i]);
			c1++;
		}
		else if (strcmp(typeid(*sarr[i]).name(), "class Master") == 0) {
			mas[c2] = dynamic_cast<Master*>(sarr[i]);
			c2++;
		}


	}
	int numofpriv = 0;
	for (int i = 0; i < 2; i++) {
		if (strcmp((*spec[i]).rang, "private") == 0) {
			numofpriv++;
		}
	}
	for (int i = 0; i < 2; i++) {
		if (strcmp((*mas[i]).rang, "private") == 0) {
			numofpriv++;
		}
	}
	cout <<"Number of privates:  "<< numofpriv << endl;
	cout << "Solders of 1st class and 1st level: " << endl;
	for (int i = 0; i < 2; i++) {
		if ((*mas[i]).level == 1 && strcmp((*mas[i]).Class, "first") == 0) {
			(*mas[i]).Show();
		}
	}
	cout << "Sergeants with 2nd class: " << endl;
	for (int i = 0; i < 2; i++) {
		if (strcmp((*spec[i]).rang, "sergeant") == 0&& strcmp((*spec[i]).Class, "second") == 0) {
			(*spec[i]).Show();
		}
	}
	for (int i = 0; i < 2; i++) {
		if (strcmp((*mas[i]).rang, "sergeant") == 0 && strcmp((*mas[i]).Class, "second") == 0) {
			(*mas[i]).Show();
		}
	}

	system("pause");
	return 0;
}