#include "QuesAnswers.h"
#include "helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *Q1(char*w,char*txt)
{
    ////length calculating
    int wlength = strlen(w);
    int tlength = strlen(txt);

    //word gio
    int wg = 0;
    for (int i = 0; i < wlength; i++)
    {
        int cur = w[i];
        cur = gio(cur);
        wg += cur;
    }

    int s_pointer = 0;
    int e_pointer = 0;
    char *c = malloc(sizeof(char) * 780);
    memset(c, 0, strlen(c));
    while (e_pointer <= tlength)
    {
        int sum = sumCal(txt, s_pointer, e_pointer);
        while (s_pointer == e_pointer && gio(txt[s_pointer]) == 0)
        {
            s_pointer++;
            e_pointer++;
            sum = sumCal(txt, s_pointer, e_pointer);
        }
        if (sum < wg)
        {
            e_pointer++;
        }
        if (sum > wg)
        {
            s_pointer++;
            e_pointer = s_pointer;
        }
        if (sum == wg)
        {
            int i = s_pointer;
            for (; i < e_pointer; i++)
            {
                char ch = txt[i];
                strncat(c, &ch, 1);
            }

            char ch = '~';
            strncat(c, &ch, 1);
            i--;
            s_pointer++;
            e_pointer=s_pointer;
        }
    }
    c[strlen(c) - 1] = '\0';
    // printf("%s", c);
    return c;
}