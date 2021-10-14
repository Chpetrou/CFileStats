//
//  extra_functions.c
//  CFileStats
//
//  Created by Christos Petrou.
//

#include "extra_functions.h"
#include <string.h>

//Cleans a 1D Array
void bufferCleaner (char *word) {
    for (int i = 0; i <sizeof(word); i++) {
        word[i] = 0;
    }
}

//Cleans a 2D Array
void doubleBufferCleaner (int rowSize, int columnSize, char word[][50]) {
    for (int i = 0; i < rowSize; i++) {
        for (int e = 0; e < columnSize; e++) {
            word[i][e] = 0;
        }
    }
}

//C Keywords Array
static char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "define", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if", "include",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "union", "unsigned", "void", "volatile", "while", ""
};

//C Special Characters Array
char notWords[] = {
    ' ', '\n', '\e', '\r', '\t', '\f', '\a', '\v', '\b', '+', '-', '*', '/', '=', ';', ':', ','/*, '.'*/, '&', '<', '>', '?', '|', '{', '}', '[', ']', '"', '\'', '!', '@', '#', '$', '%', '^', '&', '(', ')', '~', '\\', '\0'
};

//Use to find if a word in the array exists
int isKeyword(char *word)
{
    int i;
    
    for (i = 0; keywords[i][0] != '\0'; i++) //While the first character of every word, is not null, loop
        if (strcmp(keywords[i], word) == 0) //Compare each word in the array with the word provided
            return 1; //If they are equal (== 0) return 1, else 0
    
    return 0;
}

int isNotWord = 0;

//Finds if a character is not a special character
int isWord(char ch) {
    isNotWord = 0;
    for (int i = 0; i < sizeof(notWords); i++) {
        if (notWords[i] == ch)
            isNotWord = 1;
    }
    
    return isNotWord;
}

//Finds Size of a 1D Array
int sizeOfArray(char *word) {
    int size = 0;
    int i = 0;

    while (word[i] != 0) {
        size++;
        i++;
    }
    return size;
}

int ff = 0;

//Finds if Word is a Valid Identifier
int isIdentifier(char *word) {
    ff = 0;
    if (word[0] == '_' || (word[0] >= 'a' && word[0] <= 'z') || (word[0] >= 'A' && word[0] <= 'Z')) {
        for (int i = 1; i < sizeOfArray(word); i++) {
            if (word[i] != '_')
                if (word[i] < 'a' || word[i] > 'z')
                    if (word[i] < 'A' || word[i] > 'Z')
                        if (word[i] < '0' || word[i] > '9')
                            ff = 1;
        }
    }
    return ff;
}

//Finds Size of a 2D Array
int doubleSizeOfArray(int rowSize, int columnSize, char word[][50]) {
    int size = 0;
    int i = 0;
    int e = 0;
    
    while (i < rowSize) {
        while (word[i][e] != 0) {
            size++;
            e++;
        }
        i++;
    }
    return size;
}

char firstIdentifier[300][50];
int fflag = 0;
int arrayIndex = 0;

//Finds if Identifier has been seen more than one time
int isSameIdentifier (char *word) {
    for (int i = 0; i < doubleSizeOfArray(300, 50, firstIdentifier); i++) {
        fflag = 0;
        
        for (int e = 0; e < sizeOfArray(word); e++) {
            if (firstIdentifier[i][e] != word[e]) {
                fflag = 1;
            }
        }
        
        if (fflag == 0) {
            break;
        }
    }
    
    if (fflag == 1) {
        for (int a = 0; a < sizeOfArray(word); a++) {
            firstIdentifier[arrayIndex][a] = word[a];
        }
        arrayIndex++;
        return 1;
    }

    return 0;
}
