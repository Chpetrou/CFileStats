//
//  output_functions.h
//  CFileStats
//
//  Created by Christos Petrou.
//

#ifndef output_functions_h
#define output_functions_h

#include <stdbool.h>

typedef enum {
    HELP_ARG,
    TERM_ARG,
    FILE_ARG
} command_line_arguments;

typedef enum {
    NONE,
    INV_ARG,
    INV_ARG_NUM,
    MANY_ARG,
    FEW_ARG
} error_types;

typedef struct error_value {
    bool has_error;
    error_types error;
} error_value;

void help_command(void) ;

void error_print(error_types error);

void term_command(void);

void file_command(char *save_file_path);

void show_results(command_line_arguments command, char *save_file_path);

#endif /* output_functions_h */
