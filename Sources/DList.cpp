#include "../Headers/DList.h"

DList::DList()
{
	m_pHead = NULL;
	m_pTail = NULL;
	m_nCount = 0;
}

DList::DList(const DList& other)
{
	m_pHead = NULL;
	m_pTail = NULL;
	m_nCount = 0;

	int v;
	Position pos = other.GetHeadPosition();
	while (pos)
	{
		v = other.GetNext(pos);
		AddTail(v);
	}
}

DList::~DList()
{
	Empty();
}

Position DList::AddHead(const int& v)
{
	DNode* pNew = (DNode*)NewNode();
	if (!pNew)
		return (Position)NULL;
	pNew->pPrev = NULL;
	pNew->Data = v;
	if (m_pHead != NULL)
		m_pHead->pPrev = pNew;
	else
		m_pTail = pNew;
	pNew->pNext = m_pHead;
	m_pHead = pNew;
	m_nCount++;
	return (Position)pNew;
}

Position DList::AddTail(const int& v)
{
	DNode* pNew = (DNode*)NewNode();
	if (!pNew)
		return (Position)NULL;
	pNew->pNext = NULL;
	pNew->Data = v;
	if (m_pTail != NULL)
		m_pTail->pNext = pNew;
	else
		m_pHead = pNew;
	pNew->pPrev = m_pTail;
	m_pTail = pNew;
	m_nCount++;
	return (Position)pNew;
}

Position DList::InsertBefore(Position position, const int& v)
{
	if (position == NULL)
		return AddHead(v); // insert before nothing -> left of the list
							  // Insert it before position
	DNode*	pOld = (DNode*)position;
	DNode* pNew = (DNode*)NewNode();
	if (pNew == NULL)
		return (Position)NULL;
	pNew->pNext = pOld;
	pNew->Data = v;
	if (pOld->pPrev != NULL)
		pOld->pPrev->pNext = pNew;
	else
		m_pHead = pNew;
	pNew->pPrev = pOld->pPrev;
	pOld->pPrev = pNew;
	m_nCount++;
	return (Position)pNew;
}

Position DList::InsertAfter(Position position, const int& v)
{
	if (position == NULL)
		return AddTail(v); // insert after nothing -> right of the list
							  // Insert it before position
	DNode* pOld = (DNode*)position;
	DNode* pNew = (DNode*)NewNode();
	if (pNew == NULL)
		return (Position)NULL;
	pNew->pPrev = pOld;
	pNew->Data = v;
	if (pOld->pNext != NULL)
		pOld->pNext->pPrev = pNew;
	else
		m_pTail = pNew;
	pNew->pNext = pOld->pNext;
	pOld->pNext = pNew;
	m_nCount++;
	return (Position)pNew;
}

int DList::RemoveHead()
{
	DNode*	pOld = m_pHead;
	int v = pOld->Data;

	m_pHead = pOld->pNext;
	if (m_pHead != NULL)
		m_pHead->pPrev = NULL;
	else
		m_pTail = NULL;
	DeleteNode(pOld);
	m_nCount--;
	return v;
}

int DList::RemoveTail()
{
	DNode* pOld = m_pTail;
	int v = pOld->Data;

	m_pTail = pOld->pPrev;
	if (m_pTail != NULL)
		m_pTail->pNext = NULL;
	else
		m_pHead = NULL;
	DeleteNode(pOld);
	m_nCount--;
	return v;
}

int DList::RemoveAt(Position position)
{
	DNode* pOld = (DNode*)position;
	int retVal = pOld->Data;

	// remove pOld from list
	if (pOld == m_pHead)
		m_pHead = pOld->pNext;
	else
		pOld->pPrev->pNext = pOld->pNext;
	if (pOld == m_pTail)
		m_pTail = pOld->pPrev;
	else
		pOld->pNext->pPrev = pOld->pPrev;
	m_nCount--;
	DeleteNode(pOld);
	return retVal;
}

void DList::Empty()
{
	DNode* pNode;
	DNode* pNext;

	pNode = m_pHead;
	while (pNode)
	{
		pNext = pNode->pNext;
		DeleteNode(pNode);
		pNode = pNext;
	}
	m_nCount = 0;
	m_pHead = NULL;
	m_pTail = NULL;
}

int DList::GetCount() const
{
	return m_nCount;
}

bool DList::IsEmpty() const
{
	return m_nCount == 0;
}

int DList::GetHead() const
{
	return m_pHead->Data;
}

int DList::GetTail() const
{
	return m_pTail->Data;
}

Position DList::GetHeadPosition() const
{
	return (Position)m_pHead;
}

Position DList::GetTailPosition() const
{
	return (Position)m_pTail;
}

int DList::GetNext(Position& rPos) const
{
	DNode* pNode = (DNode*)rPos;
	rPos = (Position)pNode->pNext;
	return pNode->Data;
}

int DList::GetPrev(Position& rPos) const
{
	DNode* pNode = (DNode*)rPos;
	rPos = (Position)pNode->pPrev;
	return pNode->Data;
}

int DList::GetAt(Position position) const
{
	DNode* pNode = (DNode*)position;
	return pNode->Data;
}

void DList::SetAt(Position position, const int& newElement)
{
	DNode* pNode = (DNode*)position;
	pNode->Data = newElement;
}

Position DList::Find(const int& v, bool bDir) const
{
	DNode* pNode;

	if (bDir == true)
		pNode = m_pHead;
	else
		pNode = m_pTail;

	if (bDir == true)
	{
		for (; pNode != NULL; pNode = pNode->pNext)
		{
			if (pNode->Data == v)
				return (Position)pNode;
		}
	}
	else
	{
		for (; pNode != NULL; pNode = pNode->pPrev)
		{
			if (pNode->Data == v)
				return (Position)pNode;
		}
	}

	return NULL;
}

Position DList::FindIndex(int index) const
{
	if (index >= m_nCount || index < 0)
		return NULL;

	DNode* pNode = m_pHead;
	while (index--)
		pNode = pNode->pNext;
	return (Position)pNode;
}

void DList::Print()
{
	DNode* pNode;

	if (IsEmpty())
	{
		cout << "List is empty" << endl;
		return;
	}
	cout << "List count: " << m_nCount << endl;
	pNode = m_pHead;
	cout << "List data: " << endl;
	cout << "null <-> ";
	for (; pNode != NULL; pNode = pNode->pNext)
		cout << pNode->Data << " <-> ";
	cout << "null";
	cout << endl;
}

DList DList::operator = (const DList& lst)
{
	int v;
	Empty();
	Position pos = lst.GetHeadPosition();
	while (pos)
	{
		v = lst.GetNext(pos);
		AddTail(v);
	}
	return *this;
}

Position DList::NewNode()
{
	return (Position)new DNode;
}

void DList::DeleteNode(DNode* pNode)
{
	delete pNode;
}

ostream &operator <<(ostream &out, const DList& lst)
{
	int v;
	if (lst.IsEmpty())
	{
		out << "List is empty" << endl;
		return out;
	}
	out << "List count: " << lst.GetCount() << endl;
	out << "List data: " << endl;
	out << "null <-> ";
	Position pos = lst.GetHeadPosition();
	while (pos)
	{
		v = lst.GetNext(pos);
		out << v << " <-> ";
	}
	out << "null";
	out << endl;
	return out;
}
