#include "HashIterator.h"
HashIterator::HashIterator()
{
	ptr = NULL;
}

HashIterator::HashIterator(pair<string, int>* p)
{
	ptr = p;
}

HashIterator::HashIterator(const kHashTable & k)
{
	ptr = k.arr;
	kHT = &k;
}

pair<string, int>& HashIterator::operator*()
{
	return *ptr;
}

pair<string, int>* HashIterator::operator=(const HashIterator & second)
{
	kHT = second.kHT;
	ptr = second.ptr;
	return ptr;
}

pair<string, int>* HashIterator::operator->()
{
	return ptr;
}

pair<string, int>* HashIterator::operator++(int)
{
	return ptr++;
}

pair<string, int>* HashIterator::operator--(int)
{
	return ptr--;
}

pair<string, int>* HashIterator::operator++()
{
	return ++ptr;
}

pair<string, int>* HashIterator::operator--()
{
	return --ptr;
}

bool HashIterator::operator==(const HashIterator & second)
{
	return ptr == second.ptr;
}

bool HashIterator::operator!=(const HashIterator & second)
{
	return ptr != second.ptr;
}


bool HashIterator::IsDone()
{
	if (ptr == (kHT->End()))
	{
		return true;
	}
	else return false;
}

pair<string, int>* HashIterator::First()
{
	return kHT->Begin();
}

pair<string, int>* HashIterator::Next()
{
	++ptr;
	return ptr;
}



void HashIterator::PrintCurrElem()
{
	cout << "Key: " << ptr->first << "  Value: " << ptr->second << endl;
}
