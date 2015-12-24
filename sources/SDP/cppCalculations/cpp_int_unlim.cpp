#include "cpp_int_unlim.h"

cpp_int_unlim::cpp_int_unlim()
{
    num1.push_back(0);
    num2.push_back(0);
}

cpp_int_unlim::cpp_int_unlim(vector<int> iu_num1, vector<int> iu_num2)
{
    enter_numbers(iu_num1, iu_num2);
}

cpp_int_unlim::cpp_int_unlim(const cpp_int_unlim& obj)
{
    num1=obj.num1;
    num2=obj.num2;
}

cpp_int_unlim::~cpp_int_unlim()
{
    num1.clear();
    num2.clear();
    min_num.clear();
    max_num.clear();
    sum.clear();
    subt.clear();
    mult.clear();
}

void cpp_int_unlim::enter_numbers(vector<int> iu_num1, vector<int> iu_num2)
{
    num1=iu_num1;
    num2=iu_num2;
}

void cpp_int_unlim::basic_calculations()
{
    size_of_num1=num1.size();
    size_of_num2=num2.size();
    trigger=0;
    if (size_of_num1>size_of_num2)
    {
        size_of_result=size_of_num1;
        min_num=num2;
        max_num=num1;
    }
    else if(size_of_num1<size_of_num2)
    {
        size_of_result=size_of_num2;
        min_num=num1;
        max_num=num2;
        trigger++;
    }
    else
    {
        size_of_result=size_of_num1;
        min_num=num2;
        max_num=num1;
        for (int i=0; i<size_of_num1; i++)
        {
            if (min_num[i]<max_num[i])
            {
                break;
            }
            else if (min_num[i]>max_num[i])
            {
                min_num=num1;
                max_num=num2;
                trigger++;
                break;
            }
        }
    }
    size_of_min=min_num.size();
    size_of_max=max_num.size();
    for(int i = 0; i < size_of_max-size_of_min; i++)
    {
       min_num.insert(min_num.begin(), 0);
    }
    cout<<endl;
}

void cpp_int_unlim::sum_of_iu()
{
    int digit, overflow;
    for(int i = 0; i < size_of_result; i++)
    {
        digit=max_num[i]+min_num[i];
        sum.insert(sum.end(), digit);
    }

    for(int i = size_of_result-1; i > 0; i--)
    {
        if(sum[i]>=10)
        {
            overflow=sum[i]/10;
            sum[i]=sum[i]%10;
            sum[i-1]=sum[i-1]+overflow;
        }
    }
    cout<<endl;
}

int cpp_int_unlim::get_sum()
{
    cout <<"Result of sum is: ";
    copy(
            sum.begin(),
            sum.end(),
            ostream_iterator<int>(cout)
        );
    cout<<endl;

    test=0;
    for (unsigned int i=0; i<sum.size(); i++)
    {
        test=test*10+sum[i];
    }
    return test;
}

void cpp_int_unlim::subtraction_of_iu()
{
    int digit, overflow;
    for(int i = 0; i < size_of_result; i++)
    {
        int temp;
        temp=max_num[i];
        if(max_num[i]<min_num[i])
        {
            temp=temp+20;
        }
        digit=temp-min_num[i];
        if(digit==0)
        {
            digit=20;
        }
        subt.insert(subt.end(), digit);
    }

    if(subt[size_of_result-1]==20)
    {
        subt[size_of_result-1]=0;
    }

    for(unsigned int i = 0; i < subt.size(); i++)
    {
        if (subt[i]!=20)
        {
            break;
        }
        if (subt[i]==20)
        {
            subt[i]=0;
        }
    }

    for(int i = size_of_result-1; i > 0; i--)
    {
        if(subt[i]>=10)
        {
            overflow=subt[i]/10;
            subt[i]=subt[i]%10;
            subt[i-1]=subt[i-1]-overflow;
        }
    }
    cout<<endl;
}

int cpp_int_unlim::get_subtraction()
{
    cout <<"Result of subtraction is: ";
    if(trigger!=0)
    {
        cout<<"-";
    }
    copy(
            subt.begin(),
            subt.end(),
            ostream_iterator<int>(cout)
        );
    cout<<endl;

    test=0;
    for (unsigned int i=0; i<subt.size(); i++)
    {
        test=test*10+subt[i];
    }
    return test;
}

void cpp_int_unlim::multiplication_of_iu()
{
    int digit, overflow;

    size_of_result=size_of_min+size_of_max-1;

    vector<vector<int> > mult_calc(size_of_min, vector<int>(size_of_result, 0));
    int k=0;
    int l=size_of_result-1;
    for(int i = size_of_max-1; i >= size_of_max-size_of_min; i--)
    {
        l=size_of_result-1;
        for(int j = size_of_max-1; j >= 0; j--)
        {
            digit=min_num[i]*max_num[j];
            mult_calc[k][l-k] = digit;
            l--;
        }
        k++;
    }

    for(int i = 0; i < size_of_min; i++)
    {
        for(int j = size_of_result-1; j > size_of_min-1-i; j--)
        {
            if(mult_calc[i][j]>=10)
            {
                overflow=mult_calc[i][j]/10;
                mult_calc[i][j]=mult_calc[i][j]%10;
                mult_calc[i][j-1]=mult_calc[i][j-1]+overflow;
            }
        }
    }

    for(int j = size_of_result-1; j >= 0; j--)
    {
        int sum_temp=0;
        for(int i = 0; i < size_of_min; i++)
        {
            sum_temp=sum_temp+mult_calc[i][j];
        }
        mult.insert(mult.begin(), sum_temp);
    }

    for(int i = size_of_result-1; i > 0; i--)
    {
        if(mult[i]>=10)
        {
            overflow=mult[i]/10;
            mult[i]=mult[i]%10;
            mult[i-1]=mult[i-1]+overflow;
        }
    }
}

int cpp_int_unlim::get_multiplication()
{
    cout <<"Result of multiplication is: ";
    copy(
            mult.begin(),
            mult.end(),
            ostream_iterator<int>(cout)
        );
    cout<<endl;
    test=0;
    for (unsigned int i=0; i<mult.size(); i++)
    {
        test=test*10+mult[i];
    }
    return test;
}

void cpp_int_unlim::iu_to_i()
{
    num1_to_i=0;
    for (unsigned int i=0; i<num1.size(); i++)
    {
        trigger++;
        num1_to_i=num1_to_i*10+num1[i];
        if(i>=5)
        {
            trigger=2;
            break;
        }
    }
    num2_to_i=0;
    for (unsigned int i=0; i<num2.size(); i++)
    {
        num2_to_i=num2_to_i*10+num2[i];
        if(i>=5)
        {
            trigger=3;
            break;
        }
    }
    cout<<endl;
}

void cpp_int_unlim::get_int()
{
    cout <<"Result of translation num1 to int is: ";
    cout<<num1_to_i<<endl;
    if(trigger==2)
    {
        cout <<"Num1 is more then integer. Result is 31 first digits of int_unlim";
    }
    cout <<"Result of translation num2 to int is: ";
    cout<<num2_to_i<<endl;
    if(trigger==3)
    {
        cout <<"Num2 is more then integer. Result is 31 first digits of int_unlim";
    }
    cout<<endl;
}



