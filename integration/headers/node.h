#ifndef _NODEH_
#define _NODEH_

#define MAX_FILEPATH_LENGTH 256

typedef struct node {
	char filepath[MAX_FILEPATH_LENGTH];
	struct node* next;
} node;

#endif
