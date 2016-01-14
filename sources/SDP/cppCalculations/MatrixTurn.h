#ifndef CPP_MATRIX_TURN
#define CPP_MATRIX_TURN

#include <iostream>

using namespace std;

class MatrixTurn
{
private:
    int **matrix;
    int sizeOfMatrix;

public:
    MatrixTurn(int);
    MatrixTurn(int, int**);
    MatrixTurn(MatrixTurn &);
    ~MatrixTurn();
    void putNum(int , int, int);
    int getNum(int , int);
    void turnMatrix() const;
};

#endif // CPP_MATRIX_TURN

