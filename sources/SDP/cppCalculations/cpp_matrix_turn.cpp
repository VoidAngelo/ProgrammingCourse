#include "cpp_matrix_turn.h"

cpp_matrix_turn::cpp_matrix_turn()
{
    matrix = new int* [size_of_matrix];
        for (int i = 0; i < size_of_matrix; i++)
            matrix[i] = new int [size_of_matrix];
    matrix_turned = new int* [size_of_matrix];
        for (int i = 0; i < size_of_matrix; i++)
            matrix_turned[i] = new int [size_of_matrix];
}

cpp_matrix_turn::~cpp_matrix_turn()
{
    delete[] matrix;
    delete[] matrix_turned;
}

void cpp_matrix_turn::enter_matrix(int number, int** matr)
{
    size_of_matrix=number;
    for(int i=0; i<size_of_matrix; i++)
        for(int j=0; j<size_of_matrix; j++)
        {
            matrix[i][j]=matr[i][j];
        }
}

void cpp_matrix_turn::turn_matrix()
{
    for(int i=0; i<size_of_matrix; i++)
    {
        for(int j=0; j<size_of_matrix; j++)
        {
            matrix_turned[i][j]=matrix[size_of_matrix-1-j][i];
        }
    }
}

int cpp_matrix_turn::get_turned_matrix()
{
    cout<<"Turn is: ";
    for(int i=0; i<size_of_matrix; i++)
    {
        for(int j=0; j<size_of_matrix; j++)
        {
            cout<<matrix_turned[i][j]<<" ";
        }
        cout<<endl;
    }
    return **matrix_turned;
}
