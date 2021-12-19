#include "QuesAnswers.h"
#include "helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{   
    char* word =scanWord();
    char* text =scanText();
    char* ans;
    /////Q1
    ans=Q1(word,text);
    printf("\nGematria Sequences:%s",ans);
    ////Q2
    ans=Q2(word,text);
    printf("Atbash Sequences:%s",ans);
    ////Q3
    ans=Q3(word,text);
    printf("\nAnagram Sequences:%s\n",ans);
    return 0;
}

