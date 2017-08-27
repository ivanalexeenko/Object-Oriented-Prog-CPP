#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <typeinfo>
#include<cstring>
using namespace std;
class Man {	
public:
	char *surname;
	virtual void Getsurname()=0;
	virtual ~Man() {};
};
class Staff :public Man {
private:
	char *surname;
	char *subject;
public:
	
	Staff() {
		surname = new char[8];
		subject = new char[8];
		strcpy(surname, "Unknown");
		strcpy(subject, "Unknown");
	}
	Staff(char*sur, char*sub) {
		surname = new char[strlen(sur) + 1];
		subject = new char[strlen(sub) + 1];
		strcpy(surname, sur);
		strcpy(subject, sub);

	}
	//~Staff() { 
		//delete[] surname; 
		//delete[] subject;
	//}
	void Getsurname() {
		delete[] surname;
		surname = new char[30];
		cin >> surname;
	}
	friend istream &operator >> (istream &is, Staff &s) {
		return is >> s.surname >> s.subject;
	}
	friend ostream &operator<<(ostream &os, Staff &s) {
		return os << "Staff's surname: " << s.surname << endl << "Subject: " << s.subject << endl;
	}
	char* ShowSurname() {
		return surname;
}
	char* ShowSubject() {
		return subject;
	}

};
class Student :public Man {
	private:
		struct Data{
			char*subject_name;
			int mark;
		};
		Data data;
	public:
		Student() {
			
			data.subject_name = new char[8];
			strcpy(data.subject_name, "Unknown");
			data.mark = 0;

		}
		Student(char*sub, int ma) {
			data.subject_name = new char[strlen(sub) + 1];
			strcpy(data.subject_name,sub);
			data.mark = ma;

		}
		//~Student() {
			//delete[] data.subject_name;
		//}
		void Getsurname() {
			delete[] surname;
			surname = new char[30];
			cin >> surname;
		}
		friend istream &operator >> (istream &is, Student &s) {
			return is >>s.data.subject_name >>s.data.mark ;
		}
		friend ostream &operator<<(ostream &os, Student &s) {
			return os << "Subject: " << s.data.subject_name << endl <<"Mark: " <<s.data.mark<< endl;
		}
		char* ShowSubject() {
			return data.subject_name;
		}
		int ShowMark() {
			return data.mark;
		}

	};


int main() {
	//FIRST PART OF THE TASK
	Student Mark("MA", 9), Olya("History", 9), Ivan("GA", 6), Nick("History", 8), Bend("ET", 7), Justin("Music", 2);
	const int N1 = 6;
	Student St[N1] = { Mark, Olya, Ivan, Nick, Bend, Justin };
	int exel=0,curr=0,fail=0;
	int c;
	cout << "Enter your selection mark: " << endl;
	cin >> c;
	for (int i = 0; i < N1; i++) {
		if ((St[i]).ShowMark() <= 10 && (St[i]).ShowMark() >= 8) {
			exel++;
		}
		if ((St[i]).ShowMark() == c) {
			curr++;
		}
		if ((St[i]).ShowMark() < 4) {
			fail++;
		}


	}
	cout << "There is(are) " << exel << " student(s) with an excelent mark " << endl;
	cout << "There is(are) " << curr << " student(s) with selected mark " << c << endl;
	cout << "There is(are) " << fail << " student(s),who failed" << endl;
	system("pause");
	system("cls");
	//SECOND PART OF THE TASK
	Staff VP("Dubkov", "Programming"), VI("Bulatov", "MA"), GP("Razmyslovich", "GA"), PI("Zelinsky", "History"),VM("Denisenko","MA");
	const int N2 = 5;
	Staff Stu[N2] = {VP,VI,GP,PI,VM};
	char sub[30];
	cout << "Enter your selection subject: " << endl;
	cin >> sub;
	for (int i = 0; i < N2; i++) {
		if (strcmp((Stu[i]).ShowSubject(), sub) == 0) {
			cout << "Teacher of " << sub << " is " << (Stu[i]).ShowSurname() << endl;
		}
	}
	system("pause");
	system("cls");
	//THIRD PART OF THE TASK
	const int N3 = 4;
	Man*mix[N3] = { &PI,&Olya,&Nick,&Mark };
	Staff *mas1[N3];
	Student *mas2[N3];
	int c1=0, c2=0;
	for (int i = 0; i < N3; i++) {
		if (strcmp(typeid(*mix[i]).name(), "class Staff") == 0) {
			mas1[c1++] = dynamic_cast<Staff*>(mix[i]);
		}
		else if (strcmp(typeid(*mix[i]).name(), "class Student") == 0) {
			mas2[c2++] = dynamic_cast<Student*>(mix[i]);
		}

	}
	for (int i = 0; i < c1; i++) {
		cout << *mas1[i];
	}
	cout << "This subject marks: " << endl;
	double sum = 0;
	for (int i = 0; i < c2; i++) {
		if (strcmp((*mas2[i]).ShowSubject(), (*mas1[0]).ShowSubject()) == 0) {
			sum += (*mas2[i]).ShowMark();
			cout << (*mas2[i]).ShowMark() << " ";
		}
	}
	cout << endl;
	//успеваемость
	cout << "Progress is: " << (sum / 2) * 10 << "%" << endl;

	system("pause");
	return 0;
}