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
 * @Return pointer node* - point to the first node in the list
 * @Exec - tranverse and print all directories where the files are
 */
 node* nameModel(node *dir) {
    
    struct dirent *dp;
    
    // search, store, and print the directory containing given file
    if(dir != NULL) {
		while ((dp=readdir(dir)) != NULL) {
			// skip . & .. directories
			if ( strcmp(dp->d_name, ".") && strcmp(dp->d_name, "..") ) {
				// path = "dir_name/file_name"
				string path = malloc(sizeof(char) * (strlen(dir_name) + strlen(dp->d_name) + 1)); // alloc temp full path
				path = strcpy(path, dir_name); // append dir
				strcat(path, "/"); // append potential dir
				strcat(path, dp->d_name);

				// prepare for new node
				last->next = (node*)malloc(sizeof(node));
				last = last->next;
				last->data = path;
				last->next = read_dir(path); // recursive

				// skip to end
				while(last->next != NULL)
					last = last->next;
			}
		}
		closedir(dir);
	}

	// nothing if only init node
	// otherwise, first real node
	return (root == last) ? NULL : root->next;
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
