#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include "myComplex.h"
using namespace std;
int main() {
	Complex a,b,c;
	int n;
	cout<<"Enter the amount of complex numbers: "<<endl;
	cin >> n;
	double* R = new double[n];
	double* I = new double[n];
	a.Init(a, n, R, I);
	a.Sum(n, R, I);
	system("pause");
	system("cls");
	(b,c).CompareModul(b,c);

	system("pause");
	return 0;
}