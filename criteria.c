// Added by May 4: This should be DELETED once we finished the project. Here is for reference. 

// NOTES: this code is UNCOMPLETED

/** 
 * CS4323 - OperSys - Proj3 - Step2 (Criteria)
 * @Author: YifeLi, FangdaGuo
 * @Date: 4/25/19
 * @LastModified: 5/2/19
 */
 
#include <stdio.h>
#include <dirent.h>
#include <time.h> // time model
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
 * -mmin: find the files modified within given minutes
 * @Para1 DIR* d
 * @Para2 int min - given minutes
 * @Return pointer node* - point to the first node in the list
 * @Exec - print all directories where the files are
 */
 node* timeModel(DIR* d, int min) {
   
	DIR *d = opendir(fileName);
	struct dirent *dir;
   
   //struct stat buf;
   
	// initalize
	node *find;
 	createnode(&find, "");
   
   // operation
    dir = readdir(d);
    while(dir != NULL)
    {
    	
    	// long modify_time = buf.st_mtime; // lastest modification time (s)
    	long modify_time = find.st_mtime; // lastest modification time (s)
		time_t now = time(0); // currect systme time
    	diff = now - modify_time;
    	diff /= 60; // convert second to minute
    	
    	// identify files modified within given time
    	if(min<0) {
    		if(diff < -min) {
    			 char *newfilepath = dir->d_name;
            	addnode(&pointer, newfilepath);
            	dir = readdir(d);
            	pointer = pointer->next;
    		}
    	// identify files modified longer than given time
    	} else {
    		if(diff > min) {
    			 char *newfilepath = dir->d_name;
            	addnode(&pointer, newfilepath);
            	dir = readdir(d);
            	pointer = pointer->next;
    		}
    	}
	}
	closedir(d);
 	return find;
 }

/**
 * -inum: find the files with given i-node number
 * @Para1 *DIR d
 * @Para2 int num - the i-node number
 * @Return pointer node* - point to the first node in the list
 * @Exec - print all directories where the files are
 */
 node* nodeModel(DIR* d, unsigned int num) {

	DIR *d = opendir(fileName);
	struct dirent *dir;
   
   //struct stat buf;
   
	// initalize
	node *find;
 	createnode(&find, "");
   
   // operation
    dir = readdir(d);
    while(dir != NULL)
    {
		if(num == find.st_ino) { // get node
			find->next = dir;
			find = find->next;
		} else { // skip node
			find->next = NULL;
		}
    	dir = readdir(d);
	}
	closedir(d);
 	return find;
}

 
// // /**
// //  * MAIN FUNCTION - criteria switcher 
// //  * @Para1 char option[] - the criteria model option (-name/mmin/inum)
// //  * @Para2 char order[] - the given specific order following criteria 
// //  * @Return N/A
// //  * @Exec - switch to the correct criteria
// //  */
// //  void criteriaSwitcher(DIR*, char order[]) {
// //     // -name
// //     if (option[1]=='n') {
// //         char * fileName = order;
// //         nameModel(FilePath(fileName));
// //     // -mmin
// //     } else if (option[1]=='m') {
// //         int min = atoi(order); // convert char array to integer
// //         timeModel(*dir, min);
// //     // -inum
// //     } else if {option[1]=='i') {
// //         int num = atoi(order); // convert char array to integer
// //         nodeModel(*dir, num);
// //     // wrong input processor
// //     } else {
// //         printf("Wrong criteria input\n");
// //         exit(0);
// //     }
// //  }
