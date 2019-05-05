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

int main()
{

	node *dummy, *tail, *head;

	char *filepath0 = "/OprerSys_Proj3/headers/test.txt";
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
 	
 	node* result = search_by_name(test, head);
    
    if(strcmp(result->filepath,filepath0)==0) 
    {
        printf("SUCCESS! \n");
     }

 	free_list(dummy);
 	return SUCCESS;
}
