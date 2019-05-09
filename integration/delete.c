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

/*
 * Function: delete
 * ----------------------------
 *	Remove all the files with names indicated by the filelist
 *    
 *	filelist: pointer to the head of the linkedlist of the filenames
 *
 *	returns: integer indicating sucess (0) or failure (1) 
 */
int delete (node *filelist)
{
	char *filepath;
	node *p = filelist;

	while (p != NULL)
	{
		filepath = p->filepath;

		if (remove(filepath) != 0)
		{
			printf("Fail in deleting file %s\n", filepath);
		}
		else
		{
			printf("Deleted file %s\n", filepath);
		}
		p = p->next;
	}
	return SUCCESS;
}
