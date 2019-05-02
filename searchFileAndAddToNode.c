/** 
 * CS4323 - OperSys - Proj3 - Step2 (Search file and put it into node(linkedlist))
 * @Author: YifeLi, FangdaGuo
 * @Date: 5/1/19
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "linkedlist.h"

//char img_path[500][1000];
//int img_num=0;
int readFileList(char *basePath, node *chainHead) //put node head here
{
    //create(&chainHead, "");
    DIR *dir;
    struct dirent *ptr;
    //char base[1000];

    if ((dir=opendir(basePath)) == NULL)
    {
        perror("Open dir error...");
        exit(1);
    }

    while ((ptr=readdir(dir)) != NULL)
    {
        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
            continue;
        else if(ptr->d_type == 8)    ///file
            {
                addnode(chainHead,ptr->d_name)
	      // strcpy(img_path[img_num],basePath);
            //   strcat(img_path[img_num++],ptr->d_name);

	    }

        else 
        {

	    continue;
        }
    }
    closedir(dir);
    return 1;
}
/*int main()
{
    printf("Enter Image Path: ");
    fflush(stdout);
    char basePath[100]="data/";
    input=fgets(input, 256, stdin);
    if(!input) return;
    strtok(input, "\n");
    strcat(basePath,input);
    strcat(basePath,"/");
    
    readFileList(basePath);
	
	for(int i = 0;img_path[i][0] != NULL;i++){
		for (int j = 0;img_path[i][j] !=NULL; j++){
			printf("%c",img_path[i][j]);
		
		}
		printf("\n");
	}
}
*/