#pragma once

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class DynamicArray
{
public:
	explicit DynamicArray(int capacity);
	DynamicArray(DynamicArray const& that);
	~DynamicArray();
	DynamicArray& operator= (DynamicArray const& that);
	int& At(int i);
	int& GetAt(int i) const;
	const int& operator[](int i) const;
	int& operator[](int i);
	int Size() const;
	int UpperBound() const;
	int Capacity() const;
	int Find(const int& value) const;
	void Add(int const& value);
	void Insert(int index, int const& value);
	bool IsEmpty() const;
	void Empty();
	void Remove(int index);
	void Reserve(int newCapacity);
	void Reverse();
	void FreeExtra();
	int* Begin();
	int const* Begin() const;
	int* End();
	int const* End() const;

	// operator
	friend ostream &operator << (ostream &out, const DynamicArray& a);

private:
	int m_Capacity;
	int m_Size;
	int* m_pData;
};
