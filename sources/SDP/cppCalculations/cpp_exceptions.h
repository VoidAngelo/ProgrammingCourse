#ifndef CPP_EXCEPTIONS
#define CPP_EXCEPTIONS

#include"cpp_multiples.h"

class OutOfRange : public std::exception {
public:
    OutOfRange(const int num) : num(num) {}
    int getCurrentNumber() const {return num;}
private:
    int num;
};

#endif // CPP_EXCEPTIONS

