#ifndef UNLIMITEDINT_H
#define UNLIMITEDINT_H

#include <iostream>


using namespace std;

class UnlimitedInt
{
private:
    int*num;
    int sizeOfNum;
    int compare(int, int*) const;
    void overflow(int);

public:
    UnlimitedInt();
    UnlimitedInt(int);
    UnlimitedInt(const UnlimitedInt& obj);
    ~UnlimitedInt();
    int getSize() const;
    void setSize(int);
    UnlimitedInt & operator=(UnlimitedInt &);
    int &operator[](int) const;
    UnlimitedInt & operator+=(UnlimitedInt &);
    UnlimitedInt & operator-=(UnlimitedInt &);
    UnlimitedInt & operator*=(UnlimitedInt &);
    operator int();

    friend ostream& operator<<(ostream& os, UnlimitedInt &);
};

UnlimitedInt operator+(UnlimitedInt &, UnlimitedInt &);
UnlimitedInt operator-(UnlimitedInt &, UnlimitedInt &);
UnlimitedInt operator*(UnlimitedInt &, UnlimitedInt &);

#endif // UNLIMITEDINT_H
