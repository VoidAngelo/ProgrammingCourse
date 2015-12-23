#include "cpp_sum_of_digits.h"

cpp_sum_of_digits::cpp_sum_of_digits()
{

}

cpp_sum_of_digits::~cpp_sum_of_digits()
{

}


void cpp_sum_of_digits::enter_number(int number)
{
    num=number;
}

void cpp_sum_of_digits::sum_of_digits()
{
    sum=0;
    int temp=0;
    while(num!=0)
    {
        temp=num%10;
        num=num/10;
        sum=sum+temp;
    }
}

int cpp_sum_of_digits::get_sum()
{
    cout<<"Sum of digits is: ";
    cout<<sum<<endl;
    return sum;
}




