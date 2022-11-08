#pragma once
#include <iostream>
#include <math.h>
#include "PolynominalError.hpp"
using namespace std;

struct Coefficients
{
    long long MyOrder;
    double Value;
    Coefficients *Next;
};

class Polynominal
{
    Coefficients *Head;

    long long OrderOfPolynominal;

public:
    Coefficients *GetHead() const;

    long long GetOrderOfPolynominal() const;

    Polynominal(long long Order);

    ~Polynominal();

    void Set(long long Order, double Coef);

    double operator[](long long Order) const;

    Polynominal operator+(const Polynominal &Other) const;

    Polynominal operator-(const Polynominal &Other) const;

    Polynominal operator*(double Val) const;

    // Polynominal Derivate();

    Polynominal Primitive() const;

    double CountValue(double x) const;

    friend ostream &operator<<(ostream &os, const Polynominal &Obj);
};
