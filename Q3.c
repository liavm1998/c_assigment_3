#include "helpers.h"
#include "QuesAnswers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* Q3(char* w,char* txt)
{
    ////////ans dec
    char *ans= malloc(sizeof(char) * 780);
    memset(ans, 0, strlen(ans));
    
    /////////pointers declaration
    int s_pointer=0; 
    ///////////checker dec
    char*copy=malloc(sizeof(char) * strlen(w));
    strcpy(copy,w);
    /////////running thru the txt
    int stop=strlen(txt);
    for (int i = 0;i<stop;i++) 
    {    
        char cur=txt[i];
        if(cur==' ')
        {
            continue;
        }
        //////////char is currect count it
        if(strchr(copy,cur)!=NULL)
        {
            ///////delete cur char from copy
            deletechar(copy,cur);
        }
        else
        {
            s_pointer=i;
            strcpy(copy,w);
        }
        if ((copy != NULL) && (copy[0] == '\0'))//////////we fount word
        {
            char* concat= malloc(sizeof(char) * 780);
            strncpy(concat,txt+s_pointer+1,i-s_pointer);
            strcat(ans,concat);
            strcat(ans,"~");
            s_pointer=i;
        }
    }
    ans[strlen(ans) - 1] = '\0';
    return ans;   
}