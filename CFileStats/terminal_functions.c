//
//  terminal_functions.c
//  CFileStats
//
//  Created by Christos Petrou.
//

#include "terminal_functions.h"
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>

error_value validate_argument_number(int argc, int expected_argc) {
    error_value value;
    value.has_error = false;
    value.error = NONE;
    
    if (argc < expected_argc) {
        value.has_error = true;
        value.error = FEW_ARG;
    } else if (argc > expected_argc) {
        value.has_error = true;
        value.error = MANY_ARG;
    }
    return value;
}

error_value validate_argument_command(int argc, char *argv[], int *option_index, command_line_arguments *command) {
    error_value value;
    
    value.has_error = true;
    value.error = INV_ARG_NUM;
    
    if (argc > 1) {
        int expected_argc = 2;
        *command = TERM_ARG;
        
        for (int i = 0; i < argc; i++) {
            if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h")  == 0) {
                expected_argc = 2;
                *option_index = i;
                *command = HELP_ARG;
                break;
            } else if (strcmp(argv[i], "--term") == 0  || strcmp(argv[i], "-t") == 0) {
                expected_argc = 3;
                *option_index = i;
                *command = TERM_ARG;
                break;
            } else if (strcmp(argv[i], "--file") == 0 || strcmp(argv[i], "-f") == 0) {
                expected_argc = 4;
                *option_index = i;
                *command = FILE_ARG;
                break;
            }
        }
        value = validate_argument_number(argc, expected_argc);
    }
    
    return value;
}

bool evaluate_arguments(int argc, char *argv[], int *option_index, command_line_arguments *command) {
    error_value result = validate_argument_command(argc, argv, option_index, command);
    
    if (result.has_error == true) {
        error_print(result.error);
        return false;
    }
    
    return true;
}

bool get_file_path(int argc, char *argv[], char **source_file_path, char **save_file_path, command_line_arguments *command) {
    int option_index = 0;
//    command_line_arguments command = TERM_ARG;
    
    if (!evaluate_arguments(argc, argv, &option_index, command))
        return false;
    
    switch (*command) {
        case HELP_ARG:
            break;
        case TERM_ARG:
            if (option_index == 1) {
                *source_file_path = argv[2];
            } else if (option_index == 0) {
                *source_file_path = argv[1];
            }
            break;
        case FILE_ARG:
            if (option_index == 1) {
                *save_file_path = argv[2];
                *source_file_path = argv[3];
            } else if (option_index == 2) {
                *save_file_path = argv[3];
                *source_file_path = argv[1];
            }
            break;
        default:
            break;
    }
    
    return true;
}
