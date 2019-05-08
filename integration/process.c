#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/process.h"
#include "headers/constant.h"
#include "headers/linkedlist.h"
#include "headers/util.h"
#include "headers/search.h"
#include "headers/delete.h"

int process_find(char* token0)
{
	if(strcmp(token0, "find") != 0)
	{
    	print_error_msg("Invalid Input: Command should start with 'find' ");
    	return FAILURE;
    }

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
	

	//result = delete(qualified_list);

	return result;
}