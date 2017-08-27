
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
class Set {	
private:
	char*str;
	int length;
public:
	Set();
	Set(char*s);
	Set(Set&S);
	~Set();
	Set&operator= (Set&S);
	friend ostream &operator<<(ostream &os,Set&S);
	friend istream&operator >> (istream &is, Set&S);
	Set operator* (Set&S);
	Set operator+ (Set&S);
	Set operator- (Set&S);
	friend bool operator< (Set S1,Set S2);
	friend bool operator== (Set S1,Set S2);
	Set Sort();
	Set DeleteRepeated();




};
