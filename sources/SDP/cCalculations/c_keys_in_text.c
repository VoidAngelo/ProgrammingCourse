#include "c_keys_in_text.h"
#include "string.h"

void c_calc_keys_in_text(char **strings, char **keys, int num_of_strings, int num_of_keys, int *result)
{
    int i, j, n;
    char * match;
    for (i=0; i<num_of_keys; i++)
    {
        n=0;
        for (j=0; j<num_of_strings; j++)
        {
            match = strstr (strings[j], keys[i]);
            while (match != NULL)
            {
                match = strstr (match+1,keys[i]);
                n++;
            }
        }
        result[i]=n;
    }
}
