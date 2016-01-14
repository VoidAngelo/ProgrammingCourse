#ifndef CPP_MULTIPLES_SEARCH
#define CPP_MULTIPLES_SEARCH

#include <iostream>
#include <vector>

using namespace std;

class Multiples
{
private:
    vector<int> numbers;
    vector<vector<int> > multiples;

public:
    Multiples(const vector<int> &);
    ~Multiples();
    vector<vector<int> > & findMultiples();
};

#endif // CPP_MULTIPLES_SEARCH

