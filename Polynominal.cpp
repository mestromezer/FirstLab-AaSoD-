#include "Polynominal.hpp"
#include "PolynominalError.hpp"

int Polynominal::GetOrderOfPolynominal() const
{
	return OrderOfPolynominal;
}

Polynominal::Polynominal(int Order)
{
	OrderOfPolynominal = Order; 
	double* c = new double[Order] {0};//for zero order elem
	InitializeCoefs(c);
}

void Polynominal::InitializeCoefs(double* Coefs)
{
	Head = new Сoefficients;
	Сoefficients* pointer = Head;
	if (pointer == nullptr) throw MemoryError("No memory");

	for (int i = OrderOfPolynominal; i > 0 ; i--) // range
	{
		pointer->Value = ++Coefs[i];
		pointer->My_Order = i;
		pointer->Next = new Сoefficients;
		pointer = pointer->Next;
	}
	pointer->Next = nullptr;
}

void Polynominal::Set(int Order, double Coef)
{
	if(Order < 0) throw RangeError("Степень слишком мала ( < 0)");

	if (Coef == 0)
	{
		RemoveElem(Order);
	}
	else {

		Сoefficients* Pointer = Head;

		for (int i = 0; i < OrderOfPolynominal; i++)
		{
			if (Pointer->My_Order == Order)
			{
				if (Coef != 0)
				{
					Pointer->Value = Coef;
					break;
				}
				else throw("Coef is equal to 0\n");
				
			}
			Pointer = Pointer->Next;
		}
	}
}

double Polynominal::GetCoef(int Order) const
{
	if (Order > OrderOfPolynominal || Order < 0) throw RangeError("Неверная степень");
	Сoefficients* Pointer = Head;
	for (int i = 0; i < Order; i++)
	{
		Pointer = Pointer->Next;
	}
	return Pointer->Value;
}

double Polynominal::operator [] (int Order)
{
	if (Order > OrderOfPolynominal || Order < 0) throw RangeError("Неверная степень");
	Сoefficients* Pointer = Head;

	for (int i = 0; i < OrderOfPolynominal; i++)
	{
		if (i == Order) return Head[i].Value;
		Pointer = Pointer->Next;
	}
	throw MemoryError("Invalid order");
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

Polynominal Polynominal::Derivate()
	{
		int l = GetOrderOfPolynominal() - 1;

		Polynominal* newbie = new Polynominal(l);
		
		for(int current = 0; current < l; current++)
		{
			newbie->Set(current, current * GetCoef(current+1));
		}

		return (*newbie);
	}
