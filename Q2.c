#include "QuesAnswers.h"
#include "helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* Q2(char* w,char* txt)
{
    ////length calculating
    int wlength = strlen(w);
    //int tlength = strlen(txt);


    //// create atbash word in the length of the accepted word
    char *atbash=malloc(sizeof(char) * wlength);
    ////calculate atbash
    int i=0;
    while(w[i]!='\0')
    {
        if(w[i]>='a'&&w[i]<='z')
        {
            atbash[i]='z'+'a'-w[i];
        }
        if(w[i]>='A'&&w[i]<='Z')
        {
            atbash[i]='Z'+'A'-w[i];
        }
        i++;
    }
    ////create reverse atbash
    char* Ratbash= strrev(atbash);
    
    
    if(strcmp("",atbash)==0&&strcmp("",Ratbash)==0)
    {
        return "";
    }
    
    
    char *ans= malloc(sizeof(char) * 780);
    memset(ans, 0, strlen(ans));
    int stop=strlen(txt);
    for (i = 0;i<stop;) 
    {
        if (strstr(&txt[i], atbash) != NULL&&strstr(&txt[i], Ratbash) != NULL) 
        {
            int a=strstr(&txt[i], atbash)-&txt[i];
            int r=strstr(&txt[i], Ratbash)-&txt[i];
            if(a<r)
            {
                strcat(ans,atbash);
                i=a;
                i+=wlength-1;
                
            }
            else
            {
                
                strcat(ans,Ratbash);
                i=r;
                i+=wlength-1;
                
            }
        }
        else if (strstr(&txt[i], atbash) != NULL) 
        {
            int a=strstr(&txt[i], atbash)-&txt[0];
            strcat(ans,atbash);
            i=a;
            i+=wlength-1;
        }
        else if (strstr(&txt[i], atbash) != NULL) 
        {
            int r=strstr(&txt[i], Ratbash)-&txt[i];
            strcat(ans,Ratbash);
            i=r;
            i+=wlength-1;
        }
        else
        {
            break;
        }
        strcat(ans,"~");
    }
    ans[strlen(ans) - 1] = '\0';
    return ans;
}