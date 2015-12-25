/*#include "cpp_keys_in_text.h"

cpp_keys_in_text::cpp_sum_of_digits()
{

}
cpp_keys_in_text::~cpp_sum_of_digits()
{

}


void cpp_keys_in_text::enter_number(int number)
{
    num=number;
}
void cpp_keys_in_text::c_calc_keys_in_text(char **strings, char **keys, int num_of_strings, int num_of_keys, int *result)
{
    int i, j, n;
    char * match;
    for (i=0; i<num_of_keys; i++)
    {
        n=0;
        for (j=0; j<num_of_strings; j++)
        {
            match = strstr (strings[j], keys[i]);
            while (match != NULL)
            {
                match = strstr (match+1,keys[i]);
                n++;
            }
        }
        result[i]=n;
    }
}

int cpp_keys_in_text::get_sum()
{
    cout<<"Sum of digits is: ";
    cout<<sum<<endl;
    return sum;
}*/
