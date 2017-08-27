#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"MyQueueYeah.h"
using namespace std;

int main() { 
	int n;
	cout << "Enter the number of elements in 1st Queue: ";
	cin >> n;
	Queue X(n);
	for (int i = 0; i < n; i++) {
		int a;
		cout << "Enter the " << i + 1 << " element of Queue:" << endl;
		cin >> a;
		X.Add(a);
		
	}
	
	cout << endl;
	cout << "Enter the number of elements in 2st Queue: ";
	int m;
	cin >> m;
	Queue Y(m);
	for (int i = 0; i < m; i++) {
		int b;
		cout << "Enter the " << i + 1 << " element of Queue:" << endl;
		cin >> b;
		Y.Add(b);

	}
	system("cls");
	system("color 9");
	cout << "Queue X = ";
	X.Show();
	cout << endl;
	cout << "Queue Y = ";
	Y.Show();
	int counter=0;
	while (!X.IsEmpty()&&!Y.IsEmpty())  {
	
		if (X.Head() < Y.Head()) {
			counter++;
			int x, y, z;
			x = X.Head(); y = Y.Head();
			z = x + y;
			X.Delete(); Y.Delete(); 
			X.Add(z);
			
		}
		else {
			counter++;
			int x1, y1,z1; x1 = X.Head(); y1 = Y.Head();
			z1 = x1 - y1;
			X.Delete(); Y.Delete();
	
			Y.Add(z1);
			
		}
		}
	cout << endl;
	if(X.IsEmpty()==true) cout <<"Number of steps to empty Queue X is: "<< counter << endl;
	else if(Y.IsEmpty() == true) cout << "Number of steps to empty Queue Y is: " << counter << endl;

	


	system("pause");
	return 0;
}