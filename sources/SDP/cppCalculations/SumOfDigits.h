#ifndef CPP_SUM_OF_DIGITS
#define CPP_SUM_OF_DIGITS

#include <iostream>

using namespace std;

class cpp_sum_of_digits
{
private:
    int num;
    int sum;

public:
    cpp_sum_of_digits();
    ~cpp_sum_of_digits();
    void enter_number(int);
    void sum_of_digits();
    int get_sum();
};

#endif // CPP_SUM_OF_DIGITS

