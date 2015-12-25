#ifndef UNLIMITEDINTAPP
#define UNLIMITEDINTAPP

#include "iostream"
#include "UnlimitedInt.h"

using std::cout;
using std::cin;
using std::endl;
using std::terminate;
using std::ostream;
using std::istream;

class UnlimitedIntApp
{
private:
    UnlimitedInt * num;
public:
    UnlimitedIntApp(int size = 10);
    void setSize(int);
    ~UnlimitedIntApp();
};

#endif // UNLIMITEDINTAPP

