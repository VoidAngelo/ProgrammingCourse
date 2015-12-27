#include "ReversedNum.h"

ReversedNum::ReversedNum()
{
    num=123;
}

ReversedNum::ReversedNum(int number)
{
    num=number;
}

int ReversedNum::Reversion()
{
    int reversion=0;
    int temp=0;
    while(num!=0)
    {
        temp=num%10;
        num=num/10;
        reversion=reversion*10+temp;
    }
    return reversion;
}
