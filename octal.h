#pragma once
#include <iostream>
#include "numbersystem.h"

using namespace std;

class Octal : public NumberSystem
{
private:
	long inputNum;
	long integerResult;

public:
	Octal();
	Octal(long a);
	void getInput();
	void octToDec(int check);
	void octToBin();
	void octToHex();
	void operator + (Octal oo);
	void operator - (Octal oo);
	void operator * (Octal oo);
	void operator / (Octal oo);
};
