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

/* 获取单链表倒数第N个结点值  */
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

/* 单链表反转/逆序 */
Status reverseLinkedList(const LinkedList L){
	return reverse_1(L);
}

/* 获取单链表的中间结点值 */
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

/* 删除单链表中的重复元素 */
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

/* 判断单链表是否有环存在, 并用end返回环的结束结点 */
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

/* 为单链表创建环, 环的入口结点[1,length(L))*/
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

/* 解除单链表中的环*/
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
/* 判断两个单链表是否相交*/
int isTwoLinkeListIntersection(LinkedList A, LinkedList B){
	LinkedList endA, loopStartA;
	LinkedList endB, loopStartB;
	LinkedList tmp;
	int hasLoopA, hasLoopB;
	hasLoopA = hasLoopInLinkedList(A, &loopStartA);
	hasLoopB = hasLoopInLinkedList(B, &loopStartB);
	if(hasLoopA != hasLoopB){
		/* 如果一个单链表有环，而另一个没有环，则两单链表一定不相交*/
		return False;
	}else if(!hasLoopA){
		/* 两个单链表没有环，若他们相交的话，则从他们相交点开始，到表尾都相等。因此，只需比较表尾是否相同*/
		endedOfLinkedList(A, &endA);
		endedOfLinkedList(B, &endB);
		return endA == endB;
	}else{
		/* 两个单链表都有环，若他们相交，则链表的的起始结点，都会在一个环内，(即链表共享一个环)*/
		tmp = loopStartA->next;
		while( tmp != loopStartA){
			if(tmp == loopStartB)return True;
			tmp = tmp->next;
		}
	}
	return False;
}


