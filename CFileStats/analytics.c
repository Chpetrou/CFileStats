//
//  analytics.c
//  CFileStats
//
//  Created by Christos Petrou.
//

#include "analytics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//MARK: Global Variables

//Counting Variables
int numberOfLines = 0;

int numberOfSpaces = 0;

int numberOfBlankLines = 0;

int numberOfComments = 0;

int numberOfCharsInComments = 0;

int numberOfKeywords = 0;

int numberOfIdentifiers = 0;

int numberOfCharsInIdentifiers = 0;

int numberOfCharsInQuotes = 0;

//Word Arrays
char word[100];
char word2[100];

int iindex = 0;
int iindex2 = 0;

//Flags
int iAmNotBlank = 0;
int iAmNotComment = 0;
int iAmNotCommentChar = 1;
int iAmNotCommentCharDouble = 1;
int iAmNotQuote = 1;
int iAmNotQuoteSingle = 1;

int ii = 0;
int iii = 0;
int flaging;

//Temp
int CharsCommentsTemp = 0;
int CharsQuotesTemp = 0;
int CharsSingleQuotesTemp = 0;

//MARK: Main Functions

//Counts Number Of Lines
void countNumberOfLines (char ch) {
    if (ch == '\n') {
        numberOfLines++;
    }
}

//Counts Number Of Spaces
void countNumberOfSpaces (char ch) {
    if (ch == ' ') {
        numberOfSpaces++;
    }
}

//Counts Number Of Blank Lines
void countNumberOfBlankLines (char ch, char lastch) {
    if (lastch == '\n' && ch == '\n') {
        numberOfBlankLines++;
    }
    else {
        if (lastch == '\n') iAmNotBlank = 0;
        if (ch != ' ' && ch != '\t' && ch != '\r' && ch != '\n')
            iAmNotBlank = 1;
        if (ch == '\n' && iAmNotBlank == 0)
            numberOfBlankLines++;
    }
}

//Counts Number Of Comments
void countNumberOfComments (char ch, char lastch) {
    if (lastch == '/' && ch == '/') {
        numberOfComments++;
    }
    else if (lastch == '/' && ch == '*') iAmNotComment = 0;
    else if (lastch == '*' && ch == '/' && iAmNotComment == 0) {
        numberOfComments++;
        iAmNotComment = 1;
    }
}

//Counts Number Of Characters Inside Comments
void countNumberOfCharsInComments (char ch, char lastch) {
    if (lastch == '/' && ch == '/')
        iAmNotCommentCharDouble = 0;
    else if (ch != '\n' && iAmNotCommentCharDouble == 0)
        numberOfCharsInComments++;
    if (ch == '\n' || ch == '\r')
        iAmNotCommentCharDouble = 1;
    
    if (lastch == '/' && ch == '*') iAmNotCommentChar = 0;
    else if (lastch != '*' && ch != '/' && iAmNotCommentChar == 0){
        CharsCommentsTemp++;
        //putchar(ch);
        }
    else if (lastch == '*' && ch == '/' && iAmNotCommentChar == 0) {
        iAmNotCommentChar = 1;
        numberOfCharsInComments += CharsCommentsTemp;
        CharsCommentsTemp = 0;
    }
    if (iAmNotCommentChar == 0 && ch == '\n') {
        numberOfCharsInComments--;
    }
}

//Counts Number Of Characters Inside Quotes
void countNumberOfCharsInQuotes (char ch, char lastch) {
    if (ch == '"' && iAmNotQuote == 1) iAmNotQuote = 0;
    else if (ch != '"' && iAmNotQuote == 0){
        CharsQuotesTemp++;
    }
    else if (ch == '"' && iAmNotQuote == 0) {
        iAmNotQuote = 1;
        numberOfCharsInQuotes += CharsQuotesTemp;
        CharsQuotesTemp = 0;
    }
    if (iAmNotQuote == 0 && (ch == '\n' || ch == '\t' || ch == '\r')) {
        CharsQuotesTemp += 2;
    }
    if (ch =='\'' && iAmNotQuoteSingle == 1) iAmNotQuoteSingle = 0;
    else if (ch != '\'' && iAmNotQuoteSingle == 0) CharsSingleQuotesTemp++;
    else if (ch == '\'' && iAmNotQuoteSingle == 0) {
        iAmNotQuoteSingle = 1;
        numberOfCharsInQuotes += CharsSingleQuotesTemp;
        CharsSingleQuotesTemp = 0;
    }
}

//Counts Number Of Identifiers And Number Of Characters Inside Identifiers
void countNumberOfIdentifiers (char ch, char lastch) {
    if (isWord(ch) == 1) {
        if (isKeyword(word2) == 0 && isIdentifier(word2) == 0) {
            if (ch != '\n' && iAmNotCommentCharDouble == 0){
                flaging = 1;
                numberOfIdentifiers--;
            }
            else if (lastch != '*' && ch != '/' && iAmNotCommentChar == 0){
                numberOfIdentifiers--;
                flaging = 1;
            }
            if (ch != '"' && iAmNotQuote == 0){
                numberOfIdentifiers--;
                flaging = 1;
            }
            if (ch != '\'' && iAmNotQuoteSingle == 0){
                numberOfIdentifiers--;
                flaging = 1;
            }
            else if (flaging == 1) {
                flaging = 0;
            }
            else if (flaging == 0) {
                numberOfIdentifiers++;
                numberOfCharsInIdentifiers += sizeOfArray(word2);
//                printf("%d. %s\n", iii, word2);
                
            }
        }
        iii++;
        
        //Reset word
        word2[0] = 0;
        iindex2 = 0;
    }
    else {
        word2[iindex2++] = ch;
        word2[iindex2] = 0;
    }
}

//Counts Number Of Keywords
void countNumberOfKeywords (char ch, char lastch) {
    if (isWord(ch) == 1) {
        if (isKeyword(word) == 1) {
            if (ch != '\n' && iAmNotCommentCharDouble == 0)
                numberOfKeywords--;
            else if (lastch != '*' && ch != '/' && iAmNotCommentChar == 0)
                numberOfKeywords--;
            if (ch != '"' && iAmNotQuote == 0){
                numberOfKeywords--;
            }
            numberOfKeywords++;
        }
        ii++;
        
        //Reset word
        word[0] = 0;
        iindex = 0;
    }
    else {
        word[iindex++] = ch;
        word[iindex] = 0;
    }
}

//MARK: Return Functions

//Returns Number Of Lines
int returnLinesNumber (void) {
    return numberOfLines;
}

//Returns Number Of Spaces
int returnSpacesNumber (void) {
    return numberOfSpaces;
}

//Returns Number Of Blank Lines
int returnBlankLinesNumber (void) {
    return numberOfBlankLines;
}

//Returns Number Of Comments
int returnCommentsNumber (void) {
    return numberOfComments;
}

//Returns Number Of Characters Inside Comments
int returnCommentsCharsNumber (void) {
    return numberOfCharsInComments;
}

//Returns Number Of Characters Inside Quotes
int returnQuotesCharsNumber (void) {
    return numberOfCharsInQuotes;
}

//Returns Number Of Keywords
int returnKeywordsNumber (void) {
    return numberOfKeywords;
}

//Returns Number Of Identifiers
int returnIdentifiersNumber (void) {
    return numberOfIdentifiers;
}

//Returns Number Of Characters Inside Identifiers
int returnIdentifiersCharsNumber (void) {
    return numberOfCharsInIdentifiers;
}
