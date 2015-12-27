#ifndef CPP_KEYS_IN_TEXT
#define CPP_KEYS_IN_TEXT

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

class KeysInText
{
private:
    vector<string> strings;
    vector<int> result;

public:
    KeysInText(vector<string> &);
    ~KeysInText();
    vector<int> & findKeys(vector<string> &);
};


#endif // CPP_KEYS_IN_TEXT

