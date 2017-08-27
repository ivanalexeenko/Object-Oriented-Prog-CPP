#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"StudentS(1-2).h"
#include<typeinfo>
using namespace std;
int main() {
	char a[20];
	cout << "Enter Student's Name: ";
	cin.getline(a, 20);
	cout << endl;
	int g ;
	cout << "Enter Student's Group:";
	cin >> g;
	double m[4];
	double mas[4];
	cout << "Enter Student's Marks For The First Session :";
	for (int i = 0; i < 4; i++) {
		cin >> m[i];
	}
	cout << endl;
	cout << "Enter Student's Marks For The Second Session :";
	for (int i = 0; i < 4; i++) {
		cin >> mas[i];
	}
	cout << endl;
	system("cls");
	SecondSession B(a,g,m,mas);
	B.Show();
	cout << "First Session Average = " << B.FirstSession::Average() << endl;
	cout << "Second Session Average = " << B.SecondSession::Average()<< endl;
	cout << "Overall Average = " << B.OverallAverage() << endl;
	double array[4] = { 10,10,9,10 };
	double array1[4] = { 9,10,9,8 };
	Student St1("Olka",4), St2("Ivan",4);
	FirstSession FS1("Mark", 4, array), FS2("Emily", 7, m);
	SecondSession SS1("Lee", 2, m,mas),SS2("Harvey", 1, mas, array1);
	Student*M[6] = { &St1,&St2,&FS1,&FS2,&SS1,&SS2 };
	Student*S[6];
	FirstSession*FS[6];
	SecondSession *SS[6];
	int c=0, c1=0, c2=0;
	for (int i = 0; i < 6; i++) {
	if (strcmp (typeid(*M[i]).name(),"class Student")==0 ){
		S[c] = M[i];
		c++;
	
	}
	
	else if (strcmp(typeid(*M[i]).name(), "class FirstSession") == 0) {
		FS[c1] = dynamic_cast<FirstSession*>(M[i]);
		c1++;}
	else if (strcmp(typeid(*M[i]).name(), "class SecondSession") == 0) {
		SS[c2] = dynamic_cast<SecondSession*>(M[i]);
		c2++;}
	}
	double totav1 = 0;
	double summse1=0;
	for (int i = 0; i < c1; i++) {
		summse1 += (*FS[i]).Average();
	}
	totav1 = summse1/c1;

	double totav2 = 0;
	double summse2 = 0;
	for (int i = 0; i < c2; i++) {
		summse2 += (*SS[i]).OverallAverage();
		totav2 = summse2 / c2;
	}
	double total = (totav1+ totav2)/2;
	system("pause");
	system("cls");
	cout << "_______________Task number 3(Continuation)_______________" << endl;
	cout << typeid(*S[0]).name()<<":" << endl;
	for (int i = 0; i < c; i++) {
		(*S[i]).Show();
		cout << ".............................." << endl;
	}
	cout << typeid(*FS[0]).name() << ":" << endl;
	for (int i = 0; i < c1; i++) {
		(*FS[i]).Show();
		cout << ".............................." << endl;
	}
	cout << typeid(*SS[0]).name() << ":" << endl;
	for (int i = 0; i < c2; i++) {
		(*SS[i]).Show();
		cout << ".............................." << endl;
	}
	cout << "Total Average of All Marks(3 Different Classes) =" << total << endl;
	system("pause");
	return 0;
}

