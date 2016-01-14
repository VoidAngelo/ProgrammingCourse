#include "KeysInText.h"


KeysInText::KeysInText(vector<string> &istrings)
{
    for (unsigned int i=0; i<istrings.size(); i++)
    {
        strings.push_back(istrings[i]);
    }
}

KeysInText::~KeysInText()
{
    strings.clear();
}

vector<int> & KeysInText::findKeys(vector<string> &keys)
{
    int n;
    char * match;
    for (unsigned int i=0; i<keys.size(); i++)
    {
        n=0;

        char * ckey = new char [keys[i].length()+1];
        strcpy (ckey, keys[i].c_str());

        for (unsigned int j=0; j<strings.size(); j++)
        {
            char * cstring = new char [strings[j].length()+1];
            strcpy (cstring, strings[j].c_str());

            match = strstr (cstring, ckey);
            while (match != NULL)
            {
                match = strstr (match+1,ckey);
                n++;
            }
            delete[] cstring;
        }
        delete[] ckey;
        result.push_back(n);
    }
    return result;
}
