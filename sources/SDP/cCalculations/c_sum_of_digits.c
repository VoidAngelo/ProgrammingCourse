#include"c_sum_of_digits.h"

int c_calc_sum_of_digits(int num)
{
    int counted=0, temp=0;
    while(num!=0)
    {
        temp=num%10;
        num=num/10;
        counted=counted+temp;
    }
    return counted;
}
