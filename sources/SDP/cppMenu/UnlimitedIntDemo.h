#ifndef CPP_INT_UNLIM_INP
#define CPP_INT_UNLIM_INP

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
    //void checkCopy(ArrayApp &) const;
    UnlimitedInt num1;
    UnlimitedInt num2;
public:
    void demo();
};

#endif // CPP_INT_UNLIM_INP

