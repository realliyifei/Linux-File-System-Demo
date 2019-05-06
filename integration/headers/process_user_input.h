//
//  process_user_input.h
//  Virtual_FileSystem
//
//  Created by Zhiming Zou on 4/23/19.
//  Copyright © 2019 Zhiming Zou. All rights reserved.
//

#ifndef process_user_input_h
#define process_user_input_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "linkedlist.h"
#include "node.h"


#define MAX_TOKEN 6
#define MAX_TOKEN_LENGTH 256
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAILURE 0

void prompt_user_for_input() // in this function, we print the detail usage of the VFS
{
    printf("Welcome to the virtual file system! \n");
    printf("The VFS has four following functions \n");
    printf("1. find where-to-look \n");
    printf("Usage : \"find directory_name\" \n");
    printf("2.   find where-to-look criteria \n");
    printf(" -a. find where-to-look -name <specified name> \n");
    printf(" -b. find where-to-look -mmin <specified number of minutes> \n");
    printf(" -c. find where-to-look -inum <specified i-node number>) \n");
    printf("3. find where-to-look criteria -delete \n");
    printf("\n");
    printf("\n");
    
    
}

int check_length(char user_input[MAX_TOKEN_LENGTH*6])
{
    int ch_counter = 0;
    int space_counter = 0;
    int i = 0;
    while( i < MAX_TOKEN_LENGTH*6 && user_input[i] != '\n')
    {
        if(user_input[i] == ' ')
        {
            space_counter ++;
            
            if(space_counter > 5)
            {
                return FALSE; // tokens of input is too long,
            }
            
            ch_counter = 0;
        }
        else
        {
            ch_counter++;
            
            if(ch_counter > 256)
            {
                return FALSE; // token is too long,
            }
        }
        i++;
    }
    return TRUE; // the length of input is valid
}
void convert_user_instruction(char user_input[], char tokens[MAX_TOKEN][MAX_TOKEN_LENGTH])
{
    int i = 0;
    int j = 0;
    int k = 0;
    while( i < MAX_TOKEN_LENGTH*6 && user_input[i] != '\n')
    {
        if(user_input[i] == ' ')
        {
            tokens[j][k] = '\0'; // string must end with '\0'
            j++;
            k = 0;
            i++;
            continue;
        }
        else
        {
            tokens[j][k] = user_input[i];
            k++;
            i++;
        }
    }
}
int get_user_input(char tokens[MAX_TOKEN][MAX_TOKEN_LENGTH])
{
    fflush(stdin);
    char user_input[MAX_TOKEN_LENGTH*6];
    fgets(user_input, MAX_TOKEN_LENGTH*6,stdin);
    if(check_length(user_input) == TRUE)
    {
        convert_user_instruction(user_input, tokens);
        return SUCCESS;
    }
    return FAILURE;
}
int process_find(char first_token[MAX_TOKEN_LENGTH]) // check the first input is "find" or not
{
    if(strcmp(first_token, "find") != 0)
        return FALSE;
    return TRUE;
}


void get_current_path(char * dest, char * filename)
{
    strncpy(dest, filename, MAX_TOKEN_LENGTH);
    strcat(dest,"/");
    
}


node* process_location(char * token1)
{
    DIR * d; // get dir stream
    struct dirent *dir;// get detial file names in the stream
    d = opendir(token1); // get the filestream of token1
    
    if(d != NULL) // if the directory is found
    {
        dir = readdir(d);
        node *filelist; // return a list of filename
        filelist = (node*)malloc(sizeof(node));
        
        if(filelist == NULL)
        {
            printf("Fail in creating node due to malloc failure");
            return FAILURE;
        }
        node* pointer = filelist;
        while(dir != NULL)
        {
            char current_path[MAX_TOKEN_LENGTH];
            get_current_path(current_path, token1);
           
            if(strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0 )
            {
                /*node *temp = malloc(sizeof(node));
                strcat(current_path, dir->d_name);
                temp->filepath = current_path;
                temp->next = NULL;
                pointer = temp;
                pointer = pointer->next;
                printf("%s\n", filelist->filepath);*/
               
                strcat(current_path, dir->d_name);
                //printf("%s\n", current_path);
                if(opendir(current_path) != NULL) // if the current dir->d_name is a new directory, then we have to deal with sub-directory
                {
                    pointer->next = process_location(current_path);
                    while(pointer->next != NULL) // locate the tailer of the list
                        pointer = pointer ->next;
                }
                else
                {
                     add_node(&pointer, current_path);
                }
                
            }
            
            dir = readdir(d);
        }
        //printf("traversal all files in current dir\n");
        closedir(d);
   
        return filelist->next;
    }
    else // if the directory is not exisitng, then return NULL
    {
        printf("can't find directory");
        printf(" %s\n", token1);
        return NULL;
    }
}
void print_filelist(node* filelist)
{
    if(filelist != NULL)
    {
        node * pointer = filelist;
        while (pointer != NULL) {
            printf("%s\n", pointer->filepath);
            pointer = pointer->next;
        }
    }
}


#endif /* process_user_input_h */
