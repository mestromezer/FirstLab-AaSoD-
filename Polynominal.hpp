#pragma once
#include <iostream>
#include <math.h>
#include "PolynominalError.hpp"
using namespace std;

struct Coefficients
{
    int MyOrder;
    double Value;
    Coefficients *Next;
};

class Polynominal
{
    Coefficients *Head;

    int OrderOfPolynominal;

public:
    Coefficients *GetHead() const;

    int GetOrderOfPolynominal() const;

    Polynominal(int Order);

    void Set(int Order, double Coef);

    double operator[](int Order) const;

    Polynominal operator+(const Polynominal &Other);

    Polynominal operator-(const Polynominal &Other);

    Polynominal operator*(double Val);

    // Polynominal Derivate();

    Polynominal Primitive();

    double CountValue(double x);

    friend ostream &operator<<(ostream &os, const Polynominal &Obj);
};
