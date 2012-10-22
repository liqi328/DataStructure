/*
 * testMinStack.c
 *
 *  Created on: 2012-10-22
 *      Author: Administrator
 */

#include <stdio.h>
#include <stdlib.h>
#include "../Stack/MinStack.h"
#include "test.h"

void printMinStack(const MinStack *S){
	MinElem *p = S->base;
	printf("CurrentMin : %d\n", (S->top - 1)->min);
	for(;p<S->top;++p){
		printf("%d," ,p->data);
	}
	printf("\n");
}

void testMinStack(){
	int i = 0;
	MinStack S;
	MinElem e;
	initMinStack(&S);
	printMinStack(&S);
	for(i=0;i<18;++i){
		e.data = rand() % (1000 - 30) + 30;
		pushMinStack(&S, e);
	}
	printMinStack(&S);

	for(i=0;i<10;++i){
		e.data = rand() % (20) + 2;
		pushMinStack(&S, e);
	}
	printMinStack(&S);

	for(i=0;i<19;++i){
		popMinStack(&S, &e);
		printMinStack(&S);
	}
}
