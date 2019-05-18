#pragma once
#include<iostream>
using namespace std;
#define Max_Size 50

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

//采用头插法建立单链表
LinkList List_HeadInsert(LinkList &L) {
	LNode* s; int x;	
	L->next = NULL;
	cin >> x;
	while (x != 9999) {
		s = new LNode();
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
	return L;
}

//

