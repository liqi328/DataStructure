#include <stdio.h>
#include <string.h>
#include "../Evaluator/Scanner.h"
#include "test.h"

#define MAX 301

static char *inputStr(char *s){
	char *find;
	printf("Enter a expression:");
	fflush(stdout);
	find = fgets(s,MAX - 1, stdin);
	find = strchr(s, '\n');
	find ? *find = '\0' : 1;
	return s;
}

void testScanner(){
	Scanner scanner;
	Token token;
	char source[300] = {'\0'};
	printf("run testToken...\n");

	while(strlen(inputStr(source))){
		initScanner(&scanner, source);
		while(hasNextToken(&scanner)){
			token = nextToken(&scanner);
			if(token.type == NUMBER)
				printf("%d ",token.value);
			else
				printf("%c ",token.value);
		}
		printf("\n");
		fflush(stdout);
	}
}
