#include "cpp_main.h"

cpp_sum_of_digits_inp::cpp_sum_of_digits_inp()
{

}

cpp_sum_of_digits_inp::~cpp_sum_of_digits_inp()
{

}

void cpp_sum_of_digits_inp::cpp_number_inp()
{
    int num_t1;
    cout<<"Type your number: ";
    cin>>num_t1;

    sum.enter_number(num_t1);
    sum.sum_of_digits();
    sum.get_sum();

    cout <<endl;

    system("pause");
    system("cls");
}


