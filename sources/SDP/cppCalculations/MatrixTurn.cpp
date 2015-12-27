#include "MatrixTurn.h"

MatrixTurn::MatrixTurn(int size)
{
    sizeOfMatrix=size;
    matrix = new int* [sizeOfMatrix];
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        matrix[i] = new int [sizeOfMatrix];
    }

    for (int i=0; i<sizeOfMatrix; i++)
    {
        for(int j=0; j<sizeOfMatrix; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

MatrixTurn::MatrixTurn(int size, int** imatrix)
{
    sizeOfMatrix=size;
    for(int i=0; i<sizeOfMatrix; i++)
    {
        for(int j=0; j<sizeOfMatrix; j++)
        {
            matrix[i][j]=imatrix[i][j];
        }
    }
}

MatrixTurn::MatrixTurn(MatrixTurn &obj)
{
    sizeOfMatrix=obj.sizeOfMatrix;
    for(int i=0; i<sizeOfMatrix; i++)
    {
        for(int j=0; j<sizeOfMatrix; j++)
        {
            matrix[i][j]=obj.matrix[i][j];
        }
    }
}

MatrixTurn::~MatrixTurn()
{
    for (int i=0; i<sizeOfMatrix; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
}

void MatrixTurn::putNum(int i, int j, int num)
{
    matrix[i][j] = num;
}


int MatrixTurn::getNum(int i, int j)
{
    return matrix[i][j];
}


void MatrixTurn::turnMatrix()
{
    int** matrix_turned = new int* [sizeOfMatrix];
    {
        for (int i = 0; i < sizeOfMatrix; i++)
        {
            matrix_turned[i] = new int [sizeOfMatrix];
        }
    }

    for(int i=0; i<sizeOfMatrix; i++)
    {
        for(int j=0; j<sizeOfMatrix; j++)
        {
            matrix_turned[i][j]=matrix[sizeOfMatrix-1-j][i];
        }
    }

    for(int i=0; i<sizeOfMatrix; i++)
    {
        for(int j=0; j<sizeOfMatrix; j++)
        {
            matrix[i][j]=matrix_turned[i][j];
        }
    }

    for (int i=0; i<sizeOfMatrix; i++)
    {
        delete [] matrix_turned[i];
    }
    delete [] matrix_turned;
}
