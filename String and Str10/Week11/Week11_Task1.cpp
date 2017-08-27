#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include <conio.h>
#include<typeinfo>

using namespace std;
class String {
public:
	char*str;
	int length;
	String() {
		this->length = 100;
		str = new char[length + 1];
		str[0] = 0;
	}
	String(String &A) {
		this->length = A.length;
		this->str = new char[length + 1];
		strcpy(this->str, A.str);
	}
	String(char*s) {
		this->length = strlen(s);
		this->str = new char[length + 1];
		strcpy(str, s);

	}
	String(char symb) {
		this->length = 1;
		*str = symb;
	}
	~String() {
		delete[] str;
	}
	void ClearStr() {
		this->str = "";
	}
	virtual  String& operator +=(const String &s) {
		char x[100];
		strcpy(x, str);
		delete[] str;
		this->length = strlen(str) + strlen(s.str);
		str = new char[length + 1];
		strcpy(str, x);
		strcat(str, s.str);
		return *this;

	}
	virtual String & operator =(String &s) {
		delete[] str;
		this->length = strlen(s.str);
		this->str = new char[length + 1];
		strcpy(this->str, s.str);
		return *this;
	}
	bool operator==(String&a) {
		if (strcmp(str, a.str) == 0)
			return true;
		else return false;



	}


	bool operator >(String&a) {
		if (strcmp(this->str, a.str) == 1)  return true;
		else return false;

	}
	bool  operator <(String&a) {
		if (strcmp(this->str, a.str) == -1)  return true;
		else return false;
	}
	friend ostream& operator <<(ostream& os, String &s) {
		return os << s.str << " ";

	}
	friend istream& operator >> (istream& is, String &s) {
		return is >> s.str;
	}



};
class Str10 : public String {
public:
	unsigned int num;
	char*str;
	int length;
	Str10() :String() {
		num = 0;
	}
	Str10(String &A) : String(A) {
		num = atoi(A.str);

	}
	Str10(char*s) :String(s) {
		num = atoi(s);
	};
	Str10(char symb) : String(symb) {
		num = symb;
	}
	~Str10() {
		delete[] str;
	}
	Str10 operator +(Str10&a) {
		unsigned int c = num + a.num;
		Str10 str;
		str.num = c;
		return str;
	}
	Str10 operator +=(Str10&a) {
		num += a.num;
		return *this;

	}
	Str10  operator =(Str10 &s) {
		num = s.num;
		return *this;
	}
	friend ostream& operator <<(ostream& os, Str10 &s) {
		return os << s.num << " ";
	}
	friend istream& operator >> (istream& is, Str10 &s) {
		return is >> s.num;
	}
	short int StrCompare(Str10&a, Str10&b) {
		if (a.num == b.num) return 0;
		else if (a.num > b.num) return 1;
		else if (a.num < b.num) return -1;

	}
	unsigned int FromStrToNum() {
		unsigned int n = num;
		return n;
	}
	Str10 FromNumToStr(unsigned int n) {
		this->num = n;
		return *this;

	}



};
int main() {
	
	String Andriy("Andriy"); 
	String Sheva("Shevchenko");
	String is("Isalegend");
	Str10 num1("12345678");
	Str10 num2("1517232629"); 
	Str10 num3("21011999");

	String *Array[6] = { &Andriy,&Sheva,&is,&num1,&num2,&num3 };
	String *STR[6];
	Str10 *STR_10[6];
	short int c1 = 0, c2 = 0;
	for (int i = 0; i < 6; i++) {
		if (strcmp(typeid(*Array[i]).name(), "class String") == 0) {
			STR[c1] = Array[i];
			c1++;
		}
		else if (strcmp(typeid(*Array[i]).name(), "class Str10") == 0) {
			STR_10[c2] = dynamic_cast <Str10*>(Array[i]);
			c2++;
		}
	}
	cout << "Array of class String:" << endl;
	for (int i = 0; i < c1; i++) {
		cout << "(" << i + 1 << ")";
		cout << *STR[i] << endl;
	}
	cout << "Sorted Array of class String:" << endl;
	for (int i = 1; i < c1; i++) {
		for (int j = i; j > 0 && *(STR[j-1])>*(STR[j]); j--) {
			swap(*(STR[j-1]),*(STR[j]));
		}
	}
	for (int i = 0; i < c1; i++) {
		cout << "(" << i + 1 << ")";
		cout << *STR[i] << endl;
	}
	String temp;
	for (int i = 0; i < c1; i++) {
		temp += *STR[i];

	}
	cout <<"The summ of Array of class String ="<< temp << endl;
	system("pause");
	system("cls");
	
	cout << "Array of class Str10:" << endl;
	for (int i = 0; i < c2; i++) {
		cout << "(" << i + 1 << ")";
		cout << *STR_10[i] << endl;
	}
	for (int i = 1; i < c2; i++) {
		for (int j = i ; j > 0 && (*STR_10[j-1]).FromStrToNum() >(*STR_10[j]).FromStrToNum(); j--) {
			Str10 tmp = *STR_10[j - 1];
			*STR_10[j - 1] = *STR_10[j];
			*STR_10[j] = tmp;
		}
	}
	cout << "Sorted Array of class Str10:" << endl;
	for (int i = 0; i < c2; i++) {
		cout << "(" << i + 1 << ")";
		cout << *STR_10[i] << endl;
	}
	unsigned int summ = 0;
	for (int i = 0; i < c2; i++) {
		summ += (*STR_10[i]).FromStrToNum();
	
	}
	cout <<"The summ of Array of class Str10 =" <<summ<<endl;
	
	
	
	_getch();
	return 0;
}