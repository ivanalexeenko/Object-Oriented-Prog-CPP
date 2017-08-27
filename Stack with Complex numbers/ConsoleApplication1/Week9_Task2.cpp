#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include "MyStackComplex.h"
using namespace std;
int main() {
	int number;
	cout << "Enter maximum amount of numbers in stack: " << endl;
	cin>>number;
	Stack s(number);
	double* R = new double[number];
	double* I = new double[number];
	Complex a(5, 3), b(1, 1), c(4, 8);
	s.Push(a);
	s.Push(b);
	s.Push(c);
	s.Pop();
	s.Pop();
	a.Show(s.Top());

	
	
	return 0;
}