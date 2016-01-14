#include "UnlimitedInt.h"
#include "iostream"

UnlimitedInt::UnlimitedInt()
{
    sizeOfNum=0;
    num=new int[1];
    num[0]=0;
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

ostream & operator<<(ostream & os, UnlimitedInt & number)
{
    for(int i = 0; i < number.sizeOfNum; i++)
    {
        cout << number.num[i];
    }
    return os;
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

int & UnlimitedInt::operator[](int j) const
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

int UnlimitedInt::compare(int sizeOfNum2, int* num2) const
{
    int trigger;
    if(sizeOfNum<sizeOfNum2)
    {
        trigger=1;
    }
    else if(sizeOfNum>sizeOfNum2)
    {
        trigger=2;
    }
    else
    {
        for(int i=0; i<sizeOfNum; i++)
        {
            if (num[i] < num2[i])
            {
                trigger=1;
            }
            else
            {
                trigger=2;
                break;
            }
        }

    }
    return trigger;
}

void UnlimitedInt::overflow(int trigger)
{
    if(trigger==1)
    {
        for(int i = sizeOfNum-1; i > 0; i--)
        {
            if(num[i]>=10)
            {
                int overflow=num[i]/10;
                num[i]=num[i]%10;
                num[i-1]=num[i-1]+overflow;
            }
        }
    }
    else
    {
        for(int i = sizeOfNum-1; i > 0; i--)
        {
            if(num[i]<0)
            {
                num[i]=num[i]+10;
                num[i-1]--;
            }
        }
    }

}

UnlimitedInt & UnlimitedInt::operator+=(UnlimitedInt &num2)
{
    int sizeOfMin;
    int trigger;
    trigger=compare(num2.sizeOfNum, num2.num);
    if(trigger==1)
    {
        sizeOfMin=sizeOfNum;
        for(int i = 0; i < sizeOfMin; i++)
        {
            num2[num2.sizeOfNum-1-i]+=num[sizeOfNum-1-i];
        }
        *this=num2;
    }
    else
    {
        sizeOfMin=num2.sizeOfNum;
        for(int i = 0; i < sizeOfMin; i++)
        {
            num[sizeOfNum-1-i]+=num2[num2.sizeOfNum-1-i];
        }
    }
    overflow(1);
    return *this;
}

UnlimitedInt operator+(UnlimitedInt &num1, UnlimitedInt &num2)
{
    UnlimitedInt temp = num1;
    return temp+=num2;
}

UnlimitedInt & UnlimitedInt::operator-=(UnlimitedInt &num2)
{
    int sizeOfMin;
    int trigger;
    trigger=compare(num2.sizeOfNum, num2.num);;
    if(trigger==1)
    {
        sizeOfMin=sizeOfNum;
        for(int i = 0; i < sizeOfMin; i++)
        {
            num2[num2.sizeOfNum-1-i]-=num[sizeOfNum-1-i];
        }
        *this=num2;
    }
    else
    {
        sizeOfMin=num2.sizeOfNum;
        for(int i = 0; i < sizeOfMin; i++)
        {
            num[sizeOfNum-1-i]-=num2[num2.sizeOfNum-1-i];
        }
    }
    overflow(2);
    if (trigger==1)
    {
        num[0]*=-1;
    }
    return *this;
}

UnlimitedInt operator-(UnlimitedInt &num1, UnlimitedInt &num2)
{
    UnlimitedInt temp = num1;
    return temp-=num2;
}

UnlimitedInt & UnlimitedInt::operator*=(UnlimitedInt &num2)
{
    UnlimitedInt temp(sizeOfNum+num2.sizeOfNum-1);
    int** mult_calc = new int* [num2.sizeOfNum];
    for (int i = 0; i < sizeOfNum; i++)
    {
        mult_calc[i] = new int [temp.sizeOfNum];
    }

    for(int i = 0; i < num2.sizeOfNum; i++)
    {
        for(int j = 0; j < temp.sizeOfNum; j++)
        {
            mult_calc[i][j]=0;
        }
    }

    int k=0;
    for(int i = num2.sizeOfNum-1; i >= 0; i--)
    {
        int l=temp.sizeOfNum-1;
        for(int j = sizeOfNum-1; j >= 0; j--)
        {
            mult_calc[k][l-k] = num2.num[i]*num[j];
            l--;
        }
        k++;
    }

    for(int i = 0; i < num2.sizeOfNum; i++)
    {
        for(int j = temp.sizeOfNum-1; j > num2.sizeOfNum-1-i; j--)
        {
            if(mult_calc[i][j]>=10)
            {
                int overflow=mult_calc[i][j]/10;
                mult_calc[i][j]=mult_calc[i][j]%10;
                mult_calc[i][j-1]=mult_calc[i][j-1]+overflow;
            }
        }
    }

    *this=temp;

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

    overflow(1);
    return *this;
}

UnlimitedInt operator*(UnlimitedInt &num1, UnlimitedInt &num2)
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



