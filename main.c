//
//  main.c
//  Virtual_FileSystem
//
//  Created by Zhiming Zou on 4/18/19.
//  Copyright © 2019 Zhiming Zou. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "file_name_test.h"

#define max_input_token 6
#define max_length_of_characters 256
#define TRUE 1
#define FALSE 0

int main(int argc, const char * argv[]) {
    //Prompt about the usage of the function
    prompt_helper();
    char original_input[max_length_of_characters*6];
    char user_input[max_input_token][max_length_of_characters];
    fflush(stdin);
    fgets(original_input,max_length_of_characters*6,stdin);
    if(checkerLength(original_input) == TRUE)
    {
        convert_original_to_userInput(original_input, user_input);
    }
    // check the first token
    //printf("%d\n", checker_first_token(user_input[0]));
    printFilePath(user_input[1]);
    ////////////////////////////////////////////////////
    //
    //
    ////////////////////////////////////////////////////
    /* DIR * d;
    if((d = FilePath(user_input[1])) != NULL)
    {
        if(strcmp(user_input[4], "\n") == 0) // if the fourth token is not delete instead of "\n"
        {
            if(strcmp(user_input[2], "-name") == 0)
            {
                //call_find_by_name(d, user_input[3]);
            }
            else if(strcmp(user_input[2], "-mmin") == 0)
            {
                //call_find_by_modified_minute(d, user_input[3]);
            }
            else if(strcmp(user_input[2], "-inum") == 0)
            {
                //call_find_by_modified_minute(d, user_input[3]);
            }
        }
        else if (strcmp(user_input[4], "-delete") == 0)// if the fourth token is delete
        {
            if(strcmp(user_input[2], "-name") == 0)
            {
                //call_delete(call_find_by_name(d, user_input[3]));
            }
            else if(strcmp(user_input[2], "-mmin") == 0)
            {
                //call_delete(call_find_by_modified_minute(d, user_input[3]));
            }
            else if(strcmp(user_input[2], "-inum") == 0)
            {
                //call_delete(call_find_by_modified_minute(d, user_input[3]));
            }
        }
    }*/
    return  0;
}



