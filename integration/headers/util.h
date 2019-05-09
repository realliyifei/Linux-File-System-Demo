/*
 *    Project: A collection of utility methods
 *    Discription: It contains the prototypes of function of checking and converting users' input, function of constructing filepath and print function
 *    Course: CS4323
 *    Author: Shaw Hui, Zhiming Zou
 *    Last Modified date: May 9 2019
 *    Include-header instruction under same folder: #include "util.h"
 */

#ifndef _UTILH_
#define _UTILH_

#include "node.h" /* for the usage of node structure */

/*
 * @func:   check_length
 * ----------------------------
 * @brief   check if user input's length is too long
 * @param   user_input[]: user_input read from console
 * @return  return: integer indicating the status of success (0) or failure (1)
 */

int check_length(char user_input[]);

/*
 * @func:   convert_user_instruction
 * ----------------------------
 * @brief   convert 1d char array of user_input to 2d char array for future process
 * @param   user_input[]: 1d char array of user_input read from console
 * @param   tokens[]: 2d char array of user_input processed
 * @return  return: integer indicating the status of success (0) or failure (1)
 */

int convert_user_instruction(char user_input[], char *tokens[]);

/*
 * @func:   get_current_path
 * ----------------------------
 * @brief   concatenate the complete path of the file 
 * @param   buffer: holds the complete path of the file
 * @param   filename: the name of files existing in file system
 */

void get_current_path(char* buffer, char* filename);

/*
 * @func:   print_list
 * ----------------------------
 * @brief   print a list of filepaths
 * @param   list: linkedlist of filepaths to be printed
 */

void print_list(node* list);

/*
 * @func:   print_error_msg
 * ----------------------------
 * @brief   print error message
 * @param   msg: error message to be printed
 */

void print_error_msg(char* msg);

#endif

