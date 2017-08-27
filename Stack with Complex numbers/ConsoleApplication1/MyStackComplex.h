#include <iostream>
#include <cmath>
using namespace std;
class Complex {
private: double real;
		 double image;
public:
	Complex(double real, double image, Complex a) { a.real = real; a.image = image; };
	Complex(double re = 0, double im = 0) { real = re; image = im; };
	~Complex() {};
	void Show(Complex a) {
		if (image < 0 && image != -1) {
			cout << a.real << a.image << "i" << endl;
		}
		if (image == 0) cout << a.real << endl;
		if (image > 0 && image != 1) cout << a.real << "+" << a.image << "i" << endl;
		if (image == 1) cout << a.real << "+i" << endl;
		if (image == -1)cout << a.real << "-i" << endl;



	};
	void Init(Complex a, int n, double*R, double*I) {


		for (int i = 0; i < n; i++) {
			cout << "Enter the " << i + 1 << " complex number" << endl;
			cin >> a.real >> a.image;
			R[i] = a.real;
			I[i] = a.image;
			cout << "(Complex " << i + 1 << ")" << "=";
			a.Show(a);
		}



	}
	void Sum(int n, double*R, double*I) {
		Complex s;
		s.real = 0; s.image = 0;
		for (int i = 0; i < n; i++) {
			s.real += R[i];
			s.image += I[i];
		}
		cout << "The summ of complex numbers = ";

		return s.Show(s);

	}
	double Modul(Complex a) {
		return (sqrt(a.real*a.real + a.image*a.image));
	}
	int CompareModul(Complex b, Complex c) {
		cout << "Let's compare 2 complex numbers by the absolute value!" << endl;
		cout << "The 1st complex number is to be compared :";
		cin >> b.real >> b.image;
		b.Show(b);
		cout << "The 2nd complex number is to be compared :";
		cin >> c.real >> c.image;
		c.Show(c);
		cout << "The absolute value(1)= " << b.Modul(b) << endl;
		cout << "The absolute value(2)= " << c.Modul(c) << endl;
		if (b.Modul(b) > c.Modul(c)) { cout << "|1st number|>|2st number|"; return 1; }
		if (b.Modul(b) < c.Modul(c)) { cout << "|1st number|<|2st number|"; return -1; }
		if (b.Modul(b) == c.Modul(c)) { cout << "|1st number|=|2st number|"; return 0; }

	}
	void Copy(Complex a, Complex b) { a.real = b.real; a.image = b.image; }

};
class Stack {
private:
	Complex *A;
	int max;
	int top;
public:
	Stack(int number) {
		max = 10000;
		top = 0;
		if (number <= max) {
			A = new Complex[number];
			max = number;
		}
		else cout << "Stack is full" << endl;

	}
	~Stack() {
		delete[] A;

	}
	bool IsEmpty() {
		if (top <= 0) return true;
		else  return false;
	}
	bool IsFull() {
		if (top == max) return true;
		else return false;
	}
	void Push(Complex n) {
		if (top == max)
		{
			cout << "Stack is Full!!!" << endl;
				return ;
		}
		
		else {
			A[top] = n;
			top++;

		}
	}
	Complex Top() {
		if (top >0)
		return A[--top];
		else return 0;

	}
	void Pop()
	{
		if (top <= 0) 
			cout << "Stack is Empty!!!" << endl;
			
		else top--;
		
	}
	

};
