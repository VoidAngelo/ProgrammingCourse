#include"c_multiples.h"

int c_calc_multiples(int *array_2)
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
         printf("����� ����� ���\n\n");
    return temp;
}

