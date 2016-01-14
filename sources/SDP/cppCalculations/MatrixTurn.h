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
    MatrixTurn(const MatrixTurn &);
    ~MatrixTurn();
    void putNum(const int , const int, const int);
    int getNum(const int , const int);
    void turnMatrix() const;
};

#endif // CPP_MATRIX_TURN

