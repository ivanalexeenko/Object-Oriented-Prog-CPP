#define _CRT_SECURE_NO_WARNINGS
#include "Set.h"
#include<iostream>
#include<cstring>
using namespace std;
Set::Set()
{
	length = 30;
	str = new char[length];
	str[0] = 0;
	this->Sort();
	this->DeleteRepeated();
}

Set::Set(char * s)
{
	length = strlen(s) + 1;
	str=new char[length];
	str[0] = 0;
	strcpy(str, s);
	this->Sort();
	this->DeleteRepeated();
}

Set::Set(Set & S)
{
	length = strlen(S.str) + 1;
	str = new char[length];
	str[0] = 0;
	strcpy(str, S.str);
	
}

Set::~Set()
{
	delete[] str;
}

Set & Set::operator=(Set & S)
{
	delete[] str;
	length = strlen(S.str)+1;
	str = new char[length];
	str[0] = 0;
	strcpy(str, S.str);
	return*this;
}

Set  Set::operator*(Set & S)
{
	int c = 0;
	char a[100] = "";
	for (int i = 0; i < strlen(str); i++) {
		for (int j = 0; j < strlen(S.str);j++) {
			if (str[i] == S.str[j]) {
				a[c] = str[i];
				c++;
			}

		}
	}
	Set S1(a);
	return S1;
}

Set  Set::operator+(Set & S)
{
	char a[100];
	strcpy(a, this->str);
	strcat(a, S.str);
	Set S1(a);
	return S1;
	
}

Set  Set::operator-(Set & S)
{
	int check = 0;
	int c = 0;
	char a[100] = "";
	for (int i = 0; i < strlen(str); i++) {
		for (int j = 0; j < strlen(S.str); j++) {
			if (str[i] != S.str[j]) {
				check++;
				if (check == strlen(S.str)) {
					a[c] = str[i];
					c++;
					check = 0;
				}

			}
			else if (str[i] == S.str[j]) {
				check = 0;
				break;
			} 
		}
	}
		Set S1(a);
		return S1;
	
}

bool operator<(Set S1, Set S2)
{
	int c = 0;
	for (int i = 0; i < strlen(S1.str); i++) {
		for (int j = 0; j < strlen(S2.str); j++) {
			if (S1.str[i] == S2.str[j]) {
				c++;
			}
		}
	}
	if(c==strlen(S1.str)) return true ;
	else return false;
}

Set Set::Sort()
{

	for (int i = 1; i < strlen(str); i++) {
		for (int j = i; j > 0 && str[j - 1] > str[j]; j--)
			swap(str[j - 1], str[j]);
	}
	return *this;
}

Set Set::DeleteRepeated()
{
	char a[256];
	int c = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] != str[i + 1]) {
			a[c] = str[i];
			c++;
		}
	}
		a[c] = '\0';
		delete[] str;
		length = strlen(a) + 1;
		str = new char[length];
		str[0] = 0;
		strcpy(str, a);
	
	return *this;
}

ostream & operator<<(ostream & os, Set & S)
{
	return os << S.str;
}

istream & operator >> (istream & is, Set & S)
{
	return is >> S.str;
}
bool operator==(Set S1, Set S2)
{
	if (strcmp(S1.str, S2.str) == 0) {
		return true;
	}
	else return false;
}
