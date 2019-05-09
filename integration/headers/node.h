/*
 *    Project: structure of node for linkedlist
 *    Discription: It contains the definiton of node structure
 *    Course: CS4323
 *    Author: Shaw Hui
 *    Last Modified date: May 9 2019
 *    Include-header instruction under same folder: #include "node.h"
 */



#ifndef _NODEH_
#define _NODEH_

#define MAX_FILEPATH_LENGTH 256

typedef struct node {
	char filepath[MAX_FILEPATH_LENGTH];
	struct node* next;
} node;

#endif
