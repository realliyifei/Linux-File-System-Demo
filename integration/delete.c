/*
 *	Project: Function for Deleting Files on POSIX Operation Systems
 *	Course: CS4323
 *	Author: Hui Xiao
 *	Creation date: April 12 2019
 *	Compile-with-library instruction: gcc -c delete.c  linkedlist.c
 *	Link-with-library instruction: gcc -o delete_output delete.c  linkedlist.c
 */


#include <stdio.h>
#include "headers/delete.h"
#include "headers/linkedlist.h"
#include "headers/constant.h"	

int delete(node *filelist);

/*
 * Function: delete
 * ----------------------------
 *	Remove all the files with names indicated by the filelist
 *    
 *	filelist: pointer to the head of the linkedlist of the filenames
 *
 *	returns: integer indicating sucess (0) or failure (1) 
 */
int delete(node *filelist)
{
	char* filepath;
	int result;

	while(filelist != NULL)
	{
		filepath = filelist->filepath;
		result = remove(filepath);
		
		if(result != 0)
		{
			printf("Fail in deleting file %s\n", filepath);
		}
		else
		{
			printf("Deleted file %s\n", filepath);	
		}
		filelist = filelist->next;
	}
	return SUCCESS;
}

// int main()
// {

// 	node *dummy, *tail, *head;

// 	char *filepath0 = "/home/huixiao/academic/cs4323/testfolder/test0";
// 	char *filepath1 = "/home/huixiao/academic/cs4323/testfolder/subfolder1/test1";
// 	char *filepath2 = "/home/huixiao/academic/cs4323/testfolder/subfolder2/test2";
// 	char *filepath3 = "/home/huixiao/academic/cs4323/testfolder";
 	
//  	if(create_node(&dummy, "") == FAILURE)	/*dummy node for better coding style*/
//  	{
//  		return FAILURE;
//  	}			

//  	tail = dummy;						 
//  	add_node(&tail, filepath0);		
//  	add_node(&tail, filepath1);
//  	add_node(&tail, filepath2);
// 	add_node(&tail, filepath3);
 	
//  	head = dummy->next;
//  	delete(head);

//  	free_list(dummy);
//  	return SUCCESS;
// }





