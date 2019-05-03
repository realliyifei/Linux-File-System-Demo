#ifndef _SEARCHH_
#define _SEARCHH_

#include "node.h"

node* search_by_name(char* token3, node* filelist);
node* search_by_modification_time(char* token3, node* filelist);
node* search_by_inode(char* token3, node* filelist);

#endif
