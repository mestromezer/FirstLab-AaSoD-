#pragma once
#include <iostream>

using namespace std;

class PolynominalError: public exception
{
	const char* Message;

protected:

	PolynominalError();

	void SetMessage(const char* Message);

	void PrintInfo();
};

class MemoryError : PolynominalError
{
public:
	MemoryError(const char* Message);
};

class RangeError : PolynominalError
{
public:
	RangeError(const char* Message);
};

