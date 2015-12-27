#include "Multiples.h"
#include "Exceptions.h"

Multiples::Multiples()
{
    numbers.push_back(5);
    numbers.push_back(10);
    numbers.push_back(11);
}

Multiples::~Multiples()
{
    numbers.clear();
    multiples.clear();
}

Multiples::Multiples(vector<int> &nums)
{
    for (int i=0; i<nums.size(); i++)
    {
        if (nums[i]>999)
        {
            throw OutOfRange(nums[i]);
        }
        else
        {
            numbers.push_back(nums[i]);
        }
    }
}

vector<int> & Multiples::findMultiples()
{
    for (int i=0; i<numbers.size(); i++)
        for (int j=0; j<numbers.size(); j++)
        {
            if(i!=j && numbers[i]%numbers[j]==0)
            {
                multiples.push_back(numbers[i]*1000+numbers[j]);
            }
        }
    return multiples;
}
