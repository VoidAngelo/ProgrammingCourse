#include"c_matrix.h"
#include "malloc.h"

void c_calc_matrix(int square, int **matrix)
{
    int i, j;
    int **matrix_temp;
    matrix_temp = (int**)malloc(square*sizeof(int*));
    for(i=0; i<square; i++)
    {
        matrix_temp[i] = (int*)malloc(square*sizeof(int));
    }
    for(i=0; i<square; i++)
    {
        for(j=0; j<square; j++)
        {
            matrix_temp[i][j]=matrix[square-1-j][i];
        }
    }
    for(i=0; i<square; i++)
    {
        for(j=0; j<square; j++)
        {
            matrix[i][j]=matrix_temp[i][j];
        }
    }
    for(i=0; i<square; i++)
    {
        free(matrix_temp[i]);
    }
    free(matrix_temp);
}
