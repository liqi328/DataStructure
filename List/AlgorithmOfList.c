/*
 * AlgorithmOfList.c
 *
 *  Created on: 2012-10-20
 *      Author: Administrator
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "AlgorithmOfList.h"


/* Algorithm of LinkedList */

/* ��ȡ����������N�����ֵ  */
Status getNthItemFromBack(const LinkedList L, int n, ElemType *e){
	assert(L);
	LinkedList p = L, q = L;
	if(n < 1 || n > lengthOfLinkedList(L)){
		printf("Error: invalid argument of n in function[getNthItemFromBack()].");
		return ERROR;
	}
	while(n--){
		p = p->next;
	}
	while(p){
		p = p->next;
		q = q->next;
	}
	*e = q->data;
	return OK;
}

static Status reverse_1(const LinkedList L){
	LinkedList p = L->next ,q = L;
	L->next = NULL;
	while(p){
		q = p;
		p = p->next;

		q->next = L->next;
		L->next = q;
	}
	return OK;
}

/* ������ת/���� */
Status reverseLinkedList(const LinkedList L){
	return reverse_1(L);
}

/* ��ȡ��������м���ֵ */
Status getMiddleItemFromLinkedList(const LinkedList L, ElemType *e){
	assert(L);
	LinkedList p = L, q = L;
	while(p && p->next){
		p = p->next;
		q = q->next;
		p = p->next;
	}
	if(q == L){
		printf("List is empty, there is not middle Item.\n");
		*e = NULL;
		return ERROR;
	}
	*e = q->data;
	return OK;
}

/* ɾ���������е��ظ�Ԫ�� */
Status removeDuplicateItemFromLinkedList(const LinkedList L){
	assert(L);
	LinkedList p,q,r;
	p = L->next;
	while(p){
		q = p->next;
		r = p;
		while(q){
			if(q->data == p->data){
				r->next = q->next;
				free(q);
				L->data -= 1;
				q = r->next;
			}else
				r = q;
				q = q->next;
		}
		p = p->next;
	}
	return OK;
}

/* �жϵ������Ƿ��л�����, ����end���ػ��Ľ������ */
int hasLoopInLinkedList(const LinkedList L, LinkedList *end){
	assert(L);
	LinkedList p = L->next, q, r;
	int stepOf_p = 0, stepOf_q = 0;
	while(p){
		++stepOf_p;
		stepOf_q = 0;
		q = L;
		while(q != p){
			q = q->next;
			++stepOf_q;
		}
		if(stepOf_p != stepOf_q){
			printf("found loop,which is start at %d.\n",stepOf_q);
			if(end)*end = r;
			return True;
		}
		r = p;
		p = p->next;
	}
	printf("No loop founded.\n");
	if(end)*end = NULL;
	return False;
}

/* Ϊ����������, ������ڽ��[1,length(L))*/
Status createLoopInLinkedList(LinkedList L, int start){
	assert(L);
	LinkedList cur = L, tail;
	if(start < 1 || start >= lengthOfLinkedList(L)){
		printf("Error: invalid argument of start in function[createLoopInLinkedList()].\n");
		printf("start must be in [1,%d), you give %d\n",lengthOfLinkedList(L),start);
		return ERROR;
	}
	while(start--){
		cur = cur->next;
	}
	tail = cur;
	while(tail->next){
		tail = tail->next;
	}
	tail->next = cur;
	return OK;
}

/* ����������еĻ�*/
Status removeLoopInLinkedList2(LinkedList L){
	assert(L);
	LinkedList endNode;
	if(hasLoopInLinkedList(L, &endNode)){
		printf("remove loop success,which data is  %d.\n",endNode->next->data);
		endNode->next = NULL;
		return True;
	}
	printf("No loop founded.\n");
	return False;
}
Status removeLoopInLinkedList(LinkedList L){
	assert(L);
	LinkedList p = L->next, q, r = L;
	int stepOf_p = 0, stepOf_q = 0;
	while(p){
		++stepOf_p;
		stepOf_q = 0;
		q = L;
		while(q != p){
			q = q->next;
			++stepOf_q;
		}
		if(stepOf_p != stepOf_q){
			printf("remove loop success,which is start at %d.\n",stepOf_q);
			r->next = NULL;
			return True;
		}
		r = p;
		p = p->next;
	}
	printf("No loop founded.\n");
	return False;
}


static Status endedOfLinkedList(LinkedList L, LinkedList *end){
	assert(L);
	assert(end);
	LinkedList p = L;
	while(p->next){
		p = p->next;
	}
	*end = p;
	return True;
}
/* �ж������������Ƿ��ཻ*/
int isTwoLinkeListIntersection(LinkedList A, LinkedList B){
	LinkedList endA, loopStartA;
	LinkedList endB, loopStartB;
	LinkedList tmp;
	int hasLoopA, hasLoopB;
	hasLoopA = hasLoopInLinkedList(A, &loopStartA);
	hasLoopB = hasLoopInLinkedList(B, &loopStartB);
	if(hasLoopA != hasLoopB){
		/* ���һ���������л�������һ��û�л�������������һ�����ཻ*/
		return False;
	}else if(!hasLoopA){
		/* ����������û�л����������ཻ�Ļ�����������ཻ�㿪ʼ������β����ȡ���ˣ�ֻ��Ƚϱ�β�Ƿ���ͬ*/
		endedOfLinkedList(A, &endA);
		endedOfLinkedList(B, &endB);
		return endA == endB;
	}else{
		/* �����������л����������ཻ��������ĵ���ʼ��㣬������һ�����ڣ�(��������һ����)*/
		tmp = loopStartA->next;
		while( tmp != loopStartA){
			if(tmp == loopStartB)return True;
			tmp = tmp->next;
		}
	}
	return False;
}


