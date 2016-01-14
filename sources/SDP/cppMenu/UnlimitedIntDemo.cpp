#include "UnlimitedIntDemo.h"

void UnlimitedIntDemo::demo()
{
    inputNums();
    checkSum();
    checkSubt();
    checkMult();
    checkToInt();
}

void UnlimitedIntDemo::inputNums()
{
    string s1, s2;
    cout<< "Input 1st number"<< endl;
    cin>>s1;
    int size1=s1.length();
    num1.setSize(size1);
    for(unsigned int i=0; i<s1.length(); i++)
    {
        char c = s1[i];
        if ((c>='0') && (c<='9'))
        {
            int n = c - '0';
            num1[i]=n;
        }
    }
    cout<< "Input 2nd number"<< endl;
    cin>>s2;
    int size2=s1.length();
    num2.setSize(size2);
    for(unsigned int i=0; i<s1.length(); i++)
    {
        char c = s2[i];
        if ((c>='0') && (c<='9'))
        {
            int n = c - '0';
            num2[i]=n;
        }
    }
}

void UnlimitedIntDemo::checkSum()
{
    UnlimitedInt sum;
    //sum=num1+num2;
    cout<<num1<<"+"<<num2<<"="<<sum;
    cout << endl;
}

void UnlimitedIntDemo::checkSubt()
{
    UnlimitedInt subt;
    //subt=num1-num2;
    cout<<num1<<"-"<<num2<<"="<<subt;
    cout << endl;
}

void UnlimitedIntDemo::checkMult()
{
    UnlimitedInt mult;
    //mult=num1*num2;
    cout<<num1<<"*"<<num2<<"="<<mult;
    cout << endl;
}

void UnlimitedIntDemo::checkToInt()
{
    cout << "Result of conversion of num1 to int is: " <<int(num1);
    cout << endl;
    cout << "Result of conversion of num2 to int is: " <<int(num2);
    cout << endl;
}
