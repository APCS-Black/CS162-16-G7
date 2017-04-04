#pragma once

#include "DList.h"

class CList : public DList
{
public:
	CList();
	virtual ~CList();

	void Empty();
	Position AddHead(const int& v);
	Position AddTail(const int& v);
	Position InsertBefore(Position position, const int& v);
	Position InsertAfter(Position position, const int& v);
	int RemoveHead();
	int RemoveTail();
	int RemoveAt(Position position);

	// operator
	friend ostream &operator << (ostream &out, const CList& lst);
};