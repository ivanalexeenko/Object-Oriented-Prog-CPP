#pragma once
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Queue {
private: int *A;
		 int size;
		 int curr;
public:
	Queue() {
		size = 100;
		A = new int[size];
		for (int i = 0; i < size; i++) {
			A[i] = 0;

		}
		curr = 0;

	}
	Queue(int s) {
		if (s <= 0) s = 100;
		size = s;

		A = new int[size];
		for (int i = 0; i < size; i++) {
			A[i] = 0;
		}
		curr = 0;

	}
	~Queue() {
		delete[] A;
	}
	bool IsEmpty() {
		if (curr <= 0) return true;
		else return false;
	}
	bool IsFull() {
		if (curr >= size) return true;
		else return false;
	}
	int Add(int x) {
		if (curr < size) {
			A[curr++] = x;

		}
		return x;
	}
	int Delete() {
		int x;
		if (curr > 0) {
			x = A[0];
			for (int i = 0; i<curr; i++) {
				A[i] = A[i + 1];
				if (i == (curr - 1)) A[i] = 0;
			}
			curr--;
			return x;
		}
		else return -1;
	}
	void Show() {
		for (int i = 0; i < curr; i++) {
			cout << A[i] << " ";
		}

	}
	int Head() { return A[0]; };
	int Tail() { return A[curr]; };
};
