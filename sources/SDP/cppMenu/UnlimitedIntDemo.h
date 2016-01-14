#ifndef UNLIMITEDINT_INP
#define UNLIMITEDINT_INP

#include "UnlimitedInt.h"
#include <string>

using std::cin;
using std::cout;
using std::endl;

class UnlimitedIntDemo
{
private:
    void inputNums();
    void checkSum();
    void checkSubt();
    void checkMult();
    void checkToInt();
    UnlimitedInt num1;
    UnlimitedInt num2;
public:
    void demo();
};

#endif // CPP_INT_UNLIM_INP

