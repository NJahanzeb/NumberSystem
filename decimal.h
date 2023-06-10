#pragma once
#include <iostream>
#include "numbersystem.h"

using namespace std;

class Decimal : public NumberSystem
{
private:
	long inputNum;

public:
	Decimal();
	Decimal(int a);
	void getInput();
	void decToBin();
	void decToOctal();
	void decToHex();
	static void decToBin(long integerNum);
	static void decToOctal(long integerNum);
	static void decToHex(long integerNum);
	void operator + (Decimal dd);
	void operator - (Decimal dd);
	void operator * (Decimal dd);
	void operator / (Decimal dd);

};
