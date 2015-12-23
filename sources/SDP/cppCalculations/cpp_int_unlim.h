#ifndef INT_UNLIM_UI_H
#define INT_UNLIM_UI_H

#include <iostream>
#include <vector>
#include <iterator>
#include <string>


using namespace std;

class cpp_int_unlim
{
private:
    vector<int> num1;
    vector<int> num2;
    vector<int> min_num;
    vector<int> max_num;
    vector<int> sum;
    vector<int> subt;
    vector<int> mult;
    int size_of_num1;
    int size_of_num2;
    int size_of_min;
    int size_of_max;
    int size_of_result;
    int trigger;
    int num1_to_i;
    int num2_to_i;
    int test;

public:
    cpp_int_unlim();
    cpp_int_unlim(vector<int>, vector<int>);
    cpp_int_unlim(const cpp_int_unlim& obj);
    ~cpp_int_unlim();
    void enter_numbers(vector<int>, vector<int>);
    void basic_calculations();
    void sum_of_iu();
    int get_sum();
    void subtraction_of_iu();
    int get_subtraction();
    void multiplication_of_iu();
    int get_multiplication();
    void iu_to_i();
    void get_int();

};

#endif // INT_UNLIM_UI_H
