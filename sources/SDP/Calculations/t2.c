#include"t2.h"

int calc_t2(int *array_2)
{
    int temp = 0, i, j;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
        {
            if(i!=j && array_2[i]%array_2[j]==0)
            {
                printf("%d %d\n", array_2[i], array_2[j]);
                temp++;
            }
        }
    if (temp == 0)
         printf("Таких чисел нет\n\n");
    return temp;
}

