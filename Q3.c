#include "helpers.h"
#include "QuesAnswers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TXT 1024
#define WORD 30

char *Q3(char *w, char *txt)
{
    ////////ans dec
    char *ans = malloc(sizeof(char) * 780);
    memset(ans, 0, strlen(ans));

    /////////pointers declaration
    int s_pointer = 0;
    ///////////checker dec
    char *copy = malloc(sizeof(char) * strlen(w));
    strcpy(copy, w);
    /////////running thru the txt
    int stop = strlen(txt);
    for (int i = 0; i < stop; i++)
    {
        char cur = txt[i];
        if (cur == ' ')
        {
            continue;
        }
        //////////char is currect count it
        if (strchr(copy, cur) != NULL)
        {
            ///////delete cur char from copy
            deletechar(copy, cur);
        }
        else
        {
            if (strchr(w, cur) != NULL)
            {
                s_pointer++;
                ///////delete cur char from copy
                i=s_pointer;
                //deletechar(copy, cur);
            }
            else
            {
                s_pointer = i;
            }
            strcpy(copy, w);
            
        }
        if ((copy != NULL) && (copy[0] == '\0')) //////////we fount word
        {
            char *concat = malloc(sizeof(char) * 780);
            if(s_pointer==0)
            {
                strncpy(concat, txt + s_pointer, i - s_pointer+1);
            }
            else
            {
            strncpy(concat, txt + s_pointer + 1, i - s_pointer);
            }
            cur = concat[0];
            while (cur == ' ')
            {
                deletechar(concat, cur);
                cur = concat[0];
            }
            strcat(ans, concat);
            strcat(ans, "~");
            s_pointer = i;
            strcpy(copy, w);
        }
    }
    ans[strlen(ans) - 1] = '\0';
    return ans;
}