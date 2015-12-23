#ifndef CPP_MULTIPLES
#define CPP_MULTIPLES

#include <iostream>

using namespace std;

class cpp_multiples
{
private:
    int numbers[3];
    int amount;

public:
    cpp_multiples();
    ~cpp_multiples();
    void enter_numbers(int*);
    void find_multiples();
    int get_amount();
};

#endif // CPP_MULTIPLES

