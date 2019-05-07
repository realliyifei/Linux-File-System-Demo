/*
 *	Project:Implementation of LinkedList
 *	Discrition: It contains implementation of createnode, addnode and freelist functions in linkedlist.h
 *	Course: CS4323
 *	Author: Hui Xiao
 *	Creation date: April 29 2019
 *	Compile instruction: gcc linkedlist.c
 */

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"
#include <string.h>
#define SUCCESS 1
#define FAILURE 0
/*
 * Function: create_node
 * ----------------------------
 *	Change the location pointed by the pointer pointed by "node **new_node" to the location of the new node with data filepath
 *   
 *	new_node: pointer to the pointer pointing to the new node
 *	new_filepath: full path of a file of the new node
 *
 *	returns: integer indicating sucess (0) or failure (1) 
 */
int create_node(node **new_node, char *new_filepath)
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	
	if(temp == NULL)
	{
		printf("Fail in creating node due to malloc failure");
		return FAILURE;
	}

	strcpy(temp->filepath, new_filepath);
	temp->next = NULL;

	*new_node = temp;

	return SUCCESS;
}

/*
 * Function: add_node
 * ----------------------------
 *	Update the location pointed by the pointer pointed by "node **tail" to the location of the new tail after appending a new node to the end
 *	The tail node's next pointer always points to NULL  (e.g, ..->tail->NULL)
 *    
 *	tail: pointer to the pointer pointing to the current tail
 *	newfilepath: full path of a file of the new node
 *
 *	returns: integer indicating success (0) or failure (1) 
 */
int add_node(node **tail, char *new_filepath)
{
	node *new_tail = NULL;

	if(create_node(&new_tail, new_filepath) == FAILURE)
	{
		printf("Fail in adding node due to node creation");
		return FAILURE;
	}

	if(*tail != NULL) 				/*non-empty list*/
	{
		(*tail)->next = new_tail;
	}
    /*else
    {
        create_node(tail,"");
    }*/

	*tail = new_tail;

	return SUCCESS;
}

/*
 * Function: remove_node
 * ----------------------------
 *	To be implemented, if needed
 */
int remove_node()
{
	return SUCCESS;
}

/*
 * Function: free_list
 * ----------------------------
 *	Free the memory of the each node in the list allocated by malloc in create_node(...) 
 *	to prevent potential memory leak.
 *	  
 *	node: the pointer to the head of the linkedlist
 *	returns: integer indicating sucess (0) or failure (1) 
 */
int free_list(node *head)
{
	node *temp;

	while(head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}

	return SUCCESS;
}
