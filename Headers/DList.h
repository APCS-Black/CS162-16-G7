#pragma once

#include <iostream>
#include <fstream>

using namespace std;

typedef void* Position;

class DList
{
protected:
	struct DNode
	{
		DNode* pNext;
		DNode* pPrev;
		int  Data;
	};

public:
	DList();
	DList(const DList& other);
	virtual ~DList();
	
	int GetCount() const;
	bool IsEmpty() const;
	void Empty();
	int GetHead() const;
	int GetTail() const;
	Position AddHead(const int& v);
	Position AddTail(const int& v);
	Position InsertBefore(Position position, const int& v);
	Position InsertAfter(Position position, const int& v);
	int RemoveHead();
	int RemoveTail();
	int RemoveAt(Position position);
	Position Find(const int& v, bool bDir) const;
	Position FindIndex(int index) const;
	void Print();

	// iteration
	Position GetHeadPosition() const;
	Position GetTailPosition() const;
	int GetNext(Position& rPos) const;
	int GetPrev(Position& rPos) const;
	int GetAt(Position position) const;
	void SetAt(Position position, const int& v);

	// operator
	DList operator = (const DList& lst);
	friend ostream &operator << (ostream &out, const DList& lst);

protected:
	Position NewNode();
	void DeleteNode(DNode* pNode);

protected:
	DNode* m_pHead;
	DNode* m_pTail;
	int m_nCount;
};

