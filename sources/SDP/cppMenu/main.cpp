#include <iostream>
#include "longints.h"


using namespace std;

int main()
{
    longints longint;
    int num;
    std::cout << "Num: ";
    std::cin>>num;

    longint.calc_longint(num);

    std::cout << "Sum of digits is " << longint.return_longint() << std::endl;

    return 0;
}
