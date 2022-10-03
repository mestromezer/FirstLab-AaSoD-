#pragma once
#include "PolynominalError.hpp"
#define STRING_SIZE 64
#define BUFFER_SIZE 15
using namespace std;

struct Сoefficients
{
	int My_Order;
	double Value;
	Сoefficients* Next;
};

class Polynominal
{
	Сoefficients* Head;

	int OrderOfPolynominal;

	void InitializeCoefs(double* Coefs);

	void RemoveElem(int Order)
	{
		if (Order < 0) throw RangeError("Степень слишком мала ( < 0)");

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
	}

public:

	Сoefficients* GetHead() const
	{
		return Head;
	}

	int GetOrderOfPolynominal()const;

	Polynominal(int Order);

	void Set(int Order, double Coef);

	double GetCoef(int Order) const;

	double operator [] (int Power);

	Polynominal operator + (const Polynominal&  other);

	Polynominal operator - (const Polynominal&  other);

	Polynominal operator * (float val);

	Polynominal Derivate();

	friend ostream& operator<<(ostream& os, const Polynominal& Obj);
};
