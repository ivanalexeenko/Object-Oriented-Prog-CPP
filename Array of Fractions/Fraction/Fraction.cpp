
#define _CRT_SECURE_NO_WARNINGS
#include "Fraction.h"
#include<iostream>
using namespace std;
Fraction::Fraction()
{
	whole = 0;
	fractional = 0.0;
}

Fraction::Fraction(int w, double f)
{
	whole = w;
	if (f >= 1) {
		double *ff = &f;
		fractional = modf(f, ff);
	}
	else fractional = f;

}

bool Fraction::operator<=(Fraction F)
{
	if ((whole + fractional) <= (F.whole + F.fractional))
		return true;
	else return false;
}

bool Fraction::operator>=(Fraction F)
{
	if ((whole + fractional) >= (F.whole + F.fractional))
		return true;
	else return false;
}

Fraction Fraction::operator+(Fraction & f1)
{
	Fraction FFF;
	double sum = whole + f1.whole + f1.fractional + fractional;
	double *s = &sum;
	FFF.fractional = modf(sum, s);
	FFF.whole = *s;
	return FFF;
}

Fraction Fraction::operator-(Fraction & f1)
{
	Fraction FFF;
	double neg = (whole + fractional) - (f1.whole + f1.fractional);
	double *n = &neg;
	FFF.fractional = modf(neg, n);
	FFF.whole = *n;
	return FFF;
}

Fraction Fraction::operator*(Fraction & f1)
{
	Fraction FFF;
	double mult = (whole + fractional) * (f1.whole + f1.fractional);
	double *m = &mult;
	FFF.fractional = modf(mult, m);
	FFF.whole = *m;
	return FFF;

	return Fraction();
}

Fraction & Fraction::operator=(Fraction & f1)
{
	whole = f1.whole;
	fractional = f1.fractional;
	return*this;
}

Fraction Fraction::operator+=(Fraction & f1)
{
	whole += f1.whole;
	fractional += f1.fractional;
	return *this;
}

ostream & operator<<(ostream & os, Fraction & F)
{
	return os << F.whole + F.fractional;
}

istream & operator >> (istream & is, Fraction & F)
{
	return is >> F.whole >> F.fractional;
}
