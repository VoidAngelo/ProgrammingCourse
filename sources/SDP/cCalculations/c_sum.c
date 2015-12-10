#include"c_sum.h"
int c_calc_sum(int num)
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
