#include "Polynominal.hpp"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &os, const Polynominal &Obj)
{
    Сoefficients *Pointer = Obj.GetHead();
    for (int i = 0; i < Obj.GetOrderOfPolynominal() + 1; i++)
    {
        os << Pointer->Value << "*x^" << Pointer->My_Order;
        if (i != Obj.GetOrderOfPolynominal())
            os << " + ";
        Pointer = Pointer->Next;
    }
    return os;
}

int main()
{
    Polynominal a(2);
    for (int i = 2; i >= 0; i--)
    {
        a.Set(i, (i + 1) * 3);
    }
    cout << a[0] << endl;
    cout << "a[1]" << endl;

    cout << a << endl;

    return 0;
}