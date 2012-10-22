/*
 * LinkedMain.c
 *
 *  Created on: 2012-10-20
 *      Author: Administrator
 */

#include <stdio.h>
#include <assert.h>
#include "../List/LinkedList.h"
#include "../List/AlgorithmOfList.h"

#include "test.h"

static void printLinkedList(const LinkedList L){
	assert(L);
	LinkedList p = L->next;
	printf("\n------------------------\n");
	printf("Length = %d, [ ", L->data);
	for(;p;p=p->next){
		printf("%d, ",p->data);
	}
	printf(" ]\n------------------------\n");
}

int testLinkedList(){
	int i = 0;
	LinkedList L, endNode;
	initLinkedList(&L);
	getMiddleItemFromLinkedList(L,&i);
	printf("mid Node:%d \n",i);
	for(i=1;i<=5;++i){
		insertItemToLinkedList(L,i,i);
	}
	insertItemToLinkedList(L,3,76);
	insertItemToLinkedList(L,3,4);
	insertItemToLinkedList(L,3,2);
	insertItemToLinkedList(L,8,8);
	printLinkedList(L);
	getMiddleItemFromLinkedList(L,&i);
	printf("mid Node:%d \n",i);

	removeLoopInLinkedList(L);

	/* test loop*/
	createLoopInLinkedList(L, 4);
	hasLoopInLinkedList(L, &endNode);
	removeLoopInLinkedList(L);
	printLinkedList(L);

	removeDuplicateItemFromLinkedList(L);
	printLinkedList(L);

	reverseLinkedList(L);
	printLinkedList(L);
	getMiddleItemFromLinkedList(L,&i);
	printf("mid Node:%d \n",i);

	removeItemFromLinkedList(L, 1, &i);
	printLinkedList(L);
	getMiddleItemFromLinkedList(L,&i);
	printf("mid Node:%d \n",i);

	removeItemFromLinkedList(L, 3, &i);
	printLinkedList(L);
	getMiddleItemFromLinkedList(L,&i);
	printf("mid Node:%d \n",i);

	removeItemFromLinkedList(L, lengthOfLinkedList(L), &i);
	printLinkedList(L);
	clearLinkedList(L);
	printf("empty:%d\n",isLinkedListEmpty(L));
	destroyLinkedList(&L);
	return 1;
}
