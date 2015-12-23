#include "cpp_reversed_num.h"

cpp_reversed_num::cpp_reversed_num()
{
    //num
}

cpp_reversed_num::~cpp_reversed_num()
{

}

void cpp_reversed_num::enter_number(int number)
{
    num=number;
}

void cpp_reversed_num::reversion_of_num()
{
    reversion=0;
    int temp=0;
    while(num!=0)
    {
        temp=num%10;
        num=num/10;
        reversion=reversion*10+temp;
    }
}

int cpp_reversed_num::get_reversion()
{
    cout<<"Reversion of digits is: ";
    cout<<reversion<<endl;
    return reversion;
}
