#pragma once
#include <iostream>

using namespace std;

class PolynominalError
{
	const char* Message;

protected:

	PolynominalError();

	void SetMessage(const char* Message);

	void PrintInfo();
};

class SearchError : PolynominalError
{
public:
	SearchError(const char* Message);
};

class RangeError : PolynominalError
{
public:
	RangeError(const char* Message);
};

