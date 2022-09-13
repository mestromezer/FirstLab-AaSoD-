#pragma once

struct Сoefficients
{
	double Value;
	Сoefficients* Next;
};

class Polynominal
{
	Сoefficients* Values;
	int Lenght;

	int BeginnigWith;

public:

	Polynominal(int Power, double* Coefs, int Size);

	void SetCoefs(double* Coefs);

	void set(int Power, double Coef);

	double operator [] (int Power);
};
