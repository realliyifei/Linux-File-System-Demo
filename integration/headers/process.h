/*
 *    Project: Prototypes of processing users' input
 *    Discription: It contains prototype of checking and processing users' input respectively
 *    Course: CS4323
 *    Author: Shaw Hui, Zhiming Zou
 *    Last Modified date: May 9 2019
 *    Include-header instruction under same folder: #include "process.h"
 */

#ifndef _PROCESSH_
#define _PROCESSH_

#include "node.h"  /* for the usage of node structure */



/*
 * @func:   process_find
 * ----------------------------
 * @brief   check the first substring is "find" or not
 * @param   token0: the first substring of users' input
 * @return  return: integer indicating the status of success (0) or failure (1)
 */

int process_find(char* token0);

/*
 * @func:   process_location
 * ----------------------------
 * @brief   find the directory that user input and return all the file in the directory or null
 * @param   token1: the directory that user input
 * @return  return: if find qualified directory, it will return a filelist of all the file entires including all the files in sub-directories; if not, return null list..
 */

node* process_location(char* token1);


/*
 * @func:   process_criteria
 * ----------------------------
 * @brief   search files according to the criteria from user input
 * @param1  token2: criteria tyle -name, -mmin, -inum
 * @param2  token3: critiera value used to search files
 * @param3  filelist: a list of filepaths returned from process_location(..)
 * @return  return: if find qualified directory, it will return a filelist of all the file entires including all the files in sub-directories; if not, return null list..
 */

node* process_criteria(char* token2, char* token3, node* filelist);

/*
 * @func:   process_delete
 * ----------------------------
 * @brief   delete files returned from process_criteria
 * @param1  token4: "-delete" command from user input
 * @param2  token5: command right after "-delete"
 * @param3  qualified_list: a list of filepaths returned from process_criteria(..)
 * @return  return: if deletion suceeds, it will return 1, otherwise return 0
 */

int process_delete(char* token4, char* token5, node* qualified_list);

#endif

