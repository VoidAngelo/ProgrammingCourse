#include "c_matrix_turn.h"
#include "malloc.h"

void c_calc_matrix_turn(int size_of_matrix, int **matrix)
{
    int i, j;
    int **matrix_temp;
    matrix_temp = (int**)malloc(size_of_matrix*sizeof(int*));
    for(i=0; i<size_of_matrix; i++)
    {
        matrix_temp[i] = (int*)malloc(size_of_matrix*sizeof(int));
    }
    for(i=0; i<size_of_matrix; i++)
    {
        for(j=0; j<size_of_matrix; j++)
        {
            matrix_temp[i][j]=matrix[size_of_matrix-1-j][i];
        }
    }
    for(i=0; i<size_of_matrix; i++)
    {
        for(j=0; j<size_of_matrix; j++)
        {
            matrix[i][j]=matrix_temp[i][j];
        }
    }
    for(i=0; i<size_of_matrix; i++)
    {
        free(matrix_temp[i]);
    }
    free(matrix_temp);
}
