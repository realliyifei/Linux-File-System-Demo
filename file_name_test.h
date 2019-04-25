//
//  file_name_test.h
//  Virtual_FileSystem
//
//  Created by Zhiming Zou on 4/23/19.
//  Copyright © 2019 Zhiming Zou. All rights reserved.
//

#ifndef file_name_test_h
#define file_name_test_h

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#define max_input_token 6
#define max_length_of_characters 256
#define TRUE 1
#define FALSE 0

void prompt_helper() // in this function, we print the detail usage of the VFS
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
int checkerLength(char original_input[max_length_of_characters*6])
{
    int ch_counter = 0;
    int space_counter = 0;
    int i = 0;
    while( i < max_length_of_characters*6 && original_input[i] != '\n')
    {
        if(original_input[i] == ' ')
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
void convert_original_to_userInput(char original_input[], char user_input[][max_length_of_characters])
{
    int i = 0;
    int j = 0;
    int k = 0;
    while( i < max_length_of_characters*6 && original_input[i] != '\n')
    {
        if(original_input[i] == ' ')
        {
            user_input[j][k] = '\0'; // string must end with '\0'
            j++;
            k = 0;
            i++;
            continue;
        }
        else
        {
            user_input[j][k] = original_input[i];
            k++;
            i++;
        }
    }
}
int checker_first_token(char first_token[max_length_of_characters]) // check the first input is "find" or not
{
    if(strcmp(first_token, "find") != 0)
        return FALSE;
    return TRUE;
}
void printFilePath(char * fileName)
{
    DIR * d;
    struct dirent *dir;
    
    d = opendir(fileName);
    if(d != NULL)
    {
        dir = readdir(d);
        
        while(dir != NULL)
        {
            printf("%s\n", dir->d_name);
            dir = readdir(d);
        }
        printf("traversal all files in current dir\n");
        closedir(d);
    }
    else
        printf("can't find directory\n");
}
DIR * FilePath(char * fileName)
{
    DIR * d;
    d = opendir(fileName);
    if(d != NULL)
    {
        return d;
    }
    else
        printf("can't find directory\n");
    return NULL;
}
#endif /* file_name_test_h */
