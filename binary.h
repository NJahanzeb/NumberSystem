#pragma once
#include <iostream>
#include "numbersystem.h"

using namespace std;

class Binary : public NumberSystem
{
private:
	long long inputNum;
	long integerResult;

public:
	Binary();
	Binary(long long a);
	void getInput();
	void binToDec(int check);
	void binToOctal();
	void binToHex();
	void operator + (Binary bb);
	void operator - (Binary bb);
	void operator * (Binary bb);
	void operator / (Binary bb);
};
