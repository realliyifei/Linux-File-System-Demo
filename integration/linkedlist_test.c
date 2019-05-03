/*
 *	Project:Simple Test Cases for Custmozied Linkedlist Libraries
 *	Discrition: It tests the creation of node, appending node to the linkedlist and freeing the memory pointed by the linkedlist
 *	Course: CS4323
 *	Author: Hui Xiao
 *	Creation date: April 29 2019
 *	Compile-with-library instruction: gcc -c linkedlist_test.c linkedlist.c
 *	Link-with-library instruction: gcc -o linkedlist_test_output linkedlist_test.c linkedlist.c
 */

#include <stdlib.h>
#include <stdio.h>
#include "headers/linkedlist.h"


// void main()
// {
// 	node *dummy, *tail, *head, *p;
// 	int i;
	
// 	create_node(&dummy, "");					/* dummy: "" -> NULL */
 
//  	tail = dummy;

// 	for(i = 1; i <= 10; ++i)
// 	{	
// 		add_node(&tail, "path");				/* dummy: "" -> node: "path" -> node: "path" -> ... -> node(tail): "path" -> NULL */
// 	}

// 	head = dummy->next;							/* the meaningful node start with the next node of dummy */
// 	p = head;
	
// 	while(p != NULL)							/* traverse and print the file path of the list */
// 	{
// 		printf("filepath: %s\n", p->filepath);
// 		p = p->next;
// 	}

// 	free_list(dummy);							/*free the memory pointed by the list*/
// }