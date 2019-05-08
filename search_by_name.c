#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h> // stat function 
#include <unistd.h> // stat function 
#include <string.h> // strchr, strcmp
#include "headers/search.h"
#include "headers/linkedlist.h"
#include "headers/constant.h"

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
    
    char* filepath;
    int position;
    int position2;
    
    dir = opendir(filelist->filepath);
    
    node* filelist_temp = filelist; 
    node* filelist_result; 
    node* tail;
    create_node(&filelist_result,"");
    tail = filelist_result;
    
    while(filelist_temp != NULL)
    {
        filepath = filelist_temp->filepath;
        
        // find the position of the last slash "/"
        char *part2;
        part2 = strchr(filepath, '/');
        while(part2 != NULL)
        {
            position2 = part2-filepath;
            part2 = strchr(part2+1,'/');
        }
        
        // find the position of the last dot "."
        char *part;
        part = strchr(filepath, '.');
        // if filename contains dot
        if (part != NULL) 
        {
            while(part != NULL) 
            {
                position = part-filepath;
                part = strchr(part+1,'.');
            }
        }
        // if filename dones't contain dot
        else {
            position = strlen(filepath);
        }
        
        // write and compare file name 
        char* file_name = malloc(4); 
        strncpy(file_name, filepath+position2+1, position-position2-1);
        // printf("%s \n", file_name); // for test 
        if(strcmp(file_name, name)==0)
        {
            add_node(&tail,filepath); // add required node
        } 
        
        filelist_temp = filelist_temp->next;
    }
	return filelist_result->next;
}

void printer_filepath(node * filelist)
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

int main()
{

	node *dummy, *tail, *head;

	char *filepath0 = "~/environment/OprerSys_Proj3/afolder3/test.txt";
	char *filepath1 = "~/environment/OprerSys_Proj3/afolder3/afile4.txt";
	char *filepath2 = "~/environment/OprerSys_Proj3/afolder1/afile2.txt";
	char *filepath3 = "~/environment/OprerSys_Proj3/afolder1/afolder2/afile2.txt";
	char *filepath4 = "~/environment/OprerSys_Proj3/afolder1/afolder4/test";
 	
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
	add_node(&tail, filepath4);
 	
 	head = dummy->next;
 	
 	printf("All filepaths: \n");
    printer_filepath(head);
 	
 	char* test = "test";
 	node* result1 = search_by_name(test, head);
//  	node* result2 = search_by_modification_time("+10", head);
//  	node* result3 = search_by_inode("1159042912", head);
    
    // test
    printf("Seach_by_name filepath: \n");
    printer_filepath(result1);
    // printf("Seach_by_modification_time filepath: \n");
    // printer_filepath(result2);
    // printf("Seach_by_inode filepath: \n");
    // printer_filepath(result3);
    
 	free_list(dummy);
 	return SUCCESS;
}

// REFERENCE: Exampe returned from search function: 
// find .
// ./main.o
// ./file_name_test.h
// ./.DS_Store
// ./test1.txt
// ./test2.txt
// ./dir3/test7.txt
// ./dir3/test8.txt
// ./linkedlist.o
// ./linkedlist.h
// ./node.h
// ./main.c
// ./linkedlist_test.c
// ./dir1/test4.txt
// ./dir1/.DS_Store
// ./dir1/test3
// ./dir1/dir2/test6.txt
// ./dir1/dir2/test5.txt
// ./dir1/dir2/.DS_Store
// ./main
// ./linkedlist.c
