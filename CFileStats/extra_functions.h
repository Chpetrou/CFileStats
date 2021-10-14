//
//  extra_functions.h
//  CFileStats
//
//  Created by Christos Petrou.
//

#ifndef extra_functions_h
#define extra_functions_h

#include <string.h>

//Cleans a 1D Array
void bufferCleaner (char *word);

//Cleans a 2D Array
void doubleBufferCleaner (int rowSize, int columnSize, char word[][50]);

//Use to find if a word in the array exists
int isKeyword(char *word);

//Finds if a character is not a special character
int isWord(char ch);

//Finds Size of a 1D Array
int sizeOfArray(char *word);

//Finds if Word is a Valid Identifier
int isIdentifier(char *word);

//Finds Size of a 2D Array
int doubleSizeOfArray(int rowSize, int columnSize, char word[][50]);

extern char firstIdentifier[300][50];

//Finds if Identifier has been seen more than one time
int isSameIdentifier (char *word);

#endif /* extra_functions_h */
