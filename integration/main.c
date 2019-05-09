#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/constant.h"
#include "headers/linkedlist.h"
#include "headers/util.h"
#include "headers/process.h"
#include "headers/search.h"
#include "headers/delete.h"

				
void prompt_input();
int get_input(char* tokens[]);
int process_input(char* tokens[]);

void prompt_input()
{
	printf("Welcome to the virtual file system! \n");
    printf("The VFS has four following functions \n");
    printf("1. find where-to-look \n");
    printf("Usage : \"find directory_name\" \n");
    printf("2.   find where-to-look criteria \n");
    printf(" -a. find where-to-look -name <specified name> \n");
    printf(" -b. find where-to-look -mmin <specified number of minutes> \n");
    printf(" -c. find where-to-look -inum <specified i-node number>) \n");
    printf("3. find where-to-look criteria -delete \n");
    printf("\n");
	printf("\n");
}

int get_input(char* tokens[])   
{
	int result;
	char user_input[MAXTOKEN * MAX_TOKEN_LENGTH];

	fflush(stdin);
	
	fgets(user_input, MAXTOKEN * MAX_TOKEN_LENGTH, stdin);   

	if(!check_length(user_input) || !convert_user_instruction(user_input, tokens))
	{
		return FAILURE;
    }

	 return SUCCESS;
}

int process_input(char* tokens[])
{	
	int result;
	node *filelist, *qualified_list;
	
	filelist = NULL	;	
	qualified_list = NULL;

	if(!process_find(tokens[0]) || (filelist = process_location(tokens[1])) == NULL)
	{
		result = FAILURE;
	}
	else if(strcmp(tokens[2], "") == 0)
	{
		print_list(filelist);
		result = SUCCESS;
	}
	else if((qualified_list = process_criteria(tokens[2], tokens[3], filelist)) == NULL)
	{
		result = FAILURE;
	}
	/*Bug report 5/8/2019: 
		When user input "find where-to-find -mmin +5" or "find where-to-find -inode 23673"
	and after the program calls process_criteria(..), the content of token[3] and token[4] 
	are changed to weired characters, which should not happen. When user does not 
	type -delete, token[4] should be empty all the time and the code should not call process_delete */

	/*To re-create the bug: 
		please enter "find valid-dir-path -mmin +5" and print the value of token[4] and token[3] when
	1) commenting the else-if statement above 2) not commenting the else- if statement */
	else if(strlen(tokens[4]) == 0)
	{
		print_list(qualified_list);
		result = SUCCESS;
	}
	else if(!process_delete(tokens[4], tokens[5], qualified_list))
	{
		result = FAILURE;
	}
	else
	{
		result = SUCCESS;
	}

	free_list(filelist);
	free_list(qualified_list);
	
	return result;
}


int main()
{
	int result;
	char* tokens[MAXTOKEN];

	for(int i = 0; i < MAXTOKEN; ++i)
	{
		tokens[i] = (char *) malloc(MAX_TOKEN_LENGTH);
	}

	prompt_input();

	if(!get_input(tokens))
	{
		return FAILURE;
	}

	result = process_input(tokens);
	
	printf("%s\n", "Test: main ends");
	
	return result;
}
