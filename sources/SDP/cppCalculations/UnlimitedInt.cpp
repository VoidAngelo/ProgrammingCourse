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
    sizeOfNum = obj.getSize();
    num = new int [sizeOfNum];
    for (int i = 0; i < sizeOfNum; i++)
    {
        num[i] = obj.num[i];
    }
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
    if(this!= &num2)
    {
        delete [] num;

        sizeOfNum = num2.sizeOfNum;

        num = new int [sizeOfNum];
        for (int i = 0; i < sizeOfNum; i++)
        {
            num[i] = num2.num[i];
        }
     }

    return *this;
}

UnlimitedInt & UnlimitedInt::operator+=(UnlimitedInt &num2)
{
    int sizeOfMin;
    if(sizeOfNum<num2.sizeOfNum)
    {
        sizeOfMin=sizeOfNum;
    }
    else
    {
        sizeOfMin=num2.sizeOfNum;
    }
    for(int i = 0; i < sizeOfMin; i++)
    {
        num[sizeOfNum-1-i]+=num2[num2.sizeOfNum-1-i];
    }

    for(int i = sizeOfNum-1; i > 0; i--)
    {
        if(num[i]>=10)
        {
            int overflow=num[i]/10;
            num[i]=num[i]%10;
            num[i-1]=num[i-1]+overflow;
        }
    }
    return *this;
}

UnlimitedInt & operator+(UnlimitedInt &num1, UnlimitedInt &num2)
{
    UnlimitedInt temp = num1;
    return temp+=num2;
}

UnlimitedInt & UnlimitedInt::operator-=(UnlimitedInt &num2)
{
    int sizeOfMin;
    int trigger;
    if(sizeOfNum<num2.sizeOfNum)
    {
        trigger=1;
    }
    else if(sizeOfNum>num2.sizeOfNum)
    {
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
    if(trigger==1)
    {
        sizeOfMin=sizeOfNum;
    }
    else
    {
        sizeOfMin=num2.sizeOfNum;
    }

    for(int i = 0; i < sizeOfMin; i++)
    {
        num[sizeOfNum-1-i]-=num2[num2.sizeOfNum-1-i];
    }

    for(int i = sizeOfNum-1; i > 0; i--)
    {
        if(num[i]<0)
        {
            num[i]=num[i]+10;
            num[i-1]--;
        }
    }

    if (trigger==3)
    {
        num[0]*=-1;
    }
    return *this;
}

UnlimitedInt & operator-(UnlimitedInt &num1, UnlimitedInt &num2)
{
    UnlimitedInt temp = num1;
    return temp-=num2;
}

UnlimitedInt & UnlimitedInt::operator*=(UnlimitedInt &num2)
{
    int temp_size=sizeOfNum;
    setSize(sizeOfNum+num2.sizeOfNum-1);
    int** mult_calc = new int* [num2.sizeOfNum];
        for (int i = 0; i < sizeOfNum; i++)
            mult_calc[i] = new int [sizeOfNum];

    int k=0;
    int l=sizeOfNum-1;
    for(int i = num2.sizeOfNum-1; i >= 0; i--)
    {
        l=sizeOfNum-1;
        for(int j = temp_size; j >= 0; j--)
        {
            mult_calc[k][l-k] = num2.num[i]*num[j];
            l--;
        }
        k++;
    }

    for(int i = 0; i < num2.sizeOfNum; i++)
    {
        for(int j = sizeOfNum-1; j > num2.sizeOfNum-1-i; j--)
        {
            if(mult_calc[i][j]>=10)
            {
                int overflow=mult_calc[i][j]/10;
                mult_calc[i][j]=mult_calc[i][j]%10;
                mult_calc[i][j-1]=mult_calc[i][j-1]+overflow;
            }
        }
    }

    for(int j = sizeOfNum-1; j >= 0; j--)
    {
        int sum_temp=0;
        for(int i = 0; i < num2.sizeOfNum; i++)
        {
            sum_temp=sum_temp+mult_calc[i][j];
        }
        num[j]=sum_temp;
    }

    for (int i=0; i<num2.sizeOfNum; i++)
    {
        delete [] mult_calc[i];
    }
    delete [] mult_calc;

    for(int i = sizeOfNum-1; i > 0; i--)
    {
        if(num[i]>=10)
        {
            int overflow=num[i]/10;
            num[i]=num[i]%10;
            num[i-1]=num[i-1]+overflow;
        }
    }

    return *this;
}

UnlimitedInt & operator*(UnlimitedInt &num1, UnlimitedInt &num2)
{
    UnlimitedInt temp = num1;
    return temp-=num2;
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



