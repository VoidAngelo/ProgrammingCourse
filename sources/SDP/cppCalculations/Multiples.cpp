#include "Multiples.h"
#include "Exceptions.h"

Multiples::Multiples(const vector<int> &nums)
{
    for (unsigned int i=0; i<nums.size(); i++)
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

Multiples::~Multiples()
{
    numbers.clear();
    multiples.clear();
}

vector<vector<int> > & Multiples::findMultiples()
{
    vector<int> pair;
    pair.reserve(2);
    for (unsigned int i=0; i<numbers.size(); i++)
        for (unsigned int j=0; j<numbers.size(); j++)
        {
            if(i!=j && numbers[i]%numbers[j]==0)
            {
                pair[0]=numbers[i];
                pair[1]=numbers[j];
                multiples.push_back(pair);
            }
        }
    return multiples;
}
