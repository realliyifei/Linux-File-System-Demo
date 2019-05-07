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
				
void prompt_input();
int get_input(char* tokens[]);
int process_input(char* tokens[]);

void print_instruction();
int process_find(char* token0);
node* process_location(char* token1);
node* process_criteria(char* token2, char* token3, node* filelist);
int process_delete(char* token4, char* token5, node* qualified_list);

void prompt_input()
{
	print_instruction();
}

int get_input(char* tokens[])   
{
	 char user_input[MAXTOKEN * MAX_TOKEN_LENGTH];

	 /* ... */

	 fgets(user_input, MAXTOKEN * MAX_TOKEN_LENGTH, stdin);  /*to-do-list: handle fgets error? */


	 /* check if user input exceeds token maximum and return FAILURE if needed */

	 /* split user input into tokens */


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
	else if(tokens[2] == NULL)
	{
		print_list(filelist);
		result = SUCCESS;
	}
	else if((qualified_list = process_criteria(tokens[2], tokens[3], filelist)) == NULL)
	{
		result = FAILURE;
	}
	else if(tokens[4] == NULL)
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

void print_instruction()
{
	/* print user instruction */
}

int process_find(char* token0)
{
	/* check if token0 is find*/

	return SUCCESS;
}

node* process_location(char* token1)
{
	node* filelist;

	filelist = NULL;

	/* check if token1 is valid directory */

	/* if it is valid, recursively add file path name relative to the input directory to filelist*/

	return filelist;
}

node* process_criteria(char* token2, char* token3, node* filelist)
{
	node* qualified_list;

	qualified_list = NULL;

	/* check if criteria valid */


	/* choose corresponding search function*/
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
	}

	return qualified_list;
}

int process_delete(char* token4, char* token5, node* qualified_list)
{
	int result;

	
	/* check if delete syntax valid, call delete function*/
	

	result = delete(qualified_list);

	return result;
}


int main()
{
	int result;
	char* tokens[MAXTOKEN];

	prompt_input();

	if(!get_input(tokens))
	{
		return FAILURE;
	}

	result = process_input(tokens);
	
	printf("%s\n", "Test: main ends");
	
	return result;
}
