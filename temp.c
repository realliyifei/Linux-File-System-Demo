// NOTES: this code is UNCOMPLETED

// to @Da: continue to fill the three model functions 
// Question: should us use node pointer likes the example prog.c, I doubt 
// that I can write a better version than the example if using the same 
// structure

/** 
 * CS4323 - OperSys - Proj3 - Step2 (Criteria)
 * @Author: YifeLi, FangdaGuo
 * @Date: 4/25/19
 */
 
#include <stdio.h>
#include <dirent.h>

/**
 * -name: perform a name search
 * @Para char filename[] - given search file name
 * @Return pointer node* - point to the first node in the list
 * @Exec - print all directories where the files are
 */
 *node nameModel(char name[]) {
    
    // search, store, and print the directory containing given file
    
 } 

/**
 * -mmin: find the files modified within given minutes
 * @Para int min - given minutes
 * @Return pointer node* - point to the first node in the list
 * @Exec - print all directories where the files are
 */
 *node timeModel(int min) {
    
    // search files with modified time less than min
    if (min<0) {
    
    // search files with modified time more than min    
    } else if (min>0) {
        
    }
 }

/**
 * -inum: find the files with given i-node number
 * @Para int num - the i-node number
 * @Return pointer node* - point to the first node in the list
 * @Exec - print all directories where the files are
 */
 *node nodeModel(int num) {

    //
 }
 
/**
 * MAIN FUNCTION - criteria switcher 
 * @Para1 char option[] - the criteria model option (-name/mmin/inum)
 * @Para2 char order[] - the given specific order following criteria 
 * @Return N/A
 * @Exec - switch to the correct criteria
 */
 void criteriaSwitcher(char option[],char order[]) {
    // -name
    if (option[1]=='n') {
        nameModel(order);
    // -mmin
    } else if (option[1]=='m') {
        int min = atoi(order); // convert char array to integer
        timeModel(min);
    // -inum
    } else if {option[1]=='i') {
        int num = atoi(order); // convert char array to integer
        nodeModel(num);
    // wrong input processor
    } else {
        printf("Wrong criteria input\n");
        exit(0);
    }
 }
