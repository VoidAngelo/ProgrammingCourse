#ifndef CPP_MATRIX_TURN
#define CPP_MATRIX_TURN

#include <iostream>

using namespace std;

class cpp_matrix_turn
{
private:
    int **matrix;
    int size_of_matrix;

public:
    cpp_matrix_turn();
    ~cpp_matrix_turn();
    void enter_matrix(int, int**);
    void turn_matrix();
    int get_turned_matrix();
    int **matrix_turned;
};

#endif // CPP_MATRIX_TURN

