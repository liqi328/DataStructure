/*
 * StackMain.c
 *
 *  Created on: 2012-10-22
 *      Author: Administrator
 */


#include <stdio.h>
#include <assert.h>
#include "../Stack/Stack.h"
#include "test.h"

static void printStack(const ArrayStack *S){
	assert(S);
	int *p = S->base;
	printf("size = %d,[ ",lengthOfArrayStack(S));
	for(;p < S->top;++p)
		printf("%d,",*p);
	printf("]\n");
}

void testStack(){
	int i = 0;
	ArrayStack S;
	initArrayStack(&S);

	for(i=0;i<18;++i){
		pushArrayStack(&S, i+1);
	}
	printStack(&S);

	pushArrayStack(&S, 21);
	pushArrayStack(&S, 43);
	pushArrayStack(&S, 87);
	pushArrayStack(&S, 433);
	pushArrayStack(&S, 872);
	printStack(&S);

	topOfArrayStack(&S, &i);
	printf("top: %d\n",i);
	popArrayStack(&S, &i);
	printf("pop: %d\n",i);
	printStack(&S);

	topOfArrayStack(&S, &i);
	printf("top: %d\n",i);
	popArrayStack(&S, &i);
	printf("pop: %d\n",i);
	printStack(&S);
}
