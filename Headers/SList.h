#pragma once

#include <stdio.h>
#include <iostream>

using namespace std;

struct SNode
{
	SNode* pNext;
	int Data;
};

struct SList
{
	SNode* m_pHead;
	SNode* m_pTail;
	int m_nCount;
};

SList* Init(void);
void Destroy(SList* psl);
SNode* AddHead(SList* psl, int Info);
SNode* AddTail(SList* psl, int Info);
SNode* InsertAfter(SList* psl, SNode* pPrev, int Info);
int RemoveHead(SList* psl);
int RemoveTail(SList* psl);
int RemoveAt(SList* psl, SNode* pPrev, SNode* pCurr);
void Empty(SList* psl);
int Count(SList* psl);
bool IsEmpty(SList* psl);
int GetHead(SList* psl);
int GetTail(SList* psl);
SNode* GetHeadPosition(SList* psl);
int GetNext(SNode*& pNode);
int GetAt(SNode* pNode);
void SetAt(SNode* pNode, int Info);
SNode* Find(SList* psl, int Info, SNode* startAfter, SNode*& pPrev);
void Print(SList* psl);
