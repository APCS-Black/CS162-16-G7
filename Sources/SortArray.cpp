#include "../Headers/SortArray.h"

SortArray::SortArray(int Capacity)
{
	m_Capacity = Capacity;
	m_pData = new ENTRY[m_Capacity];
	m_Count = 0;
}

SortArray::~SortArray()
{
	if (m_pData)
		delete[]m_pData;
}

void SortArray::Empty()
{
	m_Count = 0;
}

bool SortArray::IsEmpty()
{
	return m_Count == 0;
}

int SortArray::Count()
{
	return m_Count;
}

int SortArray::Insert(const int& Key, const int& Val)
{
	if (m_Capacity == m_Count)
	{
		ENTRY* pTemp;
		m_Capacity += m_Capacity;
		pTemp = new ENTRY[m_Capacity];
		if (!pTemp)
			return -1;
		memcpy(pTemp, m_pData, m_Count * sizeof(ENTRY));
		delete[] m_pData;
		m_pData = pTemp;
	}
	if (!m_Count)
	{
		m_pData[m_Count].Key = Key;
		m_pData[m_Count++].Val = Val;
		return 0;
	}

	int Pos, nMoveCount;
	bool bFound = BSearch(Key, Pos);
	nMoveCount = m_Count - Pos;
	if (nMoveCount > 0)
		memmove(&m_pData[Pos + 1], &m_pData[Pos], nMoveCount * sizeof(ENTRY));

	m_pData[Pos].Key = Key;
	m_pData[Pos].Val = Val;
	m_Count++;
	return Pos;
}

bool SortArray::Delete(const int& Key)
{
	int	Pos;
	bool bFound = BSearch(Key, Pos);
	if (!bFound)
		return false;
	int nMoveCount = m_Count - (Pos + 1);
	if (nMoveCount > 0)
		memmove(&m_pData[Pos], &m_pData[Pos + 1], nMoveCount * sizeof(ENTRY));
	m_Count--;
	return true;
}

bool SortArray::DeleteAt(int i)
{
	if (i < 0 || i >= m_Count)
		return false;
	int nMoveCount = m_Count - (i + 1);
	if (nMoveCount > 0)
		memmove(&m_pData[i], &m_pData[i + 1], nMoveCount * sizeof(ENTRY));
	m_Count--;
	return true;
}

int SortArray::GetAtKey(const int& Key, int& Val)
{
	int Pos;
	bool bFound = BSearch(Key, Pos);
	if (bFound)
	{
		Val = m_pData[Pos].Val;
		return Pos;
	}
	return -1;
}

bool SortArray::CheckAtKey(const int& Key)
{
	int Pos;

	return BSearch(Key, Pos);
}

int SortArray::UpdateAtKey(const int& Key, const int& Val)
{
	int Pos;
	bool bFound = BSearch(Key, Pos);
	if (bFound)
	{
		m_pData[Pos].Val = Val;
		return Pos;
	}
	return -1;
}

bool SortArray::FirstKey(int &Key) const
{
	if (!m_Count)
		return false;
	Key = m_pData[0].Key;
	return true;
}

bool SortArray::LastKey(int &Key) const
{
	if (!m_Count)
		return false;
	Key = m_pData[m_Count - 1].Key;
	return true;
}

bool SortArray::FirstVal(int &Val) const
{
	if (!m_Count)
		return false;
	Val = m_pData[0].Val;
	return true;
}

bool SortArray::LastVal(int &Val) const
{
	if (!m_Count)
		return false;
	Val = m_pData[m_Count - 1].Val;
	return true;
}

bool SortArray::GetAt(int i, int &Key, int &Val)
{
	if (!m_Count)
		return false;
	Key = m_pData[i].Key;
	Val = m_pData[i].Val;
	return true;
}

bool SortArray::GetKeyAt(int i, int &Key)
{
	if (!m_Count)
		return false;
	Key = m_pData[i].Key;
	return true;
}

bool SortArray::GetValAt(int i, int &Val)
{
	if (!m_Count)
		return false;
	Val = m_pData[i].Val;
	return true;
}

bool SortArray::SetHeadPosition(TIterator& It)
{
	if (!m_Count)
		return false;
	It.m_Pos = 0;
	return true;
}

bool SortArray::SetTailPosition(TIterator& It)
{
	if (!m_Count)
		return false;
	It.m_Pos = m_Count - 1;
	return true;
}

bool SortArray::SetCurrPosition(int Pos, TIterator& It)
{
	if (Pos < 0 || Pos >= m_Count)
		return false;
	It.m_Pos = Pos;
	return true;
}

bool SortArray::MoveNext(TIterator& It, int& Key, int& Val)
{
	if (It.m_Pos > m_Count - 1)
		return false;
	Key = m_pData[It.m_Pos].Key;
	Val = m_pData[It.m_Pos].Val;
	It.m_Pos++;
	return true;
}

bool SortArray::MovePrev(TIterator& It, int& Key, int& Val)
{
	if (It.m_Pos < 0)
		return false;
	Key = m_pData[It.m_Pos].Key;
	Val = m_pData[It.m_Pos].Val;
	It.m_Pos--;
	return true;
}

bool SortArray::GetNext(TIterator& It, int& Key, int& Val)
{
	int pos = It.m_Pos + 1;
	if (pos >= m_Count)
		return false;
	Key = m_pData[pos].Key;
	Val = m_pData[pos].Val;
	return true;
}

bool SortArray::GetPrev(TIterator& It, int& Key, int& Val)
{
	int pos = It.m_Pos - 1;
	if (pos < 0)
		return false;
	Key = m_pData[pos].Key;
	Val = m_pData[pos].Val;
	return true;
}

bool SortArray::MoveToKey(TIterator& It, const int& Key, int& Val)
{
	int Pos;
	bool bFound = BSearch(Key, Pos);
	if (bFound)
		Val = m_pData[Pos].Val;
	It.m_Pos = Pos;
	return bFound;
}

bool SortArray::IsHead(TIterator& It)
{
	if (It.m_Pos != 0)
		return false;
	return true;
}

bool SortArray::IsTail(TIterator& It)
{
	if (It.m_Pos != m_Count - 1)
		return false;
	return true;
}

bool SortArray::GetCurrKey(int& Key, TIterator& It)
{
	if (It.m_Pos > m_Count - 1 || It.m_Pos < 0)
		return false;
	Key = m_pData[It.m_Pos].Key;
	return true;
}

bool SortArray::GetNextKey(int& Key, TIterator& It)
{
	int Pos = It.m_Pos + 1;
	if (Pos > m_Count - 1)
		return false;
	Key = m_pData[Pos].Key;
	return true;
}

bool SortArray::GetPrevKey(int& Key, TIterator& It)
{
	int Pos = It.m_Pos - 1;
	if (Pos < 0)
		return false;
	Key = m_pData[Pos].Key;
	return true;
}

bool SortArray::GetCurrVal(int& Val, TIterator& It)
{
	if (It.m_Pos > m_Count - 1 || It.m_Pos < 0)
		return false;
	Val = m_pData[It.m_Pos].Val;
	return true;
}

bool SortArray::GetNextVal(int& Val, TIterator& It)
{
	int Pos = It.m_Pos + 1;
	if (Pos > m_Count - 1)
		return false;
	Val = m_pData[Pos].Val;
	return true;
}

bool SortArray::GetPrevVal(int& Val, TIterator& It)
{
	int Pos = It.m_Pos - 1;
	if (Pos < 0)
		return false;
	Val = m_pData[Pos].Val;
	return true;
}

bool SortArray::BSearch(const int& Key, int &Pos)
{
	int	m, lb, ub;
	bool bFound = false;

	Pos = -1;
	lb = 0;
	ub = m_Count - 1;
	while (lb <= ub)
	{
		m = (lb + ub) / 2;
		if (Key < m_pData[m].Key)
			ub = m - 1;
		else
		{
			if (m_pData[m].Key < Key)
				lb = m + 1;
			else //found
			{
				bFound = true;
				break;
			}
		}
	}
	if (!bFound) //not found
		Pos = lb;
	else
		Pos = m;
	return bFound;
}

ostream &operator <<(ostream &out, const SortArray& sa)
{
	return out;
}
