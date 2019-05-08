#include <stdlib.h>
#include "headers/search.h"
#include "headers/linkedlist.h"

node* search_by_name(char* token3, node* filelist)
{
    return NULL;
}

node* search_by_modification_time(char* token3, node* filelist)
{
    DIR *dir;

    char *filepath;
    int position;
    int position2;

    dir = opendir(filelist->filepath);

    node *filelist_temp = filelist;
    node *filelist_result;
    node *tail;
    create_node(&filelist_result, "");
    tail = filelist_result;

    while (filelist_temp != NULL)
    {
        filepath = filelist_temp->filepath;

        // find the position of the last slash "/"
        char *part2;
        part2 = strchr(filepath, '/');
        while (part2 != NULL)
        {
            position2 = part2 - filepath;
            part2 = strchr(part2 + 1, '/');
        }

        // find the position of the last dot "."
        char *part;
        part = strchr(filepath, '.');
        // if filename contains dot
        if (part != NULL)
        {
            while (part != NULL)
            {
                position = part - filepath;
                part = strchr(part + 1, '.');
            }
        }
        // if filename dones't contain dot
        else
        {
            position = strlen(filepath);
        }

        // write and compare file name
        char *file_name = malloc(4);
        strncpy(file_name, filepath + position2 + 1, position - position2 - 1);

        /* hui's fix: add '\0' to the end of the file_name */
        file_name[position - position2 - 1] = '\0';
        //printf("%s \n", file_name); // for test

        if (strcmp(file_name, name) == 0)
        {
            add_node(&tail, filepath); // add required node
        }

        filelist_temp = filelist_temp->next;
    }
    printf("\n");
    return filelist_result->next;
}

node* search_by_inode(char* token3, node* filelist)
{
    return NULL;
}
