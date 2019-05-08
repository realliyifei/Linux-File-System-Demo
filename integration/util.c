#include <stdio.h>
#include <stdlib.h>
#include "headers/util.h"
#include "headers/constant.h"
#include "headers/linkedlist.h"

int check_length(char user_input[])
{
    int ch_counter = 0;
    int space_counter = 0;
    int i = 0;
    while( i < MAX_TOKEN_LENGTH * MAXTOKEN && user_input[i] != '\n')
    {
        if(user_input[i] == ' ')
        {
            space_counter ++;
            
            if(space_counter > 5)
            {
                print_error_msg("Invalid input: Exceeding maximum length of command");
                return FALSE; // tokens of input is too long,
            }
            
            ch_counter = 0;
        }
        else
        {
            ch_counter++;
            
            if(ch_counter > 256)
            {
            	 print_error_msg("Invalid input: Exceeding maximum length of chars in a word");
                return FALSE; // token is too long,
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

    while( i < MAX_TOKEN_LENGTH * MAXTOKEN && user_input[i] != '\n')
    {
        if(user_input[i] == ' ')
        {
            tokens_2d[j][k] = '\0'; // string must end with '\0'
            j++;
            k = 0;
            i++;
            continue;
        }
        else
        {
            tokens_2d[j][k] = user_input[i];
            k++;
            i++;
        }
    }
    tokens_2d[j][k] = '\0';

 	for (int i = 0; i < MAXTOKEN; ++i)
 	{
 		tokens[i] = tokens_2d[i];
 	}

    return SUCCESS;
}

void print_list(node* list)
{

}

void print_error_msg(char* msg)
{
	printf( "%s\n", msg);
}