#include "Polynominal.hpp"

Coefficients *Polynominal::GetHead() const
{
    return Head;
}

int Polynominal::GetOrderOfPolynominal() const
{
    return OrderOfPolynominal;
}

Polynominal::Polynominal(int Order)
{
    if (Order >= 0)
    {
        OrderOfPolynominal = Order;
        Head = nullptr;
    }
    else
    {
        throw RangeError("Incorrect \"Order\" for polynomianl");
    }
}

void Polynominal::Set(int Order, double Coef)
{
    if (Coef == 0)
    {
        cout << "Only non-zero coefs are available" << endl;
        if (Order == GetOrderOfPolynominal())
        {
            OrderOfPolynominal -= 1;
            cout << "Order -= 1" << endl;
        }
        return;
    }
    if (Order < 0 || Order > GetOrderOfPolynominal())
    {
        throw RangeError("Incorrect \"Order\", value can't be initialized\n");
    }
    if (Head == nullptr)
    {
        Coefficients *newbie = new Coefficients;
        newbie->MyOrder = Order;
        newbie->Value = Coef;
        newbie->Next = nullptr;
        Head = newbie;
        return;
    }

    Coefficients *PointerA = GetHead();
    Coefficients *PointerB = PointerA;
    for (int i = 0; i < GetOrderOfPolynominal() + 1; i++)
    {
        if (PointerA->Next == nullptr && Order < PointerA->MyOrder) //последний эдемент
        {
            Coefficients *newbie = new Coefficients;
            newbie->MyOrder = Order;
            newbie->Value = Coef;
            newbie->Next = nullptr;

            PointerA->Next = newbie;
            return;
        }
        else if (PointerA->MyOrder == Order) // просто изменить значение
        {
            PointerA->Value = Coef;
            return;
        }
        else if (PointerA->MyOrder < Order) // добавить между
        {
            Coefficients *newbie = new Coefficients;
            newbie->MyOrder = Order;
            newbie->Value = Coef;

            newbie->Next = PointerA;
            PointerB->Next = newbie;
            return;
        }
        PointerB = PointerA;
        PointerA = PointerA->Next;
    }
}

double Polynominal::operator[](int Order)
{
    if (Order < 0 || Order > OrderOfPolynominal)
    {
        throw RangeError("Incorrect \"Order\", value can't be found\n");
    }

    Coefficients *Pointer = GetHead();

    for (int i = 0; i <= GetOrderOfPolynominal(); i++)
    {
        if (Pointer->MyOrder == Order)
            return Pointer->Value;
        Pointer = Pointer->Next;
    }
    throw RangeError("Order has no coef\n");
}

Polynominal Polynominal::operator+(const Polynominal &other)
{
    int Length = 0;
    int Maximum = 0;
    this->GetOrderOfPolynominal() > other.GetOrderOfPolynominal() ? Length = other.GetOrderOfPolynominal() : Length = this->GetOrderOfPolynominal();

    this->GetOrderOfPolynominal() < other.GetOrderOfPolynominal() ? Maximum = other.GetOrderOfPolynominal() : Maximum = this->GetOrderOfPolynominal();

    Polynominal Result(Length);

    Coefficients *PointerA = this->GetHead();
    Coefficients *PointerB = other.GetHead();

    for (int i = 0; i < Length + 1; i++)
    {
        for (int j = 0; j <= Maximum + 1; j++)
        {
            if (PointerA->MyOrder == PointerB->MyOrder)
            {
                Result.Set(PointerA->MyOrder, (PointerA->Value + PointerB->Value));
                break;
            }
            PointerB = PointerB->Next;
        }
        PointerB = other.GetHead();
        PointerA = PointerA->Next;
    }
    return Result;
}

Polynominal Polynominal::operator-(const Polynominal &other)
{
    int Length = 0;
    int Maximum = 0;
    this->GetOrderOfPolynominal() > other.GetOrderOfPolynominal() ? Length = other.GetOrderOfPolynominal() : Length = this->GetOrderOfPolynominal();

    this->GetOrderOfPolynominal() < other.GetOrderOfPolynominal() ? Maximum = other.GetOrderOfPolynominal() : Maximum = this->GetOrderOfPolynominal();

    Polynominal Result(Length);

    Coefficients *PointerA = this->GetHead();
    Coefficients *PointerB = other.GetHead();

    for (int i = 0; i < Length + 1; i++)
    {
        for (int j = 0; j <= Maximum + 1; j++)
        {
            if (PointerA->MyOrder == PointerB->MyOrder)
            {
                Result.Set(PointerA->MyOrder, (PointerA->Value - PointerB->Value));
                break;
            }
            PointerB = PointerB->Next;
        }
        PointerB = other.GetHead();
        PointerA = PointerA->Next;
    }
    return Result;
}

Polynominal Polynominal::operator*(double Val)
{
    Coefficients *Pointer = GetHead();
    Polynominal Result(Pointer->MyOrder);

    for (int i = 0; i <= GetOrderOfPolynominal(); i++)
    {
        Result.Set(Pointer->MyOrder, Pointer->Value * Val);
        Pointer = Pointer->Next;
    }
    return Result;
}

Polynominal Polynominal::Derivate()
{
    Polynominal Result((OrderOfPolynominal - 1));
    Coefficients *Pointer = GetHead();
    for (int i = 0; i < OrderOfPolynominal; i++)
    {
        Result.Set(((Pointer->MyOrder) - 1), ((Pointer->MyOrder) * (Pointer->Value)));
        Pointer = Pointer->Next;
    }
    return Result;
}

double Polynominal::CountValue(double x)
{
    Coefficients *Pointer = GetHead();
    double Ans = 0;
    for (int i = 0; i < GetOrderOfPolynominal() + 1; i++)
    {
        Ans += Pointer->Value * pow(x, Pointer->MyOrder);
        Pointer = Pointer->Next;
    }
    return Ans;
}
