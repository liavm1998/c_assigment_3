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
    if(strlen(word)==0||strlen(text)==0)
    {
        printf("Gematria Sequences: ");    
        printf("\nAtbash Sequences: ");
        printf("\nAnagram Sequences: ");    
        return 0;
    }
    /////Q1
    ans=Q1(word,text);
    printf("Gematria Sequences: %s",ans);
    ////Q2
    ans=Q2(word,text);
    printf("\nAtbash Sequences: %s",ans);
    ////Q3
    ans=Q3(word,text);
    printf("\nAnagram Sequences: %s",ans);
    return 0;
}

