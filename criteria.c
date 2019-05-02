// NOTES: this code is UNFINISHED

/** 
 * CS4323 - OperSys - Proj3 - Step2 (Criteria)
 * @Author: YifeLi, FangdaGuo
 * @Date: 4/25/19
 */
 
#include <stdio.h>
#include <dirent.h>
#include "linkedlist.h"

/**
 * -name: perform a name search
 * @para pointer DIR* - the file pointer (from helper function)
 * @para string name - file name
 * @Return pointer node* - point to the first node in the list
 * @Exec - tranverse and print all directories where the files are
 */
 node* nameModel(DIR* d, string name) {
 	
 	struct dirent *dir;
    
    // initalize
    // char* filepath;
 	node *find;
 	createnode(&find, "");
    
    // operation
    d = opendir(name);
    if(d != NULL)
    {
        dir = readdir(d);
        
        while(dir != NULL)
        {
            // printf("%s\n", dir->d_name);
            // compare
            // if(strcmp(dir->d_name,name)) 
            // {
            	node* next;
	            char *newfilepath = dir->d_name;
	            addnode(&next, newfilepath);
	            dir = readdir(d);
            // }
        }
        closedir(d);
    }
 	
 //	while(find*!=NULL) {
	// 	if((strcasestr(find.filepath, name) != NULL)
	// 	filepath = fide->filepath;
		
	// 	if((strcasestr(DIR->data,name))!=NULL) {
	// 		node
	// 	}
	// }
 	
 	// return function
 	return find;
 	
}

/**
 * -mmin: find the files modified within given minutes
 * @Para int min - given minutes
 * @Return pointer node* - point to the first node in the list
 * @Exec - print all directories where the files are
 */
 node* timeModel(node *dir, int min) {
   
   	struct stat sb;
	time_t now = time(NULL);
	node	*root = malloc(sizeof(node)),
			*prev = root;
	int range = abs(min),
		diff, valid;


	while(dir != NULL) {
		stat(dir->data, &sb);
		valid = 0;

		diff = now - sb.st_mtime;
		diff /= 60; // minutes not seconds

		switch(mmin[0]) {
			case '+': // more than
				valid = (diff > range);
				break;
			case '-': // less than
				valid = (diff < range);
				break;
			default: // exactly
				valid = (diff == range);
				break;
		}

		if(valid) { // keep node
			prev->next = dir;
			prev = prev->next;
		} else { // skip node
			// free(prev->next);
			prev->next = NULL;
		}

		dir = dir->next; // go to next
	}

	// nothing if only init node
	// otherwise, first real node
	return (root == prev) ? NULL : root->next;
    
    // // search files with modified time less than min
    // if (min<0) {
        
    // // search files with modified time more than min    
    // } else if (min>0) {
        
    // }
 }

/**
 * -inum: find the files with given i-node number
 * @Para int num - the i-node number
 * @Return pointer node* - point to the first node in the list
 * @Exec - print all directories where the files are
 */
 node* nodeModel(node *dir, unsigned int num) {

    struct stat sb;
	node	*root = malloc(sizeof(node)),
			*prev = root;

	while(list != NULL) {
		stat(list->data, &sb);
		if(num == sb.st_ino) { // keep node
			prev->next = list;
			prev = prev->next;
		} else { // skip node
			// free(prev->next);
			prev->next = NULL;
		}

		list = list->next; // go to next
	}

	// nothing if only init node
	// otherwise, first real node
	return (root == prev) ? NULL : root->next;
 }
 
/**
 * MAIN FUNCTION - criteria switcher 
 * @Para1 char option[] - the criteria model option (-name/mmin/inum)
 * @Para2 char order[] - the given specific order following criteria 
 * @Return N/A
 * @Exec - switch to the correct criteria
 */
 void criteriaSwitcher(char option[], char order[]) {
    // -name
    if (option[1]=='n') {
        char * fileName = order;
        nameModel(FilePath(fileName));
    // -mmin
    } else if (option[1]=='m') {
        int min = atoi(order); // convert char array to integer
        timeModel(*dir, min);
    // -inum
    } else if {option[1]=='i') {
        int num = atoi(order); // convert char array to integer
        nodeModel(*dir, num);
    // wrong input processor
    } else {
        printf("Wrong criteria input\n");
        exit(0);
    }
 }
