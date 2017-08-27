#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Fraction {
private:
	int whole;
	double fractional;
public:
	Fraction();
	Fraction(int w, double f);
	bool operator<=(Fraction f1);
	bool operator>=(Fraction f1);
	Fraction operator+(Fraction&f1);
	Fraction operator-(Fraction&f1);
	Fraction operator*(Fraction&f1);
	Fraction &operator=(Fraction&f1);
	Fraction operator+=(Fraction&f1);
	friend ostream &operator<<(ostream &os, Fraction&F);
	friend istream &operator >> (istream &is, Fraction&F);
	

};