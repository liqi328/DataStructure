/*
 * Model.c
 *
 *  Created on: 2012-10-23
 *      Author: Administrator
 */

#include <stdio.h>
#include "../Stack/Stack.h"
#include "Model.h"
#include "Token.h"
#include "scanner.h"

/* 判段两个操作符的优先级 */
static char precede(char op1, char op2);
static double _evaluate(int a, char op, int b);


char * formatExpression(char * s){
	Scanner scanner;
	Token token;
	initScanner(&scanner, s);
	while(hasNextToken(&scanner)){
		token = nextToken(&scanner);
		if(token.type == NUMBER)
			printf("%d ",token.value);
		else
			printf("%c ",token.value);
	}
	printf("\n");
	fflush(stdout);
	return s;
}

double evaluateExpression(char *source){
	ArrayStack operatorStack;
	ArrayStack operandStack;
	Scanner scanner;
	Token token;
	int topOperator = '#';
	int flagNextToken = 1;
	int a,b;
	initScanner(&scanner, source);
	initArrayStack(&operatorStack);
	initArrayStack(&operandStack);
	pushArrayStack(&operatorStack, '#');

	while(hasNextToken(&scanner) || topOperator != '#'){
		if(flagNextToken)
			token = nextToken(&scanner);

		if(token.type == NUMBER){
			pushArrayStack(&operandStack, token.value);
			flagNextToken = 1;
		}else{
			topOfArrayStack(&operatorStack, &topOperator);
			switch(precede(topOperator, token.value)){
				case '<':
					pushArrayStack(&operatorStack, token.value);
					flagNextToken = 1;
					break;
				case '>':
					popArrayStack(&operatorStack, &topOperator);
					flagNextToken = 0;
					popArrayStack(&operandStack,&b);
					popArrayStack(&operandStack, &a);

					pushArrayStack(&operandStack,(int)_evaluate(a,topOperator,b));
					break;
				case '=':
					popArrayStack(&operatorStack, &topOperator);
					flagNextToken = 1;
					break;
				default:
					printf("expression syntax error.\n");
					return -1.0;
			}
		}
		topOfArrayStack(&operatorStack, &topOperator);
	}
	a = -1;
	popArrayStack(&operandStack, &a);
	return a;
}

int evaluationStatus(){
	return 1;
}


static double _evaluate(int a, char op, int b){
	double result = -1.0;
	switch(op){
		case '+': result =  a + b + 0.0; break;
		case '-': result =  a - b + 0.0; break;
		case '*': result =  a * b + 0.0; break;
		case '/': result =  a / b + 0.0; break;
		default:
			printf("Unknown operator:%c",op);break;
	}
	return result;
}


/* 判读两个操作符的优先级 */
static char precede(char op1, char op2){
	/*     优先级表,行=op1,列 = op2
	 *      +   -   /   *   (   )   #
	 *  +   >   >   <   <   <   >   >
	    -   >   >   <   <   <   >   >
	    /   >   >   >   >   <   >   >
	    *   >   >   >   >   <   >   >
	    (   <   <   <   <   <   =   error
	    )   >   >   >   >   e   >   >
	    #   <   <   <   <   <   e   =
	 * */

	char operator[] = "+-/*()#";
	char table[8][8] = {
			{'>','>','<','<','<','>','>','e'},
			{'>','>','<','<','<','>','>','e'},
			{'>','>','>','>','<','>','>','e'},
			{'>','>','>','>','<','>','>','e'},
			{'<','<','<','<','<','=','e','e'},
			{'>','>','>','>','e','>','>','e'},
			{'<','<','<','<','<','e','=','e'},
			{"eeeeeee"}
	};
	int i,index1 = 7, index2 = 7;
	for(i=0;i<strlen(operator);++i){
		index1 = operator[i]== op1? i : index1;
		index2 = operator[i]== op2? i : index2;
	}
	return table[index1][index2];
}
