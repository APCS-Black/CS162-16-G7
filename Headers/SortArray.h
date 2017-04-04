#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class SortArray
{
protected:
	struct ENTRY
	{
		int	Key;
		int	Val;
	};
public:
	SortArray(int Capacity = 2);
	virtual ~SortArray();
	void Empty();
	bool IsEmpty();
	int Count();
	int Insert(const int& Key, const int& Val);
	bool Delete(const int& Key);
	bool DeleteAt(int i);
	int GetAtKey(const int& Key, int& Val);
	bool CheckAtKey(const int& Key);
	int UpdateAtKey(const int& Key, const int& Val);
	bool GetAt(int i, int &Key, int &Val);
	bool GetKeyAt(int i, int &Key);
	bool GetValAt(int i, int &Val);
	bool BSearch(const int& Key, int &Pos);

	bool FirstKey(int &Key) const;
	bool LastKey(int &Key) const;
	bool FirstVal(int &Val) const;
	bool LastVal(int &Val) const;

public:
	//for TIterator
	class TIterator
	{
	protected:
		int m_Pos;
	public:
		TIterator()
		{
		}
		virtual ~TIterator()
		{
		}

	public:
		friend class SortArray;
	};

	bool SetHeadPosition(TIterator& It);
	bool SetTailPosition(TIterator& It);
	bool SetCurrPosition(int Pos, TIterator& It);
	bool MoveNext(TIterator& It, int& Key, int& Val);
	bool MovePrev(TIterator& It, int& Key, int& Val);
	bool GetPrev(TIterator& It, int& Key, int& Val);
	bool GetNext(TIterator& It, int& Key, int& Val);
	bool MoveToKey(TIterator& It, const int& Key, int& Val);

	bool IsHead(TIterator& It);
	bool IsTail(TIterator& It);

	bool GetCurrKey(int& Key, TIterator& It);
	bool GetNextKey(int& Key, TIterator& It);
	bool GetPrevKey(int& Key, TIterator& It);

	bool GetCurrVal(int& Val, TIterator& It);
	bool GetNextVal(int& Val, TIterator& It);
	bool GetPrevVal(int& Val, TIterator& It);

	// operator
	friend ostream &operator << (ostream &out, const SortArray& sa);

protected:
	int	m_Capacity;
	int	m_Count;
	ENTRY* m_pData;
};

