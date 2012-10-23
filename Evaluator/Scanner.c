/*
 * Scanner.c
 *
 *  Created on: 2012-10-22
 *      Author: Administrator
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "Scanner.h"
#include "Token.h"
/*
#define EOE ';'
*/
static int _skipWhiteSpace(Scanner *scanner);
static int _nextChar(Scanner *scanner);
static int _getNextToken(Scanner *scanner);
static TokenValueType _getTokenValue(Scanner *sanner);

char EOE = '#';

int initScanner(Scanner *scanner, const char *source){
	strncpy(scanner->sourceStr, source, MAX_LENGTH - 1);
	scanner->index = 0;
	scanner->currentChar = scanner->sourceStr[0];
	scanner->currentToken.type = UNKNOMN;
	_getNextToken(scanner);
	return 1;
}

int hasNextToken(const Scanner *scanner){
	return scanner->currentToken.type != NULL_TOKEN;
}

Token nextToken(Scanner *scanner){
	Token tmp = {.type = NULL_TOKEN,.value = EOE};
	if(!hasNextToken(scanner)){
		printf("no more tokens.\n");
	}else{
		tmp = scanner->currentToken;
		_getNextToken(scanner);
	}


	return tmp;
}

/* 以下是私有函数*/

/* 跳过空白字符,\t,blank等*/
static int _skipWhiteSpace(Scanner *scanner){
	assert(scanner);
	while(isspace(scanner->currentChar)){
		_nextChar(scanner);
	}
	return 1;
}

static int _nextChar(Scanner *scanner){
	if(scanner->index >= strlen(scanner->sourceStr) - 1){
		scanner->currentChar = EOE;
	}else{
		scanner->index += 1;
		scanner->currentChar = scanner->sourceStr[scanner->index];
	}
	return 1;
}

static int _getNextToken(Scanner *scanner){
	_skipWhiteSpace(scanner);
	if(isdigit(scanner->currentChar)){
		scanner->currentToken.type = NUMBER;
		initToken(&scanner->currentToken, _getTokenValue(scanner));
	}else if(scanner->currentChar == EOE){
		scanner->currentToken.type = NULL_TOKEN;
	}else{
		scanner->currentToken.type = UNKNOMN;
		initToken(&scanner->currentToken, scanner->currentChar);
		_nextChar(scanner);
	}
	return 1;
}

static TokenValueType _getTokenValue(Scanner *scanner){
	TokenValueType num = 0;
	while(isdigit(scanner->currentChar)){
		num = num * 10 + (scanner->currentChar - '0');
		_nextChar(scanner);
	}
	return num;
}


