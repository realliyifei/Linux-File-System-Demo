#ifndef _SEARCHH_
#define _SEARCHH_

#include "node.h"

node* search_by_name(char* name, node* filelist);
node* search_by_modification_time(char* min, node* filelist);
node* search_by_inode(char* inum, node* filelist);

#endif
