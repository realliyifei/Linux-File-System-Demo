// NOTES: this code is UNCOMPLETED

/** 
 * CS4323 - OperSys - Proj3 - Step2 (Criteria)
 * @Author: YifeLi, FangdaGuo
 * @Date: 4/25/19
 * @LastModified: 4/29/19
 */
 
#include <stdio.h>
#include <dirent.h>
typedef char* string;

#include "linkedlist.h" // use node struct created by @Shaw

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

node* recurDir(node* pointer, string name, string searchName) {
	
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
