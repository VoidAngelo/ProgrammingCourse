#include "UnlimitedInt.h"
#include "iostream"

UnlimitedInt::UnlimitedInt()
{
    sizeOfNum=0;
    num=0;
}

UnlimitedInt::UnlimitedInt(int size)
{
    sizeOfNum = size;
    num = new int [sizeOfNum];
    for(int i = 0; i < sizeOfNum; i++)
    {
        num[i] = 0;
    }
}

UnlimitedInt::UnlimitedInt(const UnlimitedInt& obj)
{
    num=obj.num;
}

UnlimitedInt::~UnlimitedInt()
{
    delete[] num;
}

void UnlimitedInt::showNum() const
{
    for(int i = 0; i < sizeOfNum; i++)
    {
        cout << num[i];
    }
}

int UnlimitedInt::getSize() const
{
    return sizeOfNum;
}

void UnlimitedInt::setSize(int size)
{
    sizeOfNum = size;
    num = new int [sizeOfNum];
    for(int i = 0; i < sizeOfNum; i++)
    {
        num[i] = 0;
    }
}

int & UnlimitedInt::operator[](int j)
    {
        return num[j];
    }

UnlimitedInt & UnlimitedInt::operator=(UnlimitedInt &num2)
{
    delete [] num;

    sizeOfNum = num2.sizeOfNum;

    num = new int [sizeOfNum];
    for (int i = 0; i < sizeOfNum; i++)
    {
        num[i] = num2.num[i];
    }

    return *this;
}

int UnlimitedInt::operator+(UnlimitedInt &num2)
{
    int sizeOfMax;
    int sizeOfMin;
    if(sizeOfNum>num2.sizeOfNum)
    {
        sizeOfMax=sizeOfNum;
        sizeOfMin=num2.sizeOfNum;
    }
    else
    {
        sizeOfMax=num2.sizeOfNum;
        sizeOfMin=sizeOfNum;
    }
    UnlimitedInt sum(sizeOfMax);
    UnlimitedInt min(sizeOfMin);
    if(sizeOfNum>=num2.sizeOfNum)
    {
        sum.num=num;
        min.num=num2.num;
    }
    else
    {
        sum.num=num2.num;
        min.num=num;
    }
    for(int i = sizeOfMin-1; i >= 0; i--)
    {
        sum.num[i+sizeOfMax-sizeOfMin]=sum.num[i+sizeOfMax-sizeOfMin]-min.num[i];
    }

    for(int i = sum.sizeOfNum-1; i > 0; i--)
    {
        if(sum.num[i]>=10)
        {
            int overflow=sum.num[i]/10;
            sum.num[i]=sum.num[i]%10;
            sum.num[i-1]=sum.num[i-1]+overflow;
        }
    }
    return *sum.num;
}

int UnlimitedInt::operator-(UnlimitedInt &num2)
{
    int sizeOfMax=sizeOfNum;
    int sizeOfMin=num2.sizeOfNum;
    int trigger;
    if(sizeOfNum>num2.sizeOfNum)
    {
        trigger=1;
    }
    else if(sizeOfNum<num2.sizeOfNum)
    {
        sizeOfMax=num2.sizeOfNum;
        sizeOfMin=sizeOfNum;
        trigger=2;
    }
    else
    {
        for(int i=0; i<sizeOfNum; i++)
        {
            if (num[i] < num2.num[i])
            {
                trigger=3;
                break;
            }
            else
            {
                trigger=1;
            }
        }

    }
    UnlimitedInt subt(sizeOfMax);
    UnlimitedInt min(sizeOfMin);
    if(trigger==1)
    {
        subt.num=num;
        min.num=num2.num;
    }
    else
    {
        subt.num=num2.num;
        min.num=num;
    }

    for(int i = sizeOfMin-1; i >= 0; i--)
    {
        subt.num[i+sizeOfMax-sizeOfMin]=subt.num[i+sizeOfMax-sizeOfMin]-min.num[i];
    }

    for(int i = subt.sizeOfNum-1; i > 0; i--)
    {
        if(subt.num[i]<0)
        {
            subt.num[i]=subt.num[i]+10;
            subt.num[i-1]--;
        }
    }

    if (trigger==3)
    {
        subt.num[0]=~subt.num[0]+1;
    }
    cout<<endl;
    return *subt.num;
}

int UnlimitedInt::operator*(UnlimitedInt &num2)
{
    int overflow;
    int sizeOfResult=sizeOfNum+num2.sizeOfNum-1;
    UnlimitedInt mult(sizeOfResult);
    int** mult_calc = new int* [num2.sizeOfNum];
        for (int i = 0; i < sizeOfNum; i++)
            mult_calc[i] = new int [sizeOfNum];

    int k=0;
    int l=sizeOfResult-1;
    for(int i = num2.sizeOfNum-1; i >= 0; i--)
    {
        l=sizeOfResult-1;
        for(int j = sizeOfNum-1; j >= 0; j--)
        {
            mult_calc[k][l-k] = num2.num[i]*num[j];
            l--;
        }
        k++;
    }

    for(int i = 0; i < num2.sizeOfNum; i++)
    {
        for(int j = sizeOfResult-1; j > num2.sizeOfNum-1-i; j--)
        {
            if(mult_calc[i][j]>=10)
            {
                overflow=mult_calc[i][j]/10;
                mult_calc[i][j]=mult_calc[i][j]%10;
                mult_calc[i][j-1]=mult_calc[i][j-1]+overflow;
            }
        }
    }

    for(int j = sizeOfResult-1; j >= 0; j--)
    {
        int sum_temp=0;
        for(int i = 0; i < num2.sizeOfNum; i++)
        {
            sum_temp=sum_temp+mult_calc[i][j];
        }
        mult.num[j]=sum_temp;
    }

    for(int i = sizeOfResult-1; i > 0; i--)
    {
        if(mult.num[i]>=10)
        {
            overflow=mult.num[i]/10;
            mult.num[i]=mult.num[i]%10;
            mult.num[i-1]=mult.num[i-1]+overflow;
        }
    }
    return *mult.num;
}

int UnlimitedInt::toInt()
{
    int num_to_i=0;
    for (int i=0; i<sizeOfNum; i++)
    {
        num_to_i=num_to_i*10+num[i];
        if(i>=5)
        {
            break;
        }
    }
    cout<<endl;
    return num_to_i;
}



