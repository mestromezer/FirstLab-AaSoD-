#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "Polynominal.hpp"
using namespace std;

char getch(void)
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}

Polynominal *MenuInput()
{
    cout << "Create poilynominal menu\n\n"
         << endl;

    cout << "Order of polynominal: " << endl;
    long long OrderOfPolynominal = 0;
    cin >> OrderOfPolynominal;

    Polynominal *Newbie = NULL;
    try
    {
        Newbie = new Polynominal(OrderOfPolynominal);
    }
    catch (exception e)
    {
        clog << "An exception occured" << endl;
    }

    for (long long i = OrderOfPolynominal; i >= 0; i--)
    {
        cout << "Coef by " << i << ":\n";
        double Coefficient = 0;
        cin >> Coefficient;
        Newbie->Set(i, Coefficient);
        cout << endl;
    }

    cout << "Created polynominal: " << *Newbie << endl;
    cout << "Press any key" << endl;
    getch();

    return Newbie;
}

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

double InputValue()
{
    cout << "Give a value: " << endl;
    double X = 0;
    cin >> X;
    return X;
}

void GiveAnX(const Polynominal *Object)
{
    double X = InputValue();

    double Y = Object->CountValue(X);

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

        cout << "Hellow, world!" << endl;
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