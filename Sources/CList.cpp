#include "../Headers/CList.h"

CList::CList() : DList()
{
}

CList::~CList()
{
	Empty();
}

Position CList::AddHead(const int& v)
{
	Position pos;
	pos = DList::AddHead(v);
	if (pos)
	{
		m_pHead->pPrev = m_pTail;
		m_pTail->pNext = m_pHead;
	}
	return pos;
}

Position CList::AddTail(const int& v)
{
	Position pos;
	pos = DList::AddTail(v);
	if (pos)
	{
		m_pHead->pPrev = m_pTail;
		m_pTail->pNext = m_pHead;
	}
	return pos;
}

Position CList::InsertBefore(Position position, const int& v)
{
	Position pos;
	if (position == (Position)m_pHead)
		pos = AddHead(v);
	else
		pos = DList::InsertBefore(position, v);
	return pos;
}

Position CList::InsertAfter(Position position, const int& v)
{
	Position pos;
	if (position == (Position)m_pTail)
		pos = AddTail(v);
	else
		pos = DList::InsertAfter(position, v);
	return pos;
}

int CList::RemoveHead()
{
	int v = DList::RemoveHead();
	m_pHead->pPrev = m_pTail;
	m_pTail->pNext = m_pHead;
	return v;
}

int CList::RemoveTail()
{
	int v = DList::RemoveTail();
	m_pHead->pPrev = m_pTail;
	m_pTail->pNext = m_pHead;
	return v;
}

int CList::RemoveAt(Position position)
{
	int v;

	if (position == (Position)m_pHead)
		v = RemoveHead();
	else
	{
		if (position == (Position)m_pTail)
			v = RemoveTail();
		else
			v = DList::RemoveAt(position);
	}

	return v;
}

void CList::Empty()
{
	DNode* pNode;
	DNode* pNext;
	int c = 0;

	pNode = m_pHead;
	while (pNode && c < m_nCount)
	{
		pNext = pNode->pNext;
		DeleteNode(pNode);
		c++;
		pNode = pNext;
	}
	m_nCount = 0;
	m_pHead = NULL;
	m_pTail = NULL;
}

ostream &operator <<(ostream &out, const CList& lst)
{
	int v, c = 0;
	if (lst.IsEmpty())
	{
		out << "List is empty" << endl;
		return out;
	}
	out << "List count: " << lst.GetCount() << endl;
	out << "List data: " << endl;
	out << "null <-> ";
	Position pos = lst.GetHeadPosition();
	while (pos && c < lst.GetCount())
	{
		v = lst.GetNext(pos);
		out << v << " <-> ";
		c++;
	}
	out << "null";
	out << endl;
	return out;
}
