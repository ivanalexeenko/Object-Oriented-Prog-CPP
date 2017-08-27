#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cmath>
#include "Fraction.h"
using namespace std;
int main() {
	int n;
	cout << "Enter the number of fractions in Array:";
	cin >>n;
	Fraction *F = new Fraction[n];

	for (int i = 0; i < n; i++) {
		int a; double b;
		cout << "Enter " << i + 1 << " fraction:" << endl;
		cout << "whole part: ";
		cin >> a;
		
		cout << "fractional part: ";
		cin >> b;
		Fraction F1(a, b);
		F[i] = F1;
		
	}
	system("cls");
	cout << "Our Array of fractionals is: " << endl;
	for (int i = 0; i < n; i++) {
		cout << F[i] << endl;
	}
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && F[j - 1] >= F[j]; j--)
			swap(F[j - 1], F[j]);
	}
	cout << "----------------------------------" << endl;
	cout << "Sorted Array of fractionals is: " << endl;
	for (int i = 0; i < n; i++) {
		cout << F[i] << endl;
	}
	int l1, l3;
	double l2, l4;
	cout << "----------------------------------" << endl;
	cout << "Enter the left limit of a range(Fraction type): " << endl;
	cout << "whole part: ";
	cin >> l1; 
	cout << "fractional part: ";
	cin >> l2;
	cout << "Enter the right limit of a range(Fraction type): " << endl;
	cout << "whole part: ";
	cin >> l3;
	cout << "fractional part: ";
	cin>> l4;
	Fraction f1(l1,l2), f2(l3,l4);
	Fraction sum;
	cout << "Our Range is = [" << f1 << ";" << f2 << "]" << endl;
	for (int i = 0; i < n; i++) {
		if (F[i] >= f1&&F[i] <= f2) {
			sum += F[i];
		}
	}
	cout << "The sum of our elements satisfying the range = "<<sum << endl;
	system("pause");
	return 0;
}