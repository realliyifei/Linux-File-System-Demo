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
 	node *find;
 	createnode(&find, "");
    node * pointer = find->next;
    // operation
    dir = readdir(d);
    while(dir != NULL)
    {
        // compare
        if(strcmp(dir->d_name,name)==0) 
        {
            char *newfilepath = dir->d_name;
            addnode(&pointer, newfilepath);
            dir = readdir(d);
            pointer = pointer->next;
        } else {
			pointer = recurDir(pointer,name,dir->d_name);	
        }
    }
    closedir(d);

 	return find;
}

node* recurDir(node* n, string name, string searchName) {
	
	DIR *d = opendir(fileName);
	
	if(d==NULL) {
		return NULL;
	} else {
		struct dirent *dir;
		dir = readdir(d);
		while(dir != NULL)
	    {
	        // compare
	        if(strcmp(dir->d_name,name)==0) 
	        {
	            char *newfilepath = dir->d_name;
	            addnode(&pointer, newfilepath);
	            dir = readdir(d);
	            pointer = pointer->next;
	        } else {
	        	pointer = recurDir(pointer,name,dir->d_name);	
	        }
	    }
	    closedir(d);
	}
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
