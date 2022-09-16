#pragma once
#include "PolynominalError.h"

struct Сoefficients
{
	double Value;
	Сoefficients* Next;
};

class Polynominal
{
	Сoefficients* Values;

	int OrderOfPolynominal;

	void InitializeCoefs(double* Coefs);

public:

	int GetOrderOfPolynominal()const;

	Polynominal(int Order);

	void Set(int Order, double Coef);

	double GetCoef(int Order) const
	{
		Сoefficients* pointer = Values;
		for (int i = 0; i < Order; i++)
		{
			pointer = pointer->Next;
		}
		return pointer->Value;
	}

	double operator [] (int Power);
};
