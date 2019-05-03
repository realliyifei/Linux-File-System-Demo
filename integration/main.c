#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/constant.h"
#include "headers/linkedlist.h"
#include "headers/util.h"
#include "headers/search.h"
#include "headers/delete.h"

#define MAXTOKEN 6
#define MAX_TOKEN_LENGTH 256
#define TERMINATION 2

char* tokens[MAXTOKEN];
node* filelist;					
node* qualified_list;

void prompt_input();
int get_input();
int process_input();

void print_instruction();
int process_find(char* token0);
int process_location(char* token1);
int process_criteria(char* token2, char* token3);
int process_delete(char* token4, char* token5);

void prompt_input()
{
	print_instruction();
}

int get_input()   
{
	 char user_input[MAXTOKEN * MAX_TOKEN_LENGTH];

	 /* ... */

	 fgets(user_input, MAXTOKEN * MAX_TOKEN_LENGTH, stdin);  /*to-do-list: handle fgets error? */


	 /* check if user input exceeds token maximum and return FAILURE if needed */

	 /* split user input into tokens */

	 return SUCCESS;
}

int process_input()
{	
	int res;

	if(process_find(tokens[0]) == FAILURE)
	{
		return FAILURE;
	}

	if(process_location(tokens[1]) == FAILURE)
	{
		return FAILURE;
	}

	if((res = process_criteria(tokens[2], tokens[3])) == TERMINATION)
	{
		print_list(filelist);
		return SUCCESS;
	}
	else if(res == FAILURE)
	{
		return FAILURE;
	}

	if((res = process_delete(tokens[4], tokens[5])) == TERMINATION)
	{
		print_list(qualified_list);
		return SUCCESS;
	}
	else if(res == FAILURE)
	{
		return FAILURE;
	}

	return SUCCESS;
}

void print_instruction()
{
	/* print user instruction */
}

int process_find(char* token0)
{
	/* check if token0 is find*/

	return SUCCESS;
}

int process_location(char* token1)
{
	
	/* check if token1 is valid directory */

	/* if it is valid, recursively add file path name relative to the input directory to filelist*/

	return SUCCESS;
}

int process_criteria(char* token2, char* token3)
{
	if(token2 == NULL)
	{
		return TERMINATION;
	}

	/* check and choose corresponding search function*/
	if(strcmp(token2, "-name") == 0)
	{
		qualified_list = search_by_name(token3, filelist);
	}
	else if(strcmp(token2, "-mmin") == 0)
	{
		qualified_list = search_by_modification_time(token3, filelist);
	}
	else if(strcmp(token2, "-inum") == 0)
	{
		qualified_list = search_by_inode(token3, filelist);
	}
	else			
	{
		print_error_msg("Invalid Syntax");	/* criteria is not valid */
		return FAILURE;
	}

	if(qualified_list == NULL)
	{
		return FAILURE;
	}

	return SUCCESS;
}

int process_delete(char* token4, char* token5)
{
	int res;

	if(token4 == NULL)
	{
		return TERMINATION;
	}
	
	/* check if delete syntax valid, call delete function*/
	
	delete(qualified_list);

	return res;
}


int main()
{
	int res;

	prompt_input();

	if(!get_input(tokens))
	{
		return res;
	}

	res = process_input(tokens);

	free_list(filelist);
	free_list(qualified_list);
	
	printf("%s\n", "Test: main ends");
	
	return res;
}