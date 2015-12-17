#include"c_reversed_num.h"

int c_calc_reversed_num(int num)
{
    int counted=0, temp=0;
    while(num!=0)
    {
        temp=num%10;
        num=num/10;
        counted=counted*10+temp;
    }
    return counted;
}
