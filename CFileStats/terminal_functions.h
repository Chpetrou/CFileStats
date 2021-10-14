//
//  terminal_functions.h
//  CFileStats
//
//  Created by Christos Petrou.
//

#ifndef terminal_functions_h
#define terminal_functions_h

#include "output_functions.h"
#include <stdbool.h>

error_value validate_argument_number(int argc, int expected_argc);

error_value validate_argument_command(int argc, char *argv[], int *option_index, command_line_arguments *command);

bool evaluate_arguments(int argc, char *argv[], int *option_index, command_line_arguments *command);

bool get_file_path(int argc, char *argv[], char **source_file_path, char **save_file_path, command_line_arguments *command);

#endif /* terminal_functions_h */
