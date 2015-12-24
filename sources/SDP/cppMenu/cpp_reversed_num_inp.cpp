#include "cpp_main.h"

cpp_reversed_num_inp::cpp_reversed_num_inp()
{

}

cpp_reversed_num_inp::~cpp_reversed_num_inp()
{

}

void cpp_reversed_num_inp::cpp_number_inp()
{
    int num;
    cout<<"Type your number: ";
    cin>>num;

    reverse.enter_number(num);
    reverse.reversion_of_num();
    reverse.get_reversion();

    cout <<endl;

    system("pause");
    system("cls");
}
