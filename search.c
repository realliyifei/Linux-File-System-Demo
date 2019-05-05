#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h> // stat function 
#include <unistd.h> // stat function 
#include <string.h> // strchr, strcmp
#include "headers/search.h"
#include "headers/linkedlist.h"
#include "headers/constant.h"

//Exampe returned from search function: 
// find .
// ./main.o
// ./file_name_test.h
// ./.DS_Store
// ./test1.txt
// ./test2.txt
// ./dir3
// ./dir3/test7.txt
// ./dir3/test8.txt
// ./linkedlist.o
// ./linkedlist.h
// ./node.h
// ./main.c
// ./linkedlist_test.c
// ./dir1
// ./dir1/test4.txt
// ./dir1/.DS_Store
// ./dir1/test3.txt
// ./dir1/dir2
// ./dir1/dir2/test6.txt
// ./dir1/dir2/test5.txt
// ./dir1/dir2/.DS_Store
// ./main
// ./linkedlist.c

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
    
    DIR *dir;
    struct stat st;
    struct dirent *ptr;
    
    char* filepath;
    char* file_name = malloc(4); 
    int position;
    int position2;
    
    dir = opendir(filelist->filepath);
    
    node* filelist_temp = filelist; 
    node* filelist_result; 
    create_node(&filelist_result,"");
    
    while(filelist_temp != NULL)
    {
        filepath = filelist_temp->filepath;
        
        // find the position of the last dot "."
        char *part;
        part = strchr(filepath, '.');
        while(part != NULL) 
        {
            position = part-filepath;
            part = strchr(part+1,'.');
        }
        
        // find the position of the last slash "/"
        char *part2;
        part2 = strchr(filepath, '/');
        while(part2 != NULL)
        {
            position2 = part2-filepath;
            part2 = strchr(part2+1,'/');
        }
        
        // write and compare file name 
        strncpy(file_name, filepath+position2+1, position-position2-1);
        if(strcmp(file_name, name)==0)
        {
            add_node(&filelist_result,filepath); // add required node
        } 
        filelist_temp = filelist_temp->next;
    }
	return filelist_result;
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
    node *final_filelist;
    node *temp = filelist;
    DIR *dir;
    struct stat buf;
    struct dirent *ptr;
    int i_min; // = atoi(min);// make minutes in char to int
    //char base[512];
    int result; //if result == 0, then something go wrong
    printf("start time model\n");
    if (filelist == NULL)
    {   
        printf("filelist is empty.\n");
        return NULL;
    }
    // else if ((dir = opendir(filelist->filepath)) == NULL)
    // {   
    //     printf("filepath: %s\n",filelist->filepath);
    //     ptr=readdir(dir);
    //     printf("after\n");

    //     printf("filepath: %s\n",ptr->d_name);

    //     printf("(dir = opendir(filelist->filepath)) == NULL\n");
    //     return NULL;
    // }
    printf("creat new node\n");
    create_node(&final_filelist, "");
    printf("creat new node\n");
    if (min[0] == '+')
    {
        i_min = atoi(min++);
        while ((temp->next)!=NULL)
        {
            dir = opendir(temp->filepath);
            ptr = readdir(dir);
            result = stat(ptr->d_name, &buf);
            if ((time(NULL) - buf.st_mtime)<= (i_min*60)  )
            {
                add_node(&final_filelist, temp->filepath);
            }
            temp = temp->next;
                }

        return final_filelist;
    }

    else if (min[0] == '-')
    {
        i_min = atoi(min++);
        printf("minutes after '-': %d \n", i_min);
        while ((dir = opendir(temp->filepath))!=NULL)
            {
                ptr = readdir(dir);
            result = stat(ptr->d_name, &buf);
            if ((time(NULL) - buf.st_mtime)>= (i_min*60)  )
            {
                add_node(final_filelist, temp->filepath);
                printf("filepath'-': %s \n", temp->filepath);
            }
            temp = temp->next;
            }

        return final_filelist;
    }

    else
    {
        i_min = atoi(min);
        while ((dir = opendir(temp->filepath))!=NULL)
            {
                ptr = readdir(dir);
            result = stat(ptr->d_name, &buf);
            if (((time(NULL) - buf.st_mtime) / 60) == i_min )
            {
                add_node(final_filelist, temp->filepath);
            }
            temp = temp->next;
            }
        return final_filelist;
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
    node **final_filelist;
    node *temp = filelist;
    DIR *dir;
    //struct stat buff;
    struct dirent *ptr;
    int int_num = atoi(inum); // make minutes in char to int

    if (filelist == NULL)
    {
        return NULL;
    }
    else if ((dir = opendir(filelist->filepath)) == NULL)
    {
        return NULL;
    }
    create_node(&final_filelist, "");

    while ((dir = opendir(temp->filepath))!=NULL)
        {
            ptr = readdir(dir);
            //result = stat(ptr->d_name, &buf)
            if ((int)(ptr->d_ino) == int_num)
            {
                add_node(final_filelist, temp->filepath);
            }
            temp = temp->next;
        }

    return *final_filelist;
}

int main()
{

	node *dummy, *tail, *head;

	//char *filepath0 = "/OprerSys_Proj3/headers/test.txt";
	char *filepath0 = ".";
	char *filepath1 = "/OprerSys_Proj3/afolder3/afile4.txt";
	char *filepath2 = "/OprerSys_Proj3/afolder1/afile2.txt";
	char *filepath3 = "/OprerSys_Proj3/afolder1/afolder2/afile2.txt";
 	
 	/*dummy node for better coding style*/
 	if(create_node(&dummy, "") == FAILURE)	
 	{
 		return FAILURE;
 	}			

 	tail = dummy;						 
 	add_node(&tail, filepath0);		
 	add_node(&tail, filepath1);
 	add_node(&tail, filepath2);
	add_node(&tail, filepath3);
 	
 	head = dummy->next;
 	char* test = "test";
 	char* min = "-10";
 	char* num = "1150561";
 	
 	search_by_name(head,test);
 	search_by_modification_time(min,head);
 	search_by_inode(num,head);

 	free_list(dummy);
 	return SUCCESS;
}
