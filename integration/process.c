#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
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
    DIR * d; // get dir stream
    struct dirent *dir;// get detial file names in the stream
    node* filelist; // return a list of filename
    node* pointer;

    filelist = NULL;
    pointer = NULL;

    if(strcmp(token1,"") ==0)
    {
		d = opendir(".");
    }
    else
    {
  		d = opendir(token1);
    }

    if(d != NULL) // if the directory is found
    {      
        if(!create_node(&filelist, ""))
        {
            return NULL;
        }
        
        dir = readdir(d);
        
        pointer = filelist;
        
        while(dir != NULL)
        {
            char current_path[MAX_TOKEN_LENGTH];
            get_current_path(current_path, token1);

            if(strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0 )
            {
                strcat(current_path, dir->d_name);
                if(opendir(current_path) != NULL) // if the current dir->d_name is a new directory, then we have to deal with sub-directory
                {
                    pointer->next = process_location(current_path);
                    while(pointer->next != NULL) // locate the tailer of the list
                        pointer = pointer ->next;
                }
                else
                {
                     add_node(&pointer, current_path);
                }
                
            }
            
            dir = readdir(d);
        }
        closedir(d);
        return filelist->next;
    }
    else // if the directory is not exisitng, then return NULL
    {
        print_error_msg("Invalid Input: Non-existing directory");
        return NULL;
	}

	return filelist->next;
}

node* process_criteria(char* token2, char* token3, node* filelist)
{
	node* qualified_list;

	qualified_list = NULL;

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
		print_error_msg("Invalid Syntax: Criteria should be -name, -mmin or -inum");	/* criteria is not valid */
	}

    //Test : mock data
    // node *dummy, *tail, *head;

    // char *filepath0 = "testFolder0/testFile0";
    // char *filepath1 = "testFolder0/testFolder1/testFile1";
    // char *filepath2 = "testFolder0/testFolder1/testFile0";
    // char *filepath3 = "testFolder0/testFolder1/test2";

    // if(create_node(&dummy, "") == FAILURE)  
    // {
    //     return FAILURE;
    // }           

    // tail = dummy;                        
    // add_node(&tail, filepath0);     
    // add_node(&tail, filepath1);
    // add_node(&tail, filepath2);
    // add_node(&tail, filepath3);

    // head = dummy->next;
    // qualified_list = head;

	return qualified_list;
}

int process_delete(char* token4, char* token5, node* qualified_list)
{
	int result;

	if(strcmp(token4, "-delete") != 0 || strcmp(token5, "") != 0)
    {
		print_error_msg("Invalid Input: For deleting files, enter -file after criteria");
		return FAILURE;
	}

	result = delete(qualified_list);

	return result;
}

