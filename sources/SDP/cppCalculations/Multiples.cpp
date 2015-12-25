#include "Multiples.h"
#include "Exceptions.h"

cpp_multiples::cpp_multiples()
{

}

cpp_multiples::~cpp_multiples()
{

}


void cpp_multiples::enter_numbers(int *number)
{
    for (int i=0; i<3; i++)
    {
        numbers[i]=number[i];
        if (numbers[i]>999)
        {
            throw OutOfRange(*numbers);
        }
    }
}

void cpp_multiples::find_multiples()
{
    amount=0;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
        {
            if(i!=j && numbers[i]%numbers[j]==0)
            {
                amount++;
            }
        }
}

int cpp_multiples::get_amount()
{
    if (amount == 0)
         cout<<"Таких чисел нет\n\n";
    else
    {
        cout<<"Amount of multiples found: ";
        cout<<amount<<endl;
    }
    return amount;
}
