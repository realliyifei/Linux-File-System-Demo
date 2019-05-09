#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h> // stat function
#include <unistd.h>   //   function
#include <string.h>   // strchr, strcmp
#include <time.h>
#include "headers/search.h"
#include "headers/linkedlist.h"
#include "headers/constant.h"
#include "headers/util.h"

/**
 * Function: find_symbol_position (helper function for search_by_name)
 * @Exec find the last position of given symbol in given string
 * @Para1 string - the string required finding in 
 * @Para2 symbol - the char required finding the last position of
 * @Return the integer refers to the last position of given symbol in given string
 */
int find_symbol_position(char* string, char symbol) 
{
    int symbol_position;
    char *part;
    part = strchr(string, symbol);
    // if filename contains symbol

    if (part != NULL) 
    {
        while(part != NULL) 
        {
            symbol_position = part-string;
            part = strchr(part+1,symbol);
        }
    }
    // if filename dones't contain symbol
    else {
        symbol_position = strlen(string);
    }
    return symbol_position;
}

/**
 * Function: search_by_name
 * @Exec Search all the files with name indicated by filelist and print the directory
 * @Para1 name - the required file name to be searched
 * @Para2 filelist - pointer to the head of the linkedlist of the filenames
 * @Return pointer to the head of the linkedlist of the searched file
 *          NULL if fails
 */
node* search_by_name(char* name, node* filelist)
{
    char* filepath;
    int begin_position; // the begin position of desired filename in filepath
    int end_position; // the end position of desired filename in filepath
    
    node* filelist_temp = filelist;
    node* filelist_result; // qualified filelist
    node* tail; // temporary pointer pointing to the tail of qualified filelist
    tail = filelist_result;
    create_node(&filelist_result,""); // initalize
  
    while(filelist_temp != NULL)
    {
        filepath = filelist_temp->filepath;
        
        // Find the Position of the Last Slash "/" And Dot "."
        begin_position = find_symbol_position(filepath, '/');
        // test whether given search name contains dot "."
        int name_dot_finder = (int) strchr(name,'.');
        // when given search name doesn't contain dot,
        // catch "filename" by setting the last dot in filepath as end position
        if (name_dot_finder == 0)
            end_position = find_symbol_position(filepath, '.');
        // when given search name contains dot,
        // catch "filename.suffix" by setting the last digit in filepath as end position
        else
            end_position = strlen(filepath);
        
        // Write and Compare File Name
        char* file_name = malloc(4);
        // catch the desired filename in filepath to file_name
        strncpy(file_name, filepath + begin_position + 1, end_position - begin_position - 1);
        file_name[end_position - begin_position - 1] = '\0';
        // add qualified filelist to node when the filename in filepath and given search name are identical
        if(strcmp(file_name, name)==0)
        {
            add_node(&tail,filepath);
        }
        
        filelist_temp = filelist_temp->next;
    }
    
    return filelist_result->next;
}

/**
 * Function: search_by_modification_time
 * @Exec Search all the files with modification time mentioned by min 
 *          Three conditions: less than, exactly equal to, and larger than 
 * @Para1 min - the required modification time
 * @Para2 filelist - pointer to the head of the linkedlist of the filenames
 * @Return pointer to the head of the linkedlist of the searched file
 *          NULL if fails
 */
node* search_by_modification_time(char* min, node* filelist)
{
    time_t t;
    struct tm *timeinfo;
    time(&t);
    timeinfo = localtime(&t);
    struct stat buf;
    node *final_filelist;
    node *tail;
    node *temp = filelist;

    int i_min; // = atoi(min);// make minutes in char to int

    int result;
    if (filelist == NULL)
    {
        //  printf("filelist is empty.\n");
        return NULL;
    }

    create_node(&final_filelist, "");
    tail = final_filelist;

    // printf("creat new node\n");
    if (min[0] == '+')
    {
        i_min = atoi((min) + 1);
        printf("minutes after '+': %d \n", i_min);

        while ((temp->filepath) != NULL)
        {

            stat(temp->filepath, &buf);

            printf("the filepath: %s\n", temp->filepath);
            //printf("modified time %ld\n", (time(NULL) - buf.st_mtime));
            printf("modified time: %s\n", ctime(&buf.st_mtime));
            if ((time(NULL) - buf.st_mtime) >= (i_min * 60))
            {
                if (S_ISREG(buf.st_mode))
                {
                    add_node(&tail, temp->filepath);
                }
                // printf("added filepath'-': %s \n", temp->filepath);
            }
            //printf("not added filepath'-': %s \n", temp->filepath);

            temp = temp->next;
        }
        printf("\n");
        return final_filelist->next;
    }

    else if (min[0] == '-')
    {
        i_min = atoi((min) + 1);
        printf("minutes after '-': %d \n", i_min);
        while ((temp->filepath) != NULL)

        {

            result = stat(temp->filepath, &buf);
            printf("the filepath: %s\n", temp->filepath);

            printf("modified time: %s\n", ctime(&buf.st_mtime));
            if ((time(NULL) - buf.st_mtime) < (i_min * 60))
            {
                add_node(&tail, temp->filepath);
                printf("added filepath'-': %s \n", temp->filepath);
            }

            temp = temp->next;
        }
        printf("\n");
        return final_filelist->next;
    }

    else
    {
        i_min = atoi(min);
        while ((temp->filepath) != NULL)
        {

            result = stat(temp->filepath, &buf);
            printf("the filepath: %s\n", temp->filepath);
            printf("modified time %s\n", ctime(&buf.st_mtime));
            if ((int)((time(NULL) - buf.st_mtime) / 60) == (i_min))
            {
                if (S_ISREG(buf.st_mode))
                {
                    add_node(&tail, temp->filepath);
                }
                // printf("filepath'-': %s \n", temp->filepath);
            }
            temp = temp->next;
        }
        printf("\n");
        return final_filelist->next;
    }
}

/**
 * Function: search_by_inode
 * @Exec Search all the files with i-node mentioned by inum
 * @Para1 min - the required i-node
 * @Para2 filelist - pointer to the head of the linkedlist of the filenames
 * @Return pointer to the head of the linkedlist of the searched file
 *          NULL if fails
 */
node* search_by_inode(char* inum, node* filelist)
{
    node *final_filelist;
    node *temp = filelist;
    node *tail;
    // DIR *dir;

    struct stat buf;
    int result;
    //struct dirent *ptr;
    long int_num = atol(inum); // make minutes in char to int

    if (filelist == NULL)
    {
        return NULL;
    }
    // else if ((dir = opendir(filelist->filepath)) == NULL)
    // {
    //     return NULL;
    // }
    create_node(&final_filelist, "");
    tail = final_filelist;

    while (temp != NULL)
    {
        //buf = malloc(sizeof(struct stat));
        //ptr = readdir(dir);
        //result =
        stat(temp->filepath, &buf);
        printf("the current file's inode is: %ld of %s \n", buf.st_ino, temp->filepath);
        if ((long)(buf.st_ino) == int_num)
        {
            if (S_ISREG(buf.st_mode))
            {
                add_node(&tail, temp->filepath);
            }
        }
        //free(buf);
        temp = temp->next;
    }
    printf("\n");
    return final_filelist->next;
}

