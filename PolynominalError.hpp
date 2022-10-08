#pragma once
#include <iostream>

using namespace std;

class PolynominalError : public exception
{
protected:
    const char *Message;

    PolynominalError();

    void SetMessage(const char *Message);

    void PrintInfo() const;
};

class MemoryError : PolynominalError
{
public:
    MemoryError(const char *Message);
};

class RangeError : PolynominalError
{
public:
    RangeError(const char *Message);
};