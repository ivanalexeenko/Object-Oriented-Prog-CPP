#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
class DynamicArray  {
public:
	int number;
	int *Array;
	DynamicArray() {
		number = 10;
		Array = new int[number];
		for (int i=0; i < number; i++) {
			Array[i] = 0;
		}
	}
	DynamicArray(int n, int*A) {
		number = n;
		Array = new int[number];
		for (int i = 0; i < number; i++) {
			Array[i] = A[i];
		}

	}
	DynamicArray operator = (DynamicArray &A) {
		delete[]  Array;
		number = A.number;
		Array = new int[number];
		for (int i = 0; i < A.number; i++) {
			Array[i] = A.Array[i];

		}
		return*this;
	}
	friend ostream& operator << (ostream&os, DynamicArray&A) {
		for (int i = 0; i < A.number; i++) {
			cout<< A.Array[i]<<" ";
			
		}
		return os;
	}
	friend istream &operator >> (istream&is, DynamicArray&A) {
		for (int i = 0; i < A.number; i++) {
			cin >> A.Array[i];
		}
		return is;
	}
	virtual void print() {
		for (int i = 0; i < number; i++) {
			cout << Array[i]<<" ";
		}
	}
	~DynamicArray() {
		delete[] Array;
	}

};
class Stack:public DynamicArray {
public:
	int *A;
	int max;
	int top;
	Stack(int n) {
		max = 10000;
		top = 0;
		if (n <= max) {
			A = new int[n];
			max = n;
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
	void Push(int n) {
		if (top == max)
		{
			cout << "Stack is Full!!!" << endl;
			return;
		}

		else {
			A[top] = n;
			top++;

		}
	}
	int Top() {
		if (top >0)
			return A[top-1];
		else return 0;

	}
	void Pop()
	{
		if (top <= 0)
			cout << "Stack is Empty!!!" << endl;

		else top--;

	}


};

class Queue :public DynamicArray {
public:
	int *Array;
	int tail;
	int head;
	int curr;
	Queue() {
		number = 100;
		Array = new int[number];
		for (int i = 0; i < number; i++) {
			Array[i] = 0;

		}
		head = Array[0];
		curr = 0;
		tail = Array[curr];
	}
	Queue(int s) {
		if (s <= 0) s = 100;
		number = s;

		Array = new int[number];
		for (int i = 0; i < number; i++) {
			Array[i] = 0;
		}
		head = Array[0];
		curr = 0;
		tail = Array[curr];

	}
	 ~Queue() {
		delete[] Array;
	}
	 void Add(int x) {
		 if (curr < number) {
			 Array[curr++] = x;
			 head = Array[0];
				 tail = Array[curr-1];
		 }
	 }
	 void Delete() {
		 if (curr > 0) {
			
			 for (int i = 0; i < curr; i++) {
				 Array[i] = Array[i + 1];
				 if (i == (curr - 1)) Array[i] = 0;
			 }
			 head = Array[0];
			 tail = Array[curr - 1];
			 --curr;

		 }
		 head = Array[0];
		 tail = Array[curr - 1];
	 }

	 int Head() { return Array[0]; };
	 int Tail() { return Array[curr-1]; };

};
int main() {
	Stack S1(10);
	Queue Q1(10);
	DynamicArray*A[4] = { &S1,&Q1};
	ifstream fin("StacksandQueuees.txt");
	int numbers[10];

	Stack *S[2];
	Queue *Q[2];
	int c1 = 0, c2 = 0, x = 0;
	char str[10];
	int a;
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> str;
			if (strcmp(str, "(Stack1)") == 0) {
				for (int i = 0; i < 10; i++) {
					S[c1] = dynamic_cast<Stack*>(A[x]);
					fin >> numbers[i];
					(*S[c1]).Push(numbers[i]);
					numbers[i] = 0;

				}
				c1++;
				x++;
			}
			else if (strcmp(str, "(Queue1)") == 0) {
				for (int i = 0; i < 10; i++) {
					Q[c2] = dynamic_cast<Queue*>(A[x]);
					fin >> numbers[i];
					(*Q[c2]).Add(numbers[i]);
					numbers[i] = 0;
				}
				c2++;
				x++;
			}
			
		}
	}
	cout << "Our Stack is:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << S1.Top()<<" ";
		S1.Pop();
	}
	cout << endl;
	cout << "Our Queue is:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Q1.Head()<<" ";
		Q1.Delete();
	}
	cout << endl;

	system("pause");
	return 0;
}