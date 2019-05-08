#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/util.h"
#include "headers/constant.h"
#include "headers/linkedlist.h"

int check_length(char user_input[])
{
    int ch_counter = 0;
    int space_counter = 0;
    int i = 0;
    while( i < MAX_TOKEN_LENGTH * MAXTOKEN - 1  && user_input[i] != '\n')
    {
        if(user_input[i] == ' ' && user_input[i+1] != ' ')
        {
            space_counter ++;
            if(space_counter > MAXTOKEN - 1)
            {
                print_error_msg("Invalid input: Exceeding maximum length of command");
                return FAILURE; // tokens of input is too long,
            }
            
            ch_counter = 0;
        }
        else if (user_input[i] != ' ' )
        {
            ch_counter++;
            
            if(ch_counter > MAX_TOKEN_LENGTH)
            {
                print_error_msg("Invalid input: Exceeding maximum length of chars in a word");
                return FAILURE; // token is too long,
            }
        }
        i++;
    }
    return SUCCESS; // the length of input is valid
}
int convert_user_instruction(char user_input[], char* tokens[])
{
	int i = 0;
    int j = 0;
    int k = 0;
    char tokens_2d[MAXTOKEN][MAX_TOKEN_LENGTH] = {"","","","","",""};

    while( i < MAX_TOKEN_LENGTH * MAXTOKEN - 1 && user_input[i] != '\n')
    {
        if(user_input[i] == ' ' && user_input[i+1] != ' ' )
        {
            if(k != 0)
            {
                tokens_2d[j][k] = '\0';// string must end with '\0'
                j++;
            }
            k = 0;
            i++;
            continue;
        }
        else if(user_input[i] != ' ')
        {
            tokens_2d[j][k] = user_input[i];
            k++;
            i++;
        }
        else
            i++;
    }

    tokens_2d[j][k] = '\0';

 	for (int i = 0; i < MAXTOKEN; ++i)
 	{
 		tokens[i] = tokens_2d[i];
 	}

    return SUCCESS;
}

void get_current_path(char* buffer, char* filename)
{
    if(strcmp(filename,".")==0 || strcmp(filename,"")==0)
    {
        strcpy(buffer,"");
    }
    else
    {
        strncpy(buffer, filename, MAX_TOKEN_LENGTH);
        strcat(buffer,"/");
    }
}

void print_list(node* list)
{
    node* pointer = list;
    while(pointer != NULL)
    {
        printf("%s\n", pointer->filepath);
        pointer = pointer->next;
    }

}

void print_error_msg(char* msg)
{
	printf( "%s\n", msg);
}