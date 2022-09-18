#include "Polynominal.hpp"

int Polynominal::GetOrderOfPolynominal() const
{
	return OrderOfPolynominal;
}

Polynominal::Polynominal(int Order)
{
	OrderOfPolynominal = Order;
	double* c = new double[Order] {0};
	InitializeCoefs(c);
}

void Polynominal::InitializeCoefs(double* Coefs)
{
	Values = new Сoefficients;
	Сoefficients* pointer = Values;

	for (int i = 0; i < OrderOfPolynominal; i++) // range
	{
		if (pointer == nullptr) throw SearchError("Invalid order");
		pointer->Value = ++Coefs[i];
		pointer->Next = new Сoefficients;
		pointer = pointer->Next;
	}
	pointer->Next = nullptr;
}

void Polynominal::Set(int Order, double Coef)
{
	if(Order < 0) throw RangeError("Степень слишком мала ( < 0)");

	Сoefficients* Pointer = Values;

	for (int i = 0; i < OrderOfPolynominal; i++)
	{
		Pointer = Pointer->Next;
		if (i == Order) Pointer[i].Value = Coef;
	}
}

double Polynominal::GetCoef(int Order) const
{
	Сoefficients* pointer = Values;
	for (int i = 0; i < Order; i++)
	{
		pointer = pointer->Next;
	}
	return pointer->Value;
}

double Polynominal::operator [] (int Order)
{
	if(Order < 0) throw RangeError("Степень слишком мала ( < 0)");
	Сoefficients* Pointer = Values;

	for (int i = 0; i < OrderOfPolynominal; i++)
	{
		if (i == Order) return Values[i].Value;
	}
	throw SearchError("Invalid order");
}

Polynominal Polynominal::operator + (const Polynominal&  other)
{
	int l = 0;
	other.GetOrderOfPolynominal() < this->GetOrderOfPolynominal()? l = other.GetOrderOfPolynominal() : l = this->GetOrderOfPolynominal();

	Polynominal* newbie = new Polynominal(l);

	for(int i = 0; i < l; i++)
	{
		newbie->Set(i,this->GetCoef(i) + other.GetCoef(i));
	}

	return (*newbie);
}

Polynominal Polynominal::operator - (const Polynominal&  other)
{
	int l = 0;
	other.GetOrderOfPolynominal() < this->GetOrderOfPolynominal()? l = other.GetOrderOfPolynominal() : l = this->GetOrderOfPolynominal();

	Polynominal* newbie = new Polynominal(l);

	for(int current = 0; current < l; current++)
	{
		newbie->Set(current,this->GetCoef(current) - other.GetCoef(current));
	}

	return (*newbie);
}

Polynominal Polynominal::operator * (float val)
{
	int l = GetOrderOfPolynominal();
	Polynominal* newbie = new Polynominal(l);

	for(int current =0; current < l;current++) newbie->Set(current, this->GetCoef(current) * val);
	
	return (*newbie);
}
