#include "kHashTable.h"
#include "HashIterator.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	kHashTable k(10);
	kHashTable h(10);
	std::string s;
	int a = 0;
	int b = 0;
	cout << "..........Hash Iterator Demonstration.........." << endl;
	cout << "HashTable_1 :" << endl;
	
	for(HashIterator i(k);!i.IsDone(); i.Next())
	{
		s = s + to_string(a++);
		k.Insert(s , b++);
	}
	for (HashIterator i(k); !i.IsDone(); i.Next())
	{
		i.PrintCurrElem();
	}
	cout << endl;
	s = "";
	a = 0;
	b = 15;
	cout << "HashTable_2 :" << endl;
	for (HashIterator i(h); !i.IsDone(); i.Next())
	{
		s = s + to_string(a--);
		h.Insert(s, b--);
	}
	for (HashIterator i(h); !i.IsDone(); i.Next())
	{
		i.PrintCurrElem();
	}	
	cout << endl;
	a = 0;
	b = 0;
	for (HashIterator i(k); !i.IsDone(); i.Next())
	{
		for (HashIterator j(h); !j.IsDone(); j.Next())
		{
			if (i->first == j->first)
			{
				a++;
			}
			if (i->second == j->second)
			{
				b++;
			}

		}
	}
	cout << "Number of equal keys between tables = " << a << endl;
	cout<<"Number of equal values between tables = " << b << endl;
	cout << endl;
	system("pause");

	system("cls");

	cout << "..........Visitor Demonstration.........." << endl;
	kHashTable table_1(3);
	kHashTable table_2(4);
	kHashTable table_3(5);

	table_1.Append(INIT{ {"Hey",19}, {"Yo",10},{"How",12} });
	table_2.Append(INIT{ { "You",23 },{ "Doing?",7 },{ "Maaan",31 },{"blablabla",965} });
	table_3.Append(INIT{ { "God",45 },{ "Save",8 },{ "The",91 },{ "Queen",20},{"Please",3} });

	cout << "HashTable_1:" << endl;
	cout << table_1;

	cout << "HashTable_2:" << endl;
	cout << table_2;

	cout << "HashTable_3:" << endl;
	cout << table_3;

	cout << endl;

	CountSum count_sum;
	count_sum.visit(&table_1);
	cout <<"first_val_sum = " << count_sum.Sum() << endl;

	count_sum.visit(&table_2);
	cout <<"second_val_sum = "<< count_sum.Sum() << endl;

	count_sum.visit(&table_3);
	cout << "third_val_sum = " << count_sum.Sum() << endl << endl;

	ConcatKeys concat_keys;
	concat_keys.visit(&table_1);
	cout <<"first_concat = "<< concat_keys.Str() << endl;

	concat_keys.visit(&table_2);
	cout << "second_concat = " << concat_keys.Str() << endl;

	concat_keys.visit(&table_3);
	cout << "third_concat = " << concat_keys.Str() << endl << endl;



	system("pause");
	return 0;
}