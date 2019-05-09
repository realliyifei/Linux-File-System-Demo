#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/constant.h"
#include "headers/linkedlist.h"
#include "headers/util.h"
#include "headers/process.h"
#include "headers/delete.h"

void prompt_input();
int get_input(char *tokens[]);
int process_input(char *tokens[]);

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

int get_input(char *tokens[])
{
	int result;
	char user_input[MAXTOKEN * MAX_TOKEN_LENGTH];

	fflush(stdin);

	fgets(user_input, MAXTOKEN * MAX_TOKEN_LENGTH, stdin);

	if (!check_length(user_input) || !convert_user_instruction(user_input, tokens))
	{
		return FAILURE;
	}

	return SUCCESS;
}

int process_input(char *tokens[])
{
	int result;
	node *filelist, *qualified_list;

	filelist = NULL;
	qualified_list = NULL;

	if (!process_find(tokens[0]) || (filelist = process_location(tokens[1])) == NULL)
	{
		result = FAILURE;
	}
	else if (strcmp(tokens[2], "") == 0)
	{
		print_list(filelist);
		result = SUCCESS;
	}
	else if ((qualified_list = process_criteria(tokens[2], tokens[3], filelist)) == NULL)
	{
		result = FAILURE;
	}
	else if (strlen(tokens[4]) == 0)
	{
		print_list(qualified_list);
		result = SUCCESS;
	}
	else if (!process_delete(tokens[4], tokens[5], qualified_list))
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
	char *tokens[MAXTOKEN];

	for (int i = 0; i < MAXTOKEN; ++i)
	{
		tokens[i] = (char *)malloc(MAX_TOKEN_LENGTH);
	}

	prompt_input();

	if (!get_input(tokens))
	{
		return FAILURE;
	}

	result = process_input(tokens);

	return result;
}
