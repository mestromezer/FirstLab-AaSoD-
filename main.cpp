#include <iostream>
#include "Polynominal.hpp"
#include "Input.hpp"

using namespace std;

void GiveAnX(const Polynominal *Object)
{
    double Y = 0;
    double X = InputValue();

    for (int i = Object->GetOrderOfPolynominal(); i >= 0; i--)
    {
        Y += (*Object)[i] * pow(X, i);
    }

    cout << "Value for polynom (x = " << X << "): " << Y << endl;
}

void Sum(const Polynominal *Object)
{
    system("clear");

    cout << "Firstly input another polynom" << endl;
    cout << "Any key to input another polynom" << endl;

    getch();

    system("clear");

    const Polynominal *Another = MenuInput();

    system("clear");

    cout << "Sum of two polynominals:" << endl;
    cout << "\n\nFirst: " << (*Object) << endl;
    cout << "\nSecond: " << (*Another) << endl;
    cout << "\nTheir sum: " << ((*Object) + (*Another)) << endl;

    delete Another;
}

void Substract(const Polynominal *Object)
{
    system("clear");

    cout << "Substract menu\n"
         << endl;

    cout << "Firstly input another polynom" << endl;
    cout << "Any key to input another polynom" << endl;

    getch();

    system("clear");

    const Polynominal *Another = MenuInput();

    system("clear");

    cout << "Substract menu\n"
         << endl;

    cout << "Sum of two polynominals:" << endl;
    cout << "First: " << (*Object) << endl;
    cout << "Second: " << (*Another) << endl;
    cout << "Their substruction result: " << ((*Object) - (*Another)) << endl;

    delete Another;
}

void MultiplyByArg(const Polynominal *Object)
{
    cout << "Multiply by arg menu\n"
         << endl;
    int Arg = InputValue();

    system("clear");

    cout << "Multiply by arg menu\n"
         << endl;

    cout << "(" << (*Object) << ")"
         << " * " << Arg << " :" << endl;
    cout << (*Object) * Arg << endl;
}

void GetCoefByIndex(const Polynominal *Object)
{
    system("clear");

    cout << "Get coefficient by index menu\n"
         << endl;
    cout << (*Object) << endl;
    cout << "Input index: ";
    int Index = 0;
    cin >> Index;
    cout << "Value: " << (*Object)[Index] << endl;
}

void GetPremitiveFucntion(const Polynominal *Object)
{
    system("clear");

    cout << "Get Premitive funtion menu\n"
         << endl;
    cout << "For : " << (*Object) << endl;
    cout << "Primitive function equals: " << (*Object).Primitive() << endl;
}

int MenuChoice()
{
    cout << "\n\t[1] - Give an X" << endl;
    cout << "\n\t[2] - Sum" << endl;
    cout << "\n\t[3] - Substract" << endl;
    cout << "\n\t[4] - Multiply by arg" << endl;
    cout << "\n\t[5] - Get coefficinent by index" << endl;
    cout << "\n\t[6] - Get premitive fucntion" << endl;
    cout << "\n\t[BACKSPACE] - Set new polynoms" << endl;
    cout << "\n\n\tEsc - Exit" << endl;
    while (true)
    {
        int key = getch();
        if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 127) || (key == 27))
        {
            return key;
        }
    }
}

int main()
{
    while (true)
    {
        system("clear");

        Polynominal *Object = nullptr;

        Object = MenuInput();

        while (Object)
        {
            system("clear");

            cout << "Your polymon: " << *Object << endl;
            int Choice = MenuChoice();

            switch (Choice)
            {
            case 49: // Give an X
                GiveAnX(Object);
                break;
            case 50: // Sum

                Sum(Object);
                break;
            case 51: // Substract
                Substract(Object);
                break;
            case 52: // Multiply by arg
                MultiplyByArg(Object);
                break;
            case 53: // Get doef by index
                GetCoefByIndex(Object);
                break;
            case 54: // Get premitive fucntion
                GetPremitiveFucntion(Object);
                break;
            case 127: // Set new polynoms
                delete Object;
                Object = nullptr;
                break;
            case 27: // Exit
                system("clear");
                cout << "Word is done" << endl;
                return EXIT_SUCCESS;
                break;
            default:
                break;
            }

            cout << "Press any key" << endl;
            getch();
        }
    }
}