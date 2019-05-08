#ifndef _NODEH_
#define _NODEH_
#define MAX_TOKEN_LENGTH 256
typedef struct node {
	char  filepath[MAX_TOKEN_LENGTH];
	struct node* next;
} node;

#endif
