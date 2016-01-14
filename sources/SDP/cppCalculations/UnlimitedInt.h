#ifndef INT_UNLIM_UI_H
#define INT_UNLIM_UI_H

#include <iostream>


using namespace std;

class UnlimitedInt
{
private:
    int *num;
    int sizeOfNum;

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
    int toInt();

    friend ostream& operator<<(ostream& os, UnlimitedInt &);
};

UnlimitedInt operator+(UnlimitedInt &, UnlimitedInt &);
UnlimitedInt operator-(UnlimitedInt &, UnlimitedInt &);
UnlimitedInt operator*(UnlimitedInt &, UnlimitedInt &);

#endif // INT_UNLIM_UI_H
