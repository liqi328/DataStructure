/*
 * testArrayList.c
 *
 *  Created on: 2012-10-22
 *      Author: Administrator
 */


#include <stdio.h>
#include "../List/ArrayList.h"
#include "test.h"

void printArrayList(const ArrayList *L){
	int i=0;
	printf("\n------------------------\n");
	printf("Capacity = %d, Length = %d, [ ", L->capacity, L->length);
	for(i=0;i<L->length;++i){
		printf("%d, ",L->elem[i]);
	}
	printf(" ]\n------------------------\n");
}


int testArrayList(){
	int i;
	ArrayList L;
	initArrayList(&L, 10);
	printf("running....\n");
	for(i=0;i<9;++i){
		insertItemToArrayList(&L, i+1, i+1);
	}
	printArrayList(&L);
	for(i=0;i<3;++i){
		insertItemToArrayList(&L, (i+1)*2, i+20);
	}
	printArrayList(&L);
	return 1;
}
