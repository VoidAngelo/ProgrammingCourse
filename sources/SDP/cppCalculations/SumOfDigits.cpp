#include "SumOfDigits.h"

SumOfDigits::SumOfDigits()
{
    num = 123;
}

SumOfDigits::SumOfDigits(int number)
{
    num=number;
}

int SumOfDigits::Sum()
{
    int sum=0;
    int temp=0;
    while(num!=0)
    {
        temp=num%10;
        num=num/10;
        sum=sum+temp;
    }
    return sum;
}




