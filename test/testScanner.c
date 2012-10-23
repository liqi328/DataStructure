#include <stdio.h>

#include "../Evaluator/Scanner.h"
#include "test.h"

void testScanner(){
	Scanner scanner;
	Token token;
	char source[300] = {'\0'};;
	printf("run testToken...\nEnter a expression:");
	while(gets(source)){
		initScanner(&scanner, source);
		while(hasNextToken(&scanner)){
			token = nextToken(&scanner);
			if(token.type == NUMBER)
				printf("%d ",token.value);
			else
				printf("%c ",token.value);
		}
		printf("Enter a expression:");
	}
}
