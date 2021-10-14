//
//  main.c
//  CFileStats
//
//  Created by Christos Petrou.
//

#include "analytics.h"
#include "terminal_functions.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
    //Current and Last Characters
    char ch = '\n';
    char lastch = '\n';

    
    //File Path
    char *source_file_path = "";
    char *save_file_path = "";
    command_line_arguments command = TERM_ARG;
    if (!get_file_path(argc, argv, &source_file_path, &save_file_path, &command))
        exit(0);

    //Opens File For Reading
    FILE *fptr;
    fptr = fopen(source_file_path, "r");

    //Shows Error If File Not Found
    if (fptr == (void *)0) {
        printf("Error: File not found!\n");
        exit(0);
    }
    
    //Calls The Cleaner Functions To Clean The Arrays
    bufferCleaner(word);
    bufferCleaner(word2);
    doubleBufferCleaner(300, 50, firstIdentifier);

    //Opens File For Reading
    fptr = fopen(source_file_path, "r");
    
    //Reads Character Until The End OF File
    while((ch = getc(fptr)) != EOF)
    {
        //Counts Different Statistics
        countNumberOfLines(ch);
        countNumberOfSpaces(ch);
        countNumberOfBlankLines(ch, lastch);
        countNumberOfCharsInQuotes(ch, lastch);
        countNumberOfComments(ch, lastch);
        countNumberOfCharsInComments(ch, lastch);
        countNumberOfIdentifiers(ch, lastch);
        countNumberOfKeywords(ch, lastch);
        
        //Saves Last Character
        lastch = ch;
    }
    
    //Shows the Results in the Preferred Way
    show_results(command, save_file_path);
    return 0;
}
