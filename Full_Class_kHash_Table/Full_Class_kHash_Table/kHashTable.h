#pragma once
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
int Hash(const string &key);
class Element
{
public:
	virtual void accept(class Visitor &v) = 0;
};

class kHashTable:public Element
{
private:
	pair<string, int> *arr;
	int size = 0;
	const int MAX_SIZE = 100;
	int added_elem = 0;
public:
	void accept(Visitor&v);
	PAIR * Begin() const;
	PAIR * End() const;
	friend class HashIterator;
	kHashTable();
	kHashTable(int s);
	kHashTable(const kHashTable &kHT);
	kHashTable(kHashTable&&kHT);
	kHashTable(INIT &list);
	~kHashTable();
	kHashTable &operator = (const kHashTable &kHT);
	kHashTable &operator = (kHashTable &&kHT);

	pair<string, int>&operator[] (int index);
	friend ostream &operator << (ostream &os, kHashTable &kHT);
	friend istream &operator >> (istream &is, kHashTable &kHT);
	bool IsEmpty();
	bool IsFull();
	int Size();
	pair<string, int> *Find(string &str);
	bool IsCellEmpty(int index);
	bool Insert(const string &key,const int value);
	bool Insert(const pair<string, int>&elem);
	bool Insert(const char *str, const int value);
	bool Insert(INIT &args,...);

	template <class ...Args> 
	bool Emplace(const Args...args)
	{
		return Insert(PAIR(args...));
	}
	bool Append(INIT &list);
	void Swap(kHashTable &kHT);
	void Clear();
	bool Delete(string &key);
};

kHashTable CreateHashTable(INIT & list);

class Visitor
{
public:
	virtual void visit(kHashTable *kHT) = 0;
};

class CountSum : public Visitor
{
private:
	double sum;
public:
	void visit(kHashTable *kHT);
	friend ostream &operator << (ostream &os, CountSum &CS);
	double Sum();
};

class ConcatKeys: public Visitor
{
private:
	string str;
public:
	void visit(kHashTable * kHT);
	friend ostream &operator << (ostream &os, ConcatKeys &CK);
	string Str();
};