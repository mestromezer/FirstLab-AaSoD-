#include "Polynominal.h"

Polynominal::Polynominal(int Power, double* Coefs, int Size)
{
	BeginnigWith = Power;
	Lenght = Size;
	SetCoefs(Coefs);
}

void Polynominal::SetCoefs(double* Coefs)
{
	Values = new Сoefficients;
	Сoefficients* pointer = Values;

	for (int i = 0; i < Lenght; i++) // range
	{
		pointer->Value = Coefs[i];
		pointer->Next = new Сoefficients;
		pointer = pointer->Next;
	}
	pointer->Next = nullptr;
}

void Polynominal::set(int Power, double Coef)
{
	Сoefficients* Pointer = Values;

	for (int i = 0; i < Lenght; i++)
	{
		Pointer = Pointer->Next;
		if (i == Power + BeginnigWith) Pointer[i].Value = Coef;
	}
}

double Polynominal::operator [] (int Power)
{
	Сoefficients* Pointer = Values;

	for (int i = 0; i < Lenght; i++)
	{
		if (i == Power + BeginnigWith) return Values[i].Value;
	}
	throw "Polynominal's last member is in lower power";
}
