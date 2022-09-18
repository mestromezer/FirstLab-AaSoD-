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

	Polynominal Derivate();
};
