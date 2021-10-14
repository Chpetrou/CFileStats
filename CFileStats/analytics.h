//
//  analytics.h
//  CFileStats
//
//  Created by Christos Petrou.
//

#ifndef analytics_h
#define analytics_h

#include "extra_functions.h"

//MARK: Global Variables

//Word Arrays
extern char word[100];
extern char word2[100];

//MARK: Main Functions

//Counts Number Of Lines
void countNumberOfLines (char ch);

//Counts Number Of Spaces
void countNumberOfSpaces (char ch);

//Counts Number Of Blank Lines
void countNumberOfBlankLines (char ch, char lastch);

//Counts Number Of Comments
void countNumberOfComments (char ch, char lastch);

//Counts Number Of Characters Inside Comments
void countNumberOfCharsInComments (char ch, char lastch);

//Counts Number Of Characters Inside Quotes
void countNumberOfCharsInQuotes (char ch, char lastch);

//Counts Number Of Identifiers And Number Of Characters Inside Identifiers
void countNumberOfIdentifiers (char ch, char lastch);

//Counts Number Of Keywords
void countNumberOfKeywords (char ch, char lastch);

//MARK: Return Functions

//Returns Number Of Lines
int returnLinesNumber (void);

//Returns Number Of Spaces
int returnSpacesNumber (void);

//Returns Number Of Blank Lines
int returnBlankLinesNumber (void);

//Returns Number Of Comments
int returnCommentsNumber (void);

//Returns Number Of Characters Inside Comments
int returnCommentsCharsNumber (void);

//Returns Number Of Characters Inside Quotes
int returnQuotesCharsNumber (void);

//Returns Number Of Keywords
int returnKeywordsNumber (void);

//Returns Number Of Identifiers
int returnIdentifiersNumber (void);

//Returns Number Of Characters Inside Identifiers
int returnIdentifiersCharsNumber (void);

#endif /* analytics_h */
