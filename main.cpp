#include "Polynominal.hpp"
#include <string>
using namespace std;

ostream& operator<<(ostream& os, const Polynominal& Obj)
{
    Ñoefficients* Pointer = Obj.GetHead();
    for (int i = 0; i < Obj.GetOrderOfPolynominal(); i++)
    {
        os << Pointer->Value << " * x^" << Pointer->My_Order << ' ';
        if (i++ != Obj.GetOrderOfPolynominal()) os << '+';
        Pointer = Pointer->Next;
    }
    return os;
}

void main()
{
    Polynominal test(2); // 2 for x^2 
    for (int i = 0; i < 4; i++) test.Set(i, i);

    cout << test << endl;

    /*
    Polynominal a(5);
    for(int i = 0; i < 7; i++) a.Set(i,i*3);

    Polynominal b(7);
    for(int i = 0; i <= 7; i++) b.Set(i,i*2);

    Print(a);
    cout<< '\n' << endl;

    Print(b);
    cout<< '\n' << endl;*/

    getchar();
}