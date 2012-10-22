#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"

Status initArrayList(ArrayList *L, int capacity){
	if( capacity <= 0){
		printf("Error: the initial capacity of List must be >= 1.\n");
		return ERROR;
	}
	L->elem = (ElemType *)malloc(capacity * sizeof(ElemType));
	if(!L->elem){
		printf("Error: memory allocation failed.\n");
		exit(OVERFLOW);
	}
	L->length = 0;
	L->capacity = capacity;

	return OK;
}

Status destroyArrayList(ArrayList *L){
	free(L->elem);
	L->elem = NULL;
	return OK;
}

Status clearArrayList(ArrayList *L){
	L->length = 0;
	return OK;
}

Status isArrayListEmpty(const ArrayList *L){
	return L->length == 0;
}

int lengthOfArrayList(const ArrayList *L){
	return L->length;
}

/* 用e返回L中第i个数据元素, 1<= i <= length(L)*/
Status getElemFromArrayList(const ArrayList *L, int i, ElemType *e){
	if(i < 1 || i > L->length){
		printf("Error: Array Index out of bund.\n");
		return ERROR;
	}
	*e = L->elem[i - 1];
	return OK;
}

/* 在L中查找第一个与e相等的元素, 若找到，则返回e在数组中的下标+1, 即e是第几个元素. 否则,返回 -1*/
int locateElemFromArrayList(const ArrayList *L, ElemType e, int (*cmp)(ElemType, ElemType)){
	int i = 0;
	for(i=0;i<L->length;i++){
		if(!(*cmp)(L->elem[i],e)) return i;
	}
	return -1;
}

/* 在L中第i个位置之前插入新的数据元素e, 1<= i <= length(L) + 1*/
Status insertItemToArrayList(ArrayList *L, int i, ElemType e){
	ElemType *newbase;
	int j = 0;
	if(i < 1 || i > L->length + 1){
		printf("Error: illegal insert location.\n");
		return ERROR;
	}
	if(L->length >= L->capacity){
		newbase = (ElemType *)realloc(L->elem, LIST_INCREMENT + L->length * sizeof(ElemType));
		if(!newbase){
			printf("memory reallocation failed.\n");
			exit(OVERFLOW);
		}
		L->elem = newbase;
		L->capacity += LIST_INCREMENT;
	}

	for(j = L->length;j > i - 1; --j){
		L->elem[j] = L->elem[j-1];
	}

	L->elem[i-1] = e;
	L->length += 1;
	return OK;
}

/* 删除第i个元素, 1 <= i <= length(L)*/
Status removeItemFromArrayList(ArrayList *L, int i, ElemType *e){
	ElemType *q,*p;
	if(i < 1 || i > L->length){
		printf("Error: illegal delete location.\n");
		return ERROR;
	}
	*e = L->elem[i - 1];
	p = &(L->elem[i - 1]);
	q = L->elem + L->length - 1;
	for(;p<q;++p)*p = *(p+1);
	L->length -= 1;
	return OK;
}

