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
    void showNum() const;
    int getSize() const;
    void setSize(int);
    UnlimitedInt & operator=(UnlimitedInt &);
    int &operator[](int);
    UnlimitedInt & operator+=(UnlimitedInt &);
    UnlimitedInt & operator-=(UnlimitedInt &);
    UnlimitedInt & operator*=(UnlimitedInt &);
    int toInt();
};

UnlimitedInt & operator+(UnlimitedInt &, UnlimitedInt &);
UnlimitedInt & operator-(UnlimitedInt &, UnlimitedInt &);
UnlimitedInt & operator*(UnlimitedInt &, UnlimitedInt &);

#endif // INT_UNLIM_UI_H
