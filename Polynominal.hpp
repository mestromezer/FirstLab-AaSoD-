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

	double GetCoef(int Order) const;

	double operator [] (int Power);

	Polynominal operator + (const Polynominal&  other);

	Polynominal operator - (const Polynominal&  other);

	Polynominal operator * (float val);

	Polynominal Derivate()
	{
		int l = GetOrderOfPolynominal() - 1;

		Polynominal* newbie = new Polynominal(l);
		
		for(int current = 0; current < l; current++)
		{
			newbie->Set(current, current * GetCoef(current+1));
		}

		return (*newbie);
	}
};
