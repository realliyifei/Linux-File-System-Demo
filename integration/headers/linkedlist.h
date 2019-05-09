/*
 *	Project: Header of LinkedList
 *	Discrition: It contains declarations of basic version of node, addnode function, removenode function and freelist function
 *	Course: CS4323
 *	Author: Hui Xiao
 *	Creation date: April 29 2019
 *	Include-header instruction under same folder: #include "linkedlist.h"
 */
#ifndef _LINKEDLISTH_
#define _LINKEDLISTH_

#include "node.h"

int create_node(node **new_node, char *new_filepath);
int add_node(node **cur_tail, char *new_filepath);
int remove_node(); // to be implemented if needed
int free_list(node *head);

#endif
