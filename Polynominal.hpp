#pragma once
#include <iostream>
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

    /*void RemoveElem(int Order)
    {
        //if (Order < 0) throw RangeError("Степень слишком мала ( < 0)");

        Сoefficients* ForwardPointer = Head;

        Сoefficients* BackwardPointer = Head;

        if (Order == 0)
        {
            ForwardPointer = ForwardPointer->Next;
            delete Head;
            Head = ForwardPointer;
        }
        else {
            for (int i = 0; i <= OrderOfPolynominal; i++)
            {
                if (ForwardPointer->My_Order == Order)
                {
                    Сoefficients* tmp = ForwardPointer;
                    ForwardPointer = ForwardPointer->Next;
                    delete tmp;
                    BackwardPointer->Next = ForwardPointer;
                }
                BackwardPointer = ForwardPointer;
                ForwardPointer = ForwardPointer->Next;
            }
        }
    }*/

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
