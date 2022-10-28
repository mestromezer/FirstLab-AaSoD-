#include "Input.hpp"

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

    Polynominal *Newbie = new Polynominal(OrderOfPolynominal);

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