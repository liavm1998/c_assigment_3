#include "helpers.h"
#include "QuesAnswers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TXT 1024
#define WORD 30

int gio(int c)
{
    if (c >= 65 && c <= 90)
    {
        c -= 64;
    }
    else if (c >= 97 && c <= 122)
    {
        c -= 96;
    }
    else
    {
        return 0;
    }
    return c;
}

int sumCal (char* txt, int s_pointer, int e_pointer)
{
    int sum = 0;
    for (int i = s_pointer; i < e_pointer; i++)
    {
        sum += gio(txt[i]);
    }
    return sum;
}

char *strrev(char *str){
   
    char *copy = malloc(strlen(str) + 1);
    strcpy(copy, str);
    int i;
	int j;
    unsigned char a;
    unsigned len = strlen((const char *)str);
    for (i = 0, j = len - 1; i < j; i++, j--)
	{
		a = copy[i];
		copy[i] = copy[j];
		copy[j] = a;
	}
    return copy;
}

void deletechar(char *s,char c)
{
	int i,temp=1,n;
 
    n=strlen(s); 
    
 
    for(i=0;i<n;i++)  
    {
     	 
       if(temp)
        {
          	 if(c==s[i])
          	{
				temp=0;
				 s[i]=s[i+1];
		    }
	    }
	    else
	     s[i]=s[i+1];
	   
    }
}

char *scanWord()
{
    ///////word scanning
    char *w;
    w=malloc (sizeof (char)*WORD);
    //printf("enter word\n");
    scanf("%s", w);
    return w;
}

char *scanText()
{
    ///////text reading Txt
    //printf("enter text\n");
    char *txt=malloc (sizeof (char)*TXT);
    int i=0;
    char c1=0;
    while((c1=getchar()) != '~') 
    {
        txt[i++] = c1;
    }
    return txt;
}