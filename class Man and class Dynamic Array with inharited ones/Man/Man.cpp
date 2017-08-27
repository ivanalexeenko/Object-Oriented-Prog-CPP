#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include <fstream>
#include<typeinfo>
using namespace std;
class Man {
public:
	char*name;
	int age;
	char *sex;
	int weight;
	Man() {
		name = new char[8];
		name = "Unknown";
		age = 0;
		sex = new char[6];
		sex = "Man";
		weight = 0;
	}
	Man(char* n, int a, char*s, int w) {
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		age = a;
		sex = new char[strlen(s) + 1];
		strcpy(sex, s);
		weight = w;
	}
	~Man() {
		delete[] name;
		delete[] sex;
	}
	void change_name(char*str) {
		delete[] name;
		name = new char[strlen(str) + 1];
		strcpy(name, str);
	}
	void change_age(int ag) {
		age = ag;
	}
	void change_weight(int we) {
		weight = we;
	}
	virtual void Show() {
		cout << "Name:" << name << endl << "Age:" << age << endl << "Sex:" << sex << endl << "Weight:" << weight << " ";
	}
	Man& operator=(Man&m) {


		delete[] name;
		name = new char(strlen(m.name) + 1);
		strcpy(name, m.name);
		age = m.age;
		delete[] sex;
		sex = new char(strlen(m.sex) + 1);
		strcpy(sex, m.sex);
		weight = m.weight;
	}
	virtual bool operator==(Man&m) {
		if (age == m.age)
			return true;
		else return false;
	}
};
class Student :public Man {
public:
	int year;
	Student() :Man() {
		year = 0;
	}
	Student(char* n, int a, char*s, int w, int y) :Man(n, a, s, w) {
		year = y;
	}
	void change_year(int ye) {
		year = ye;

	}
	Student& operator =(Student &s) {

		delete[] name;
		name = new char(strlen(s.name) + 1);
		strcpy(name, s.name);
		age = s.age;
		delete[] sex;
		sex = new char(strlen(s.sex) + 1);
		strcpy(sex, s.sex);
		weight = s.weight;
		year = s.year;
	}
	virtual bool operator==(Student s) {
		if (year == s.year) return true;
		else return false;

	}
	virtual void Show() {
		cout << "Name:" << name << endl << "Age:" << age << endl << "Sex:" << sex << endl << "Weight:" << weight << endl << "Year of study:" << year << " ";
	}
	~Student() {
		delete[] name;
		delete[] sex;
	}

};
void InsertSort(int c1,int *yea) {

	for (int i = 1; i < c1; i++) {
		for (int j = i; j > 0 && yea[j - 1] > yea[j]; j--)
			swap(yea[j - 1], yea[j]);
	}

}

int main() {
	Man*Array[6];
	ifstream fin("Man.txt");
	int i = 0;
	char type;
	while (!fin.eof()) {
		char *n1 = new char[20];
		char *s1 = new char[10];
		int a1, w1, y1;
		fin >> type;
		if (type == 's') {
			fin >> n1 >> a1 >> s1 >> w1 >> y1;
			Array[i++] = new Student(n1, a1, s1, w1, y1);
			(*Array[i - 1]).Show();
			cout << endl;
		}
		else if (type == 'm') {
			fin >> n1 >> a1 >> s1 >> w1;
			Array[i++] = new Man(n1, a1, s1, w1);
			(*Array[i - 1]).Show();
			cout << endl;
		}
	}
	int ag[6];
	int yea[3];
	int am[6];
	int c1 = 0, c2 = 0;
	Student *check;
	for (int i = 0; i < 6; i++) {
		if (strcmp(typeid(*Array[i]).name(), "class Student") == 0) {
			check = dynamic_cast<Student*>(Array[i]);
			yea[c1++] = check->year;
		}
	}
	InsertSort(c1,yea);
	for (int i = 0; i < c1; i++) {
		am[i] = 1;
	}
	int k = 0;
	for (int i = 1; i < c1; i++) {
		if (yea[i] == yea[i - 1]) {
			am[k]++;
		}
		else k++;
	}
	int x = 0;
	for (int i = 0; i <=k; i++) {
		cout << "There is(are) " << am[i] << " student(s),who studied in " << yea[x]<<endl;
		x += am[i];
	}
	for (int i = 0; i < 6; i++) {
		am[i] = 1;
	}
	for (int i = 0; i < 6; i++) {
		ag[i] =(*Array[i]).age ;
	}
	InsertSort(6, ag);
	k = 0;
	for (int i = 1; i < 6; i++) {
		if (ag[i]==ag[i-1]){
			am[k]++;
		}
		else k++;
	}
	 x = 0;
	for (int i = 0; i <= k; i++) {
		cout << "There is(are) " << am[i] << " student(s) aged " << ag[x] << endl;
		x += am[i];
	}

	system("pause");
	return 0;

}