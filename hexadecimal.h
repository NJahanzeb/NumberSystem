#pragma once
#include <iostream>
#include "numbersystem.h"

using namespace std;

class Hexadecimal : public NumberSystem
{
private:
	char inputNum[16];
	long integerResult;

public:
	Hexadecimal();
	void getInput();
	void hexToDec(int check);
	void hexToBin();
	void hexToOctal();
	void operator + (Hexadecimal hh);
	void operator - (Hexadecimal hh);
	void operator * (Hexadecimal hh);
	void operator / (Hexadecimal hh);
};
