#pragma once
#define MaxSize 50

typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

/*  动态分配的数组
#define InitSize 100   //初始长度
typedef struct {
	int *data;
	int Maxsize, length;
}SeqList;
*/

//(1)插入操作
bool ListInsert(SqList& L, int i, ElemType e) {
	//将元素e插入到顺序表L中的第i个位置
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length >= MaxSize)
		return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return true;
}

//(2)删除操作
bool ListDelete(SqList & L, int i) {
	//删除顺序表L第i个位置的元素
	if (i<1 || i>L.length)
		return false;
	for (int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}

//(3)按值操作
int LocateElem(SqList & L, ElemType i) {
	//查找顺序表中值为e的元素，查找成功返回位序，否则返回0
	for (int j = 0; j < L.length; j++)
		if (L.data[j] == i)
			return j + 1;
	return 0;
}
