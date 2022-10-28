#pragma once
#include "Polynominal.hpp"
#include <termios.h>
#include <unistd.h>
#include <iostream>

char getch(void);

Polynominal *MenuInput();

ostream &operator<<(ostream &os, const Polynominal &Obj);

double InputValue();