/*
 * list
 *
 *  Created on: 2012-10-19
 *      Author: Administrator
 */

#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#include "../CommonFlag.h"

#define LIST_INCREMENT 10

typedef struct{
	ElemType *elem;	/* 存储空间基址 */
	int length;		/* 当前长度*/
	int capacity;	/* 当前分配的存储容量*/
}ArrayList;

extern Status initArrayList(ArrayList *L, int capacity);
extern Status destroyArrayList(ArrayList *L);
extern Status clearArrayList(ArrayList *L);
extern Status isArrayListEmpty(const ArrayList *L);
extern int lengthOfArrayList(const ArrayList *L);
extern Status getElemFromArrayList(const ArrayList *L, int i, ElemType *e);
extern int locateElemFromArrayList(const ArrayList *L, ElemType e,int (*cmp)(ElemType, ElemType));
extern Status insertItemToArrayList(ArrayList *L, int i, ElemType e);
extern Status removeItemFromArrayList(ArrayList *L, int i, ElemType *e);


#endif /* _ARRAYLIST_H */
