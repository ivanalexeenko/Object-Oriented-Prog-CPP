#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Set.h"
using namespace std;
int main()
{
	Set s1("Heathens");
	Set s2("Health");
	cout << "(String_1):" <<"Heathens" << " ----> (Set_s1): "<<s1 << endl;
	cout << "(String_2):" << "Health" << " ----> (Set_s2): " << s2 << endl;
	Set s3=s1*s2;
	cout << "Set_s3=s1*s2=" << s3 << endl;
	Set s4 = s1 + s2;
	cout << "Set_s4=s1+s2=" << s4 << endl;
	Set s5 = s1 - s2;
	cout << "Set_s5=s1-s2=" << s5 << endl;
	Set s6("HealthyLife");
	cout << "(String_6):" << "HealthyLife" << " ----> (Set_s6): " << s6 << endl;
	boolalpha(cout);
	cout << "s1<s2=" << (s1 < s2) << endl;
	cout << "s2<s1=" << (s2 < s1) << endl;
	cout << "s2<s6=" << (s2 < s6) << endl;
	Set s7(s1);
	cout <<"Set_s7(s1):"<<s7<<"=="<<s1<<"=="<<(s7 == s1)<<endl;


	system("pause");
	return 0;
}