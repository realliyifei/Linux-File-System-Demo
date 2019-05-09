/*
 *    Project: Prototypes of searching function
 *    Discription: It contains prototype of the functions including searching by name, searching by the time of modification and searching by inode
 *    Course: CS4323
 *    Author: Fangda Guo, Yifei Li
 *    Last Modified date: May 9 2019
 *    Include-header instruction under same folder: #include "search.h"
 */

#ifndef _SEARCHH_
#define _SEARCHH_

#include "node.h"/* for the usage of node structure */

/**
 * @func: search_by_name
 * ----------------------------
 * @brief  search all the files with name indicated by filelist and print the directory
 * @param1 name - the required file name to be searched
 * @param2 filelist - pointer to the head of the linkedlist of the filenames
 * @return pointer to the head of the linkedlist of the searched file
 *          NULL if fails
 */
node* search_by_name(char* name, node* filelist);

/**
 * func: search_by_modification_time
 * @brief   search all the files with modification time mentioned by min
 *          three conditions: less than, exactly equal to, and larger than
 * @param1  min - the required modification time
 * @param2  filelist - pointer to the head of the linkedlist of the filenames
 * @return  pointer to the head of the linkedlist of the searched file
 *          NULL if fails
 */
node* search_by_modification_time(char* min, node* filelist);

/**
 * func:   search_by_inode
 * @brief  search all the files with i-node mentioned by inum
 * @param1 min - the required i-node
 * @param2 filelist - pointer to the head of the linkedlist of the filenames
 * @return pointer to the head of the linkedlist of the searched file
 *         NULL if fails
 */
node* search_by_inode(char* inum, node* filelist);

#endif
