#include"t5.h"
#include "string.h"

void calc_t5(char **text, char **key, int t, int k, int *result)
{
    int i, j, n;
    char * pch;
    for (i=0; i<k; i++)
    {
        n=0;
        for (j=0; j<t; j++)
        {
            pch = strstr (text[j], key[i]);
            while (pch != NULL)
            {
                pch = strstr (pch+1,key[i]);
                n++;
            }
        }
        result[i]=n;
    }
}
