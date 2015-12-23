#include "cpp_main.h"

cpp_int_unlim_inp::cpp_int_unlim_inp()
{

}

cpp_int_unlim_inp::~cpp_int_unlim_inp()
{

}

void cpp_int_unlim_inp::cpp_iu_inp()
{
    string s1, s2;
    vector<int> num1;
    vector<int> num2;

    cout << "Type number: ";
    cin>>s1;
    for(int i=0; i<s1.length(); i++)
    {
        char c = s1[i];
        if ((c>='0') && (c<='9'))
        {
            int n = c - '0';
            num1.push_back(n);
        }
    }

    cout << "Type number: ";
    cin>>s2;
    for(int i=0; i<s2.length(); i++)
    {
        char c = s2[i];
        if ((c>='0') && (c<='9'))
        {
            int n = c - '0';
            num2.push_back(n);
        }
    }

    iu.enter_numbers(num1, num2);
    iu.basic_calculations();
    iu.sum_of_iu();
    iu.get_sum();
    iu.subtraction_of_iu();
    iu.get_subtraction();
    iu.multiplication_of_iu();
    iu.get_multiplication();
    iu.iu_to_i();
    iu.get_int();
    cpp_int_unlim new_iu(iu);

    cout <<endl;

    system("pause");
    system("cls");
}
