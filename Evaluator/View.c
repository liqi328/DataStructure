#include <stdio.h>
#include <string.h>
#include "View.h"
#include "Model.h"

#define MAX 301

char * inputExpression(char * s){
	char *find;
	printf("Enter a expression:");
	fflush(stdout);
	find = fgets(s,MAX - 1, stdin);
	find = strchr(s, '\n');
	find ? *find = '\0' : 1;
	return s;
}

int runEvaluator(){
	char expression[MAX] = {'\0'};
	printf("Start.......\n");
	while(strlen(inputExpression(expression))){
		printf("Before format: %s\nAfter  format: ",expression);
		formatExpression(expression);
		printf("value = %.0f\n", evaluateExpression(expression));
	}
	printf("Finish.......\n");
	return 1;
}

