#include "Polynominal.hpp"
#include <string>
using namespace std;

void Print(const Polynominal& obj)
{
    int l = obj.GetOrderOfPolynominal();
    for(int i = 0; i < l; i++)
    {
        cout << "+" << obj.GetCoef(i) << "*X^" << i;
    }    
}

void main()
{
    Polynominal a(5);
    for(int i = 0; i < 5; i++) a.Set(i,i*3);

    Polynominal b(7);
    for(int i = 0; i < 7; i++) a.Set(i,i*2);

    Print(a);
    cout<< '\n' << endl;

    Print(b);
    cout<< '\n' << endl;
}