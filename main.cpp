#include "Polynominal.hpp"
#include <string>
using namespace std;

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