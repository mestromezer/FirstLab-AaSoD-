#pragma once
#include <iostream>
#include "PolynominalError.hpp"
using namespace std;

struct Сoefficients
{
    int My_Order;
    double Value;
    Сoefficients *Next;
};

class Polynominal
{
    Сoefficients *Head;

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
    Сoefficients *GetHead() const
    {
        return Head;
    }

    int GetOrderOfPolynominal() const
    {
        return OrderOfPolynominal;
    }

    Polynominal(int Order)
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

    void Set(int Order, double Coef)
    {
        if (Coef == 0)
        {
            cout << "Only non-zero coefs are available" << endl;
            return;
        }
        if (Order < 0 || Order > GetOrderOfPolynominal())
        {
            throw RangeError("Incorrect \"Order\", value can't be initialized\n");
        }
        if (Head == NULL)
        {
            Сoefficients *newbie = new Сoefficients;
            newbie->My_Order = Order;
            newbie->Value = Coef;
            newbie->Next = nullptr;
            Head = newbie;
            return;
        }

        Сoefficients *PointerA = GetHead();
        Сoefficients *PointerB = PointerA;
        for (int i = 0; i < GetOrderOfPolynominal() + 1; i++)
        {
            if (PointerA->Next == nullptr && Order < PointerA->My_Order) //последний эдемент
            {
                Сoefficients *newbie = new Сoefficients;
                newbie->My_Order = Order;
                newbie->Value = Coef;
                newbie->Next = nullptr;

                PointerA->Next = newbie;
                return;
            }
            else if (PointerA->My_Order == Order) // просто изменить значение
            {
                PointerA->Value = Coef;
                return;
            }
            else if (PointerA->My_Order < Order) // добавить между
            {
                Сoefficients *newbie = new Сoefficients;
                newbie->My_Order = Order;
                newbie->Value = Coef;

                newbie->Next = PointerA;
                PointerB->Next = newbie;
                return;
            }
            PointerB = PointerA;
            PointerA = PointerA->Next;
        }
    }

    double GetCoef(int Order) const;

    double operator[](int Order)
    {
        if (Order < 0 || Order > OrderOfPolynominal)
        {
            throw RangeError("Incorrect \"Order\", value can't be found\n");
        }

        Сoefficients *Pointer = GetHead();

        for (int i = 0; i <= GetOrderOfPolynominal(); i++)
        {
            if (Pointer->My_Order == Order)
                return Pointer->Value;
            Pointer = Pointer->Next;
        }
        throw RangeError("Order has no coef\n");
    }

    Polynominal operator+(const Polynominal &other);

    Polynominal operator-(const Polynominal &other);

    Polynominal operator*(float val);

    Polynominal Derivate();

    friend ostream &operator<<(ostream &os, const Polynominal &Obj);
};
