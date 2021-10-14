//
//  output_functions.c
//  CFileStats
//
//  Created by Christos Petrou.
//

#include "output_functions.h"
#include "analytics.h"
#include <stdio.h>
#include <stdlib.h>

void help_command(void) {
    printf("\nusage: CFileStats [options] <source_file_path>\n");
    printf("Prints the statistics of a C source code file.\n");
    printf("  options:\n");
    printf("    -h, --help                help\n");
    printf("    -t, --term                prints result to terminal (Default)\n");
    printf("    -f, --file <file_path>    prints result to file\n");
}

void error_print(error_types error) {
    switch (error) {
        case INV_ARG:
            printf("Invalid argument\n");
            break;
        case INV_ARG_NUM:
            printf("Invalid argument number\n");
            break;
        case FEW_ARG:
            printf("Too few arguments\n");
            break;
        case MANY_ARG:
            printf("Too many arguments\n");
            break;
        default:
            break;
    }
    help_command();
}

void term_command() {
    printf("STATS\n");
    printf("-----\n");
    
    //Prints All The Statistics To The Screen
    printf("lines: %d\nspaces: %d\nblanklines: %d\nquoted characters: %d\ncomments: %d\ncomments characters: %d\nkeywords: %d\nidentifiers: %d\nidentifiers characters: %d\n", returnLinesNumber(), returnSpacesNumber(), returnBlankLinesNumber(), returnQuotesCharsNumber(), returnCommentsNumber(), returnCommentsCharsNumber(), returnKeywordsNumber(), returnIdentifiersNumber(), returnIdentifiersCharsNumber());
}

void file_command(char *save_file_path) {
    FILE *fptr;

    fptr = fopen(save_file_path, "w");
    
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    
    fprintf(fptr, "\nlines: %d\nspaces: %d\nblanklines: %d\nquoted characters: %d\ncomments: %d\ncomments characters: %d\nkeywords: %d\nidentifiers: %d\nidentifiers characters: %d\n", returnLinesNumber(), returnSpacesNumber(), returnBlankLinesNumber(), returnQuotesCharsNumber(), returnCommentsNumber(), returnCommentsCharsNumber(), returnKeywordsNumber(), returnIdentifiersNumber(), returnIdentifiersCharsNumber());
    
    fclose(fptr);
    
    printf("Result successfuly saved in \"%s\".\n", save_file_path);
}

void show_results(command_line_arguments command, char *save_file_path) {
    switch (command) {
        case HELP_ARG:
            help_command();
            break;
        case TERM_ARG:
            term_command();
            break;
        case FILE_ARG:
            file_command(save_file_path);
            break;
        default:
            break;
    }
}
