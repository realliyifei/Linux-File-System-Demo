#ifndef _UTILH_
#define _UTILH_

#include "node.h"
int check_length(char user_input[]);
int convert_user_instruction(char user_input[], char *tokens[]);
void get_current_path(char* buffer, char* filename);
void print_list(node* list);
void print_error_msg(char* msg);

#endif

