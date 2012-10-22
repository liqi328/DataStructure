/*
 * LinkedList.c
 *
 *  Created on: 2012-10-20
 *      Author: Administrator
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkedList.h"

/* 建立一个带头结点的单链表，头结点的数据域存储链表的length*/
Status initLinkedList(LinkedList *L){
	*L = (LinkedList)malloc(sizeof(LNode));
	if(!(*L)){
		printf("Error: memory allocation failed.\n");
		exit(OVERFLOW);
	}
	(*L)->next = NULL;
	(*L)->data = 0;/*此单链表的长度*/
	return OK;
}

Status destroyLinkedList(LinkedList *L){
	assert(*L);
	clearLinkedList(*L);
	free(*L);
	*L = NULL;
	return OK;
}

Status clearLinkedList(LinkedList L){
	assert(L);
	LinkedList p = L->next, q = L->next;
	while(p){
		q = p;
		p = p->next;
		free(q);
	}
	L->next = NULL;
	L->data = 0;
	return OK;
}
Status isLinkedListEmpty(const LinkedList L){
	assert(L);
	return lengthOfLinkedList(L) == 0;
}
int lengthOfLinkedList(const LinkedList L){
	assert(L);
	return L->data;
}
Status getElemFromLinkedList(const LinkedList L, int i, ElemType *e){
	assert(L);
	LinkedList p = L;
	if(i < 1 || i > lengthOfLinkedList(L) ){
		printf("Error: invalid index.\n");
		return(ERROR);
	}
	while(i--){
		p = p->next;
	}
	*e = p->data;
	return OK;
}

/* 在L中查找第一个与e相等的元素, 若找到，则返回e在数组中的下标+1, 即e是第几个元素. 否则,返回 -1*/
int locateElemFromLinkedList(const LinkedList L, ElemType e){
	assert(L);
	LinkedList p = L->next;
	int i = 0;
	while(p){
		++i;
		if(p->data == e)return i;
		p = p->next;
	}
	return -1;
}

/* 在L中第i个位置之前插入新的数据元素e, 1<= i <= length(L) + 1*/
Status insertItemToLinkedList(LinkedList L, int i, ElemType e){
	assert(L);
	LinkedList p = L;
	if(i < 1 || i > lengthOfLinkedList(L) + 1){
		printf("Error: invalid index for insertion, index must be in[1,%d],you give %d.\n", lengthOfLinkedList(L),i);
		return ERROR;
	}
	LNode * newNode = (LNode *)malloc(sizeof(LNode));
	while(--i){
		p = p->next;
	}
	newNode->data = e;
	newNode->next = p->next;
	p->next = newNode;
	L->data += 1;
	return OK;
}

Status removeItemFromLinkedList(LinkedList L, int i, ElemType *e){
	assert(L);
	LinkedList p = L, q = NULL;
	if(i < 1 || i > lengthOfLinkedList(L)){
		printf("Error: invalid index for remove.\n");
		return ERROR;
	}
	while(--i){
		p = p->next;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	L->data -= 1;
	free(q);
	return OK;
}
