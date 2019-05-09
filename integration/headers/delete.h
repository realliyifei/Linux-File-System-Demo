/*
 *    Project: Prototype of qualified file deletion
 *    Discription: It contains prototype of the function of deleting files that satisfy with the users' requirement
 *    Course: CS4323
 *    Author: Hui Xiao
 *    Creation date: April 29 2019
 *    Include-header instruction under same folder: #include "delete.h"
 */


#ifndef _DELETEH_
#define _DELETEH_

#include "node.h" /* for the usage of node structure */


/*
 * @func: delete
 * ----------------------------
 * @brief   remove all the files with names indicated by the filelist
 * @param   filelist: pointer to the head of the linkedlist of the filenames
 * @return  return: integer indicating the status of success (0) or failure (1)
 */

int delete(node* filelist);

#endif
