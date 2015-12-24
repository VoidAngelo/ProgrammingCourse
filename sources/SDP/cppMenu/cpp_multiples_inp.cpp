#include "cpp_main.h"
#include "cpp_exceptions.h"

cpp_multiples_inp::cpp_multiples_inp()
{

}

cpp_multiples_inp::~cpp_multiples_inp()
{

}

void cpp_multiples_inp::cpp_numbers_inp()
{
    int exp;
    int num[3];
    cout<<"Type your numbers: ";
    for (int i=0; i<3; i++)
        cin>>num[i];
    try{
    mult.enter_numbers(num);
    }
    catch (OutOfRange& exp)
    {
    cout << "Number is more then 999. Current number: " << exp.getCurrentNumber() << endl;
    }
    mult.find_multiples();
    mult.get_amount();

    cout <<endl;

    system("pause");
    system("cls");
}
