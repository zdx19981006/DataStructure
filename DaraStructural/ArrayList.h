#pragma once
#define MaxSize 50

typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

/*  ��̬���������
#define InitSize 100   //��ʼ����
typedef struct {
	int *data;
	int Maxsize, length;
}SeqList;
*/

//(1)�������
bool ListInsert(SqList& L, int i, ElemType e) {
	//��Ԫ��e���뵽˳���L�еĵ�i��λ��
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

//(2)ɾ������
bool ListDelete(SqList & L, int i) {
	//ɾ��˳���L��i��λ�õ�Ԫ��
	if (i<1 || i>L.length)
		return false;
	for (int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}

//(3)��ֵ����
int LocateElem(SqList & L, ElemType i) {
	//����˳�����ֵΪe��Ԫ�أ����ҳɹ�����λ�򣬷��򷵻�0
	for (int j = 0; j < L.length; j++)
		if (L.data[j] == i)
			return j + 1;
	return 0;
}
