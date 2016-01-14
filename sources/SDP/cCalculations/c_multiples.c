#include"c_multiples.h"

int c_calc_multiples(int *numbers)
{
    int trigger = 0, i, j;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
        {
            if(i!=j && numbers[i]%numbers[j]==0)
            {
                printf("%d %d\n", numbers[i], numbers[j]);
                trigger++;
            }
        }
    if (trigger == 0)
         printf("Таких чисел нет\n\n");
    return trigger;
}
