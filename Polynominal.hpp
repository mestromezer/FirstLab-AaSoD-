#pragma once
#include "PolynominalError.h"
#define STRING_SIZE 64
#define BUFFER_SIZE 15

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

	ostream& operator<<(ostream& os) {
		char String[STRING_SIZE]{ '\0' };
		for (int i = 0; i < OrderOfPolynominal; i++)
		{
			char Buffer[BUFFER_SIZE]{ '\0' };
			sprintf(Buffer, "%f*(X^%d)", GetCoef(i), i);
			strcat(String, Buffer);
			strcat(String, " + ");
			free(Buffer);
		}
		return os << String << endl;
	}

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

	int GetOrderOfPolynominal()const;

	Polynominal(int Order);

	void Set(int Order, double Coef);

	double GetCoef(int Order) const;

	double operator [] (int Power);

	Polynominal operator + (const Polynominal&  other);

	Polynominal operator - (const Polynominal&  other);

	Polynominal operator * (float val);

	Polynominal Derivate();
};
