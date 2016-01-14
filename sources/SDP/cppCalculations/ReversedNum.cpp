#include "ReversedNum.h"

int ReversedNum::Reversion(const int num)
{
    int reversion=0;
    int temp=0;
    int temp_num=num;
    while(temp_num!=0)
    {
        temp=temp_num%10;
        temp_num=temp_num/10;
        reversion=reversion*10+temp;
    }
    return reversion;
}
