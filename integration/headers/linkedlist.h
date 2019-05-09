/*
 *	Project: Functionalities of LinkedList
 *	Discription: It contains declarations of node, the function of node insertion at tail, and freelist function
 *	Course: CS4323
 *	Author: Hui Xiao
 *	Last Modified date: May 9 2019
 *	Include-header instruction under same folder: #include "linkedlist.h"
 */
#ifndef _LINKEDLISTH_
#define _LINKEDLISTH_

#include "node.h" /* for the usage of node structure */


/*
 * @func: create_node
 * ----------------------------
 * @brief    change the location pointed by the pointer pointed by "node **new_node" to the location of the new node with data filepath
 * @param1   new_node: pointer to the pointer pointing to the new node
 * @param2   new_filepath: full path of a file of the new node
 * @return   returns: integer indicating the status of success (0) or failure (1)
 */

int create_node(node **new_node, char *new_filepath);

/*
 * @func: add_node
 * ----------------------------
 * @brief  update the location pointed by the pointer pointed by "node **tail"
 *          to the location of the new tail after appending a new node to the end
 *          the tail node's next pointer always points to NULL  (e.g, ..->tail->NULL)
 * @param1  tail: pointer to the pointer pointing to the current tail
 * @param2  newfilepath: full path of a file of the new node
 * @return returns: integer indicating the status of success (0) or failure (1)
 */
int add_node(node **cur_tail, char *new_filepath);

/*
 * @func: free_list
 * ----------------------------
 * @brief free the memory of the each node in the list allocated by malloc in create_node(...)
 *        to prevent potential memory leak.
 *
 * @param1  node: the pointer to the head of the linkedlist
 * @return  returns: integer indicating the status of success (0) or failure (1)
 */
int free_list(node *head);

#endif


