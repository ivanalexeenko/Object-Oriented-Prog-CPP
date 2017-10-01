#pragma once
#include "kHashTable.h"
#include <iostream>
#include <initializer_list>
#include <iterator>
#include <string>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS
#define EMPTYNESS_KEY "THIS_CELL_IS_EMPTY"
#define EMPTYNESS_VAL 0
#define INIT initializer_list<pair<string, int>>
#define PAIR pair<string,int>
using namespace std;

class HashIterator
{
private:
	const kHashTable* kHT;
	pair<string, int> *ptr;
public:
	HashIterator();
	HashIterator(pair<string, int> *p);
	HashIterator(const kHashTable &k);
	pair<string, int> &operator*();
	pair<string, int> *operator=(const HashIterator &second);
	pair<string, int> *operator->();
	pair<string, int> *operator++(int);//postfix
	pair<string, int> *operator--(int);//postfix

	pair<string, int> *operator++();//prefix
	pair<string, int> *operator--();//prefix

	bool operator==(const HashIterator &second);
	bool operator!=(const HashIterator &second);

	bool IsDone();
	pair<string, int> *First();
	pair<string, int> *Next();


	void PrintCurrElem();



};