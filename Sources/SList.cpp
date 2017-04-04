#include "../Headers/SList.h"

SList* Init(void)
{
	SList* psl;

	psl = new SList;
	if (psl == NULL)
		return NULL;
	psl->m_pHead = NULL;
	psl->m_pTail = NULL;
	psl->m_nCount = 0;
	return psl;
}

void Destroy(SList* psl)
{
	Empty(psl);
	delete psl;
}

SNode* AddHead(SList* psl, int Info)
{
	SNode* pNew = new SNode; // cap phat mot node

	if (pNew == NULL)
		return NULL;
	pNew->Data = Info; // gan thong tin vao node
	if (psl->m_pTail == NULL) // danh sach dang rong
		psl->m_pTail = pNew;
	pNew->pNext = psl->m_pHead; // tro vao node dau tien cua danh sach lien ket
	psl->m_pHead = pNew; // node moi tro thanh node dau tien cua danh sach lien ket
	psl->m_nCount++; // tang so luong phan tu len 1

	return pNew; // tra ve node chua thong tin them vao.
}

SNode* AddTail(SList* psl, int Info)
{
	SNode* pNew = new SNode;

	if (pNew == NULL)
		return NULL;
	pNew->pNext = NULL;
	pNew->Data = Info; // gan thong tin vao node
	if (psl->m_pTail != NULL) // dach sach lien ket khong rong
		psl->m_pTail->pNext = pNew;
	else // danh sach lien ket rong
		psl->m_pHead = pNew;
	psl->m_pTail = pNew; // node moi tro thanh node cuoi cung cua danh sach lien ket
	psl->m_nCount++;

	return pNew;
}

SNode* InsertAfter(SList* psl, SNode* pPrev, int Info)
{
	if (pPrev == NULL)
		return AddTail(psl, Info);

	SNode* pNew = new SNode;

	if (pNew == NULL)
		return NULL;
	pNew->Data = Info;
	if (pPrev->pNext == NULL) // la phan tu cuoi danh sach lien ket
		psl->m_pTail = pNew;
	pNew->pNext = pPrev->pNext;
	pPrev->pNext = pNew;
	psl->m_nCount++;

	return pNew;
}

int RemoveHead(SList* psl)
{
	SNode*	pOld = psl->m_pHead;
	int retVal = pOld->Data;

	psl->m_pHead = pOld->pNext;
	if (psl->m_pHead == NULL)
		psl->m_pTail = NULL;
	delete pOld;
	psl->m_nCount--;
	return retVal;
}

int RemoveTail(SList* psl)
{
	SNode *pCurr = psl->m_pHead, *pPrev = NULL;

	for (; pCurr != NULL; pCurr = pCurr->pNext)
	{
		if (pCurr == psl->m_pTail)
			break;
		pPrev = pCurr;
	}
	return RemoveAt(psl, pPrev, pCurr);
}

int RemoveAt(SList* psl, SNode* pPrev, SNode* pCurr)
{
	int retVal = pCurr->Data;

	// remove pCurr from list
	if (pCurr == psl->m_pHead)
		psl->m_pHead = pCurr->pNext;
	else
		pPrev->pNext = pCurr->pNext;
	if (pCurr == psl->m_pTail)
	{
		psl->m_pTail = pPrev;
		if (psl->m_nCount == 1)
			psl->m_pTail = NULL;
	}
	psl->m_nCount--;
	delete pCurr;
	return retVal;
}

void Empty(SList* psl)
{
	SNode* pNode;
	SNode* pNext;

	pNode = psl->m_pHead;
	while (pNode != NULL)
	{
		pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}
	psl->m_nCount = 0;
	psl->m_pHead = NULL;
	psl->m_pTail = NULL;
}

int Count(SList* psl)
{
	return psl->m_nCount;
}

bool IsEmpty(SList* psl)
{
	return psl->m_nCount == 0;
}

int GetHead(SList* psl)
{
	return psl->m_pHead->Data;
}

int GetTail(SList* psl)
{
	return psl->m_pTail->Data;
}

SNode* GetHeadPosition(SList* psl)
{
	return psl->m_pHead;
}

int GetNext(SNode*& pNode)
{
	int v = pNode->Data;
	pNode = pNode->pNext;
	return v;
}

int GetAt(SNode* pNode)
{
	return pNode->Data;
}

void SetAt(SNode* pNode, int Info)
{
	pNode->Data = Info;
}

SNode* Find(SList* psl, int Info, SNode* startAfter, SNode*& pPrev)
{
	SNode* pNode = (SNode*)startAfter;

	pPrev = NULL;
	if (pNode == NULL)
		pNode = psl->m_pHead;
	else
		pNode = pNode->pNext;

	for (; pNode != NULL; pNode = pNode->pNext)
	{
		if (pNode->Data == Info)
			return pNode;
		pPrev = pNode;
	}
	return NULL;
}

void Print(SList* psl)
{
	SNode* pNode;

	if (IsEmpty(psl))
	{
		cout << "List is empty" << endl;
		return;
	}
	cout << "List count: " << psl->m_nCount << endl;
	pNode = psl->m_pHead;
	cout << "List data: ";
	for (; pNode != NULL; pNode = pNode->pNext)
		cout << pNode->Data << " ";
	cout << endl;
}
