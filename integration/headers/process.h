#ifndef _PROCESSH_
#define _PROCESSH_

#include "node.h"

int process_find(char *token0);
node *process_location(char *token1);
node *process_criteria(char *token2, char *token3, node *filelist);
int process_delete(char *token4, char *token5, node *qualified_list);

#endif
