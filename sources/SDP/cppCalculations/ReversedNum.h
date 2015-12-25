#ifndef CPP_REVERSED_NUM
#define CPP_REVERSED_NUM

#include <iostream>

using namespace std;

class cpp_reversed_num
{
private:
    int num;
    int reversion;

public:
    cpp_reversed_num();
    ~cpp_reversed_num();
    void enter_number(int);
    void reversion_of_num();
    int get_reversion();
};

#endif // CPP_REVERSED_NUM

