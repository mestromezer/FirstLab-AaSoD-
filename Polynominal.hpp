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

public:

	int GetOrderOfPolynominal();

	Polynominal(int Order);

	void SetCoefs(double* Coefs);

	void Set(int Order, double Coef);

	double operator [] (int Power);
};
