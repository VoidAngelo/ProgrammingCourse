#include "SumOfDigits.h"

int SumOfDigits::Sum(const int num)
{
    int sum=0;
    int temp=0;
    int temp_num=num;
    while(temp_num!=0)
    {
        temp=temp_num%10;
        temp_num=temp_num/10;
        sum=sum+temp;
    }
    return sum;
}




