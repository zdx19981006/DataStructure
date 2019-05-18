#pragma once
#include"ArrayList.h"
using namespace std;

//2.1
bool Delete_Min(SqList & L, ElemType & min) {  //直接返回只能返回一个值，传参可以返回多个值
	if (L.length == 0)
		return false;
	min = L.data[0];
	int n = 0;
	for (int i = 0; i < L.length; i++)
		if (min > L.data[i]) {
			min = L.data[i];
			n = i;
		}
	L.data[n] = L.data[L.length - 1];
	L.length--;
	return true;
}

//2.2
void Reverse(SqList & L) {
	ElemType a;
	for (int t = 0; t < L.length / 2; t++) {
		a = L.data[t];
		L.data[t] = L.data[L.length - 1 - t];
		L.data[L.length - 1 - t] = a;
	}
}

//2.3
void del_x_1(SqList & L, ElemType x) {
	int k = 0;
	for (int temp = 0; temp < L.length; temp++) {
		if (L.data[temp] == x)
			k++;
		else
			L.data[temp - k] = L.data[temp];
	}
	L.length -= k;
}
void del_x_2(SqList & L, ElemType x) {
	int k = 0;
	for (int temp = 0; temp < L.length; temp++) {
		if (L.data[temp] != x) {
			L.data[k] = L.data[temp];
			k++;
		}
	}
	L.length = k;
}

//2.4 2.5
bool del_s_t2(SqList & L, ElemType s, ElemType t) {
	if (s >= t)
		return false;
	if (L.length == 0)
		return false;
	int z = 0;
	for (int temp = 0; temp < L.length; temp++) {
		if (L.data[temp] >= s && L.data[temp] <= t)
			z++;
		else
			L.data[temp - z] = L.data[temp];
	}
	L.length -= z;
	return true;
}

//2.6
bool Delete_Same(SqList & L) {
	if (L.length == 0)
		return false;
	int k = 0;
	for (int temp = 1; temp < L.length; temp++) {
		if (L.data[temp - 1] == L.data[temp])
			k++;
		else
			L.data[temp - k] = L.data[temp];
	}
	L.length -= k;
	return true;
}
//2.7
bool Merge(SqList & A, SqList & B, SqList & C) {
	if (A.length + B.length > MaxSize)
		return false;
	int a = 0, b = 0;
	C.length = 0;
	while (C.length != A.length + B.length) {
		if (A.data[a] <= B.data[b] && a < A.length || b >= B.length) {
			C.data[C.length] = A.data[a];
			a++;
		}
		else {
			C.data[C.length] = B.data[b];
			b++;
		}
		C.length++;
	}
	return true;
}
//2.8

