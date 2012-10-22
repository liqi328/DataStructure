#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "../CommonFlag.h"

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkedList;

extern Status initLinkedList(LinkedList *L);
extern Status destroyLinkedList(LinkedList *L);
extern Status clearLinkedList(LinkedList L);
extern Status isLinkedListEmpty(const LinkedList L);
extern int lengthOfLinkedList(const LinkedList L);
extern Status getElemFromLinkedList(const LinkedList L, int i, ElemType *e);
extern int locateElemFromLinkedList(const LinkedList L, ElemType e);
extern Status insertItemToLinkedList(LinkedList L, int i, ElemType e);
extern Status removeItemFromLinkedList(LinkedList L, int i, ElemType *e);


#endif


