#include "Polynominal.h"

int Polynominal::GetOrderOfPolynominal()
{
	return OrderOfPolynominal;
}

Polynominal::Polynominal(int Order)
{
	OrderOfPolynominal = Order;
	Values = nullptr;
}

void Polynominal::SetCoefs(double* Coefs)
{
	Values = new Сoefficients;
	Сoefficients* pointer = Values;

	for (int i = 0; i < OrderOfPolynominal; i++) // range
	{
		if (pointer == nullptr) throw SearchError("Invalid order");
		pointer->Value = Coefs[i];
		pointer->Next = new Сoefficients;
		pointer = pointer->Next;
	}
	pointer->Next = nullptr;
}

void Polynominal::Set(int Order, double Coef)
{
	Сoefficients* Pointer = Values;

	for (int i = 0; i < OrderOfPolynominal; i++)
	{
		Pointer = Pointer->Next;
		if (i == Order) Pointer[i].Value = Coef;
	}
}

double Polynominal::operator [] (int Order)
{
	Сoefficients* Pointer = Values;

	for (int i = 0; i < OrderOfPolynominal; i++)
	{
		if (i == Order) return Values[i].Value;
	}
	throw SearchError("Invalid order");
}
