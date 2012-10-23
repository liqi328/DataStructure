/*
 * Scanner.h
 *
 *  Created on: 2012-10-22
 *      Author: Administrator
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include "Token.h"

#define MAX_LENGTH 300


typedef struct{
	char sourceStr[MAX_LENGTH];
	int index;
	char currentChar;
	Token currentToken;
}Scanner;


extern int initScanner(Scanner *scanner, const char *source);
extern int hasNextToken(const Scanner *scanner);
extern Token nextToken(Scanner *scanner);

#endif /* SCANNER_H_ */
