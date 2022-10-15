#include "Polynominal.hpp"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &os, const Polynominal &Obj)
{
    if (Obj.GetOrderOfPolynominal() == -1)
    {
        cout << "Polynominal has no coefs" << endl;
    }
    Coefficients *Pointer = Obj.GetHead();
    for (int i = 0; i < Obj.GetOrderOfPolynominal() + 1 && Pointer; i++)
    {
        os << Pointer->Value << "*x^" << Pointer->MyOrder;
        if (Pointer->Next)
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

    Polynominal b(4);
    for (int i = 4; i >= 0; i--)
    {
        b.Set(i, ((i + 2) * 3));
    }

    cout << "\na[0]: " << endl;
    cout << a[0] << endl;

    cout << "\na: " << endl;
    cout << a << endl;

    cout << "\nb: " << endl;
    cout << b << endl;

    cout << "\n(a * 2): " << endl;
    cout << (a * 2) << endl;

    cout << "\na+b: " << endl;
    cout << (a + b) << endl;

    cout << "\na-b: " << endl;
    cout << a - b << endl;

    cout << "\nPrimitive (a): " << endl;
    cout << a.Primitive() << endl;

    cout << "\nCount value for x = 15" << endl;
    cout << "y = " << a.CountValue(15.0) << endl;

    return 0;
}