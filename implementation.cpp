#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include "numbersystem.h"
#include "decimal.h"
#include "binary.h"
#include "octal.h"
#include "hexadecimal.h"


using namespace std;

NumberSystem::NumberSystem()
{}





Decimal::Decimal() : NumberSystem::NumberSystem()
{
	inputNum = 0;
}

Decimal::Decimal(int a) : NumberSystem::NumberSystem()
{
	inputNum = a;
}

void Decimal::getInput()
{
	cout << "\nEnter decimal number: ";
	cin >> inputNum;
}

void Decimal::decToBin()
{
	long input = inputNum;
	long remainder;
	int binaryResult[64];

	int i = 0;
	while (input > 0)
	{
		remainder = input % NumberSystem::binBase;
		input /= NumberSystem::binBase;
		binaryResult[i] = remainder;
		++i;
	}

	cout << "\nResult: ";
	for (int j = i - 1; j >= 0; --j)
	{
		cout << binaryResult[j];
	}
	cout << endl;
}

void Decimal::decToOctal()
{
	long input = inputNum;
	long remainder;
	int octalResult[32];

	int i = 0;
	while (input > 0)
	{
		remainder = input % NumberSystem::octalBase;
		input /= NumberSystem::octalBase;
		octalResult[i] = remainder;
		++i;
	}

	cout << "\nResult: ";
	for (int j = i - 1; j >= 0; --j)
	{
		cout << octalResult[j];
	}
	cout << endl;
}

void Decimal::decToHex()
{
	long input = inputNum;
	char remainder;
	char hexResult[16];

	int i = 0;
	while (input > 0)
	{
		if (input % NumberSystem::hexBase >= 0 && input % NumberSystem::hexBase <= 9)
		{
			remainder = (input % NumberSystem::hexBase + 48);
		}
		else
		{
			remainder = (input % NumberSystem::hexBase + 55);
		}

		input /= NumberSystem::hexBase;
		hexResult[i] = remainder;
		++i;
	}

	cout << "\nResult: ";
	for (int j = i - 1; j >= 0; --j)
	{
		cout << hexResult[j];
	}
	cout << endl;
}

void Decimal::decToBin(long integerNum)
{
	long input = integerNum;
	long remainder;
	int binaryResult[64];

	int i = 0;
	while (input > 0)
	{
		remainder = input % NumberSystem::binBase;
		input /= NumberSystem::binBase;
		binaryResult[i] = remainder;
		++i;
	}

	cout << "\nResult: ";
	for (int j = i - 1; j >= 0; --j)
	{
		cout << binaryResult[j];
	}
	cout << endl;
}

void Decimal::decToOctal(long integerNum)
{
	long input = integerNum;
	long remainder;
	int octalResult[32];

	int i = 0;
	while (input > 0)
	{
		remainder = input % NumberSystem::octalBase;
		input /= NumberSystem::octalBase;
		octalResult[i] = remainder;
		++i;
	}

	cout << "\nResult: ";
	for (int j = i - 1; j >= 0; --j)
	{
		cout << octalResult[j];
	}
	cout << endl;
}

void Decimal::decToHex(long integerNum)
{
	long input = integerNum;
	char remainder;
	char hexResult[16];

	int i = 0;
	while (input > 0)
	{
		if (input % NumberSystem::hexBase >= 0 && input % NumberSystem::hexBase <= 9)
		{
			remainder = (input % NumberSystem::hexBase + 48);
		}
		else
		{
			remainder = (input % NumberSystem::hexBase + 55);
		}

		input /= NumberSystem::hexBase;
		hexResult[i] = remainder;
		++i;
	}

	cout << "\nResult: ";
	for (int j = i - 1; j >= 0; --j)
	{
		cout << hexResult[j];
	}
	cout << endl;
}

void Decimal::operator + (Decimal dd)
{
	long result = inputNum + dd.inputNum;
	cout << "\nAddition result: " << result << endl;
}

void Decimal::operator - (Decimal dd)
{
	long result = inputNum - dd.inputNum;
	cout << "\nSubtraction result: " << result << endl;
}

void Decimal::operator * (Decimal dd)
{
	long result = inputNum * dd.inputNum;
	cout << "\nMultiplication result: " << result << endl;
}

void Decimal::operator / (Decimal dd)
{
	double result = (double)inputNum / (double)dd.inputNum;
	cout << "\nDivision result: " << result << endl;
}





Binary::Binary() : NumberSystem::NumberSystem()
{
	inputNum = 0;
	integerResult = 0;
}

Binary::Binary(long long a) : NumberSystem::NumberSystem()
{
	inputNum = a;
	integerResult = 0;
}

void Binary::getInput()
{
	cout << "\nEnter binary number: ";
	cin >> inputNum;
}

void Binary::binToDec(int check)
{
	long long input = inputNum;
	long result = 0;
	int base = 1;
	long remainder;

	while (input > 0)
	{
		remainder = input % NumberSystem::decBase;
		input /= NumberSystem::decBase;
		result += remainder * base;
		base *= NumberSystem::binBase;
	}

	integerResult = result;

	if (check == 1)
	{
		cout << "\nResult: " << integerResult;
	}
}

void Binary::binToOctal()
{
	binToDec(0);
	Decimal::decToOctal(integerResult);
}

void Binary::binToHex()
{
	binToDec(0);
	Decimal::decToHex(integerResult);
}

void Binary::operator + (Binary bb)
{
	binToDec(0);
	bb.binToDec(0);
	integerResult += bb.integerResult;
	Decimal::decToBin(integerResult);
	cout << "Result (in Decimal): " << integerResult << endl;
}

void Binary::operator - (Binary bb)
{
	binToDec(0);
	bb.binToDec(0);
	integerResult -= bb.integerResult;
	Decimal::decToBin(integerResult);
	cout << "Result (in Decimal): " << integerResult << endl;
}

void Binary::operator * (Binary bb)
{
	binToDec(0);
	bb.binToDec(0);
	integerResult *= bb.integerResult;
	Decimal::decToBin(integerResult);
	cout << "Result (in Decimal): " << integerResult << endl;
}

void Binary::operator / (Binary bb)
{
	binToDec(0);
	bb.binToDec(0);
	integerResult /= bb.integerResult;
	Decimal::decToBin(integerResult);
	cout << "Result (in Decimal): " << integerResult << endl;
}

Octal::Octal() : NumberSystem::NumberSystem()
{
	inputNum = 0;
	integerResult = 0;
}

Octal::Octal(long a)
{
	inputNum = a;
	integerResult = 0;
}

void Octal::getInput()
{
	cout << "\nEnter octal number: ";
	cin >> inputNum;
}

void Octal::octToDec(int check)
{
	int i = 0;
	int remainder;

	while (inputNum > 0)
	{
		remainder = inputNum % NumberSystem::decBase;
		inputNum /= NumberSystem::decBase;
		integerResult += remainder * (long)pow(NumberSystem::octalBase, i);
		++i;
	}

	if (check == 1)
	{
		cout << "\nResult: " << integerResult;
	}
}

void Octal::octToBin()
{
	octToDec(0);
	Decimal::decToBin(integerResult);
}

void Octal::octToHex()
{
	octToDec(0);
	Decimal::decToHex(integerResult);
}

void Octal::operator + (Octal oo)
{
	octToDec(0);
	oo.octToDec(0);
	integerResult += oo.integerResult;
	Decimal::decToOctal(integerResult);
	cout << "Result (in Decimal): " << integerResult << endl;
}

void Octal::operator - (Octal oo)
{
	octToDec(0);
	oo.octToDec(0);
	integerResult -= oo.integerResult;
	Decimal::decToOctal(integerResult);
	cout << "Result (in Decimal): " << integerResult << endl;
}

void Octal::operator * (Octal oo)
{
	octToDec(0);
	oo.octToDec(0);
	integerResult *= oo.integerResult;
	Decimal::decToOctal(integerResult);
	cout << "Result (in Decimal): " << integerResult << endl;
}

void Octal::operator / (Octal oo)
{
	octToDec(0);
	oo.octToDec(0);
	integerResult /= oo.integerResult;
	Decimal::decToOctal(integerResult);
	cout << "Result (in Decimal): " << integerResult << endl;
}





Hexadecimal::Hexadecimal() : NumberSystem::NumberSystem()
{
	inputNum[0] = '0';
	integerResult = 0;
}

void Hexadecimal::getInput()
{
	cout << "\nEnter hexadecial number: ";
	cin >> inputNum;
}

void Hexadecimal::hexToDec(int check)
{
	int len = strlen(inputNum) - 1;
	int exponent = len;

	for (int i = 0; i < len; ++i)
	{
		if (inputNum[i] >= '0' && inputNum[i] <= '9')
		{
			integerResult += (((long)inputNum[i] - 48) * (long)pow(NumberSystem::hexBase, exponent));
		}
		else
		{
			integerResult += (((long)inputNum[i] - 55) * (long)pow(NumberSystem::hexBase, exponent));
		}
		--exponent;
	}

	if (check == 1)
	{
		cout << "\nResult: " << integerResult;
	}
}

void Hexadecimal::hexToBin()
{
	hexToDec(0);
	Decimal::decToBin(integerResult);
}

void Hexadecimal::hexToOctal()
{
	hexToDec(0);
	Decimal::decToOctal(integerResult);
}

void Hexadecimal::operator + (Hexadecimal hh)
{
	hexToDec(0);
	hh.hexToDec(0);
	integerResult += hh.integerResult;
	Decimal::decToHex(integerResult);
	cout << "Result (in Decimal): " << integerResult << endl;
}

void Hexadecimal::operator - (Hexadecimal hh)
{
	hexToDec(0);
	hh.hexToDec(0);
	integerResult -= hh.integerResult;
	Decimal::decToHex(integerResult);
	cout << "Result (in Decimal): " << integerResult << endl;
}

void Hexadecimal::operator * (Hexadecimal hh)
{
	hexToDec(0);
	hh.hexToDec(0);
	integerResult *= hh.integerResult;
	Decimal::decToHex(integerResult);
	cout << "Result (in Decimal): " << integerResult << endl;
}

void Hexadecimal::operator / (Hexadecimal hh)
{
	hexToDec(0);
	hh.hexToDec(0);
	integerResult /= hh.integerResult;
	Decimal::decToHex(integerResult);
	cout << "Result (in Decimal): " << integerResult << endl;
}





void programInterface()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   Welcome to number conversion and calculation system!";

	while (1)
	{
		Binary b, bb;
		Decimal d, dd;
		Hexadecimal h, hh;
		Octal o, oo;
		int mainmenu, submenu, option;

		chrono::seconds dura(4);
		this_thread::sleep_for(dura);
		system("CLS");

		cout << "\n\nEnter 1 to work in Binary system,\n2 to work in Decimal system,\n3 to work in Hexadecimal system,\n4 to work in Octal system or,\n0 to exit.\n\n";
		cin >> mainmenu;

		switch (mainmenu)
		{
		case 0:
			system("CLS");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tgoodbye.\n\n\n\n\n\n\n\n\n\n\n\n\n";
			exit(0);

		case 1:
			b.getInput();
			cout << "\nEnter 1 to convert the number to other number systems,\n2 to perform arithmetic operations on it or,\n3 to go back to main menu.\n\n";
			cin >> submenu;
			switch (submenu)
			{
			case 1:
				cout << "\nEnter 1 to convert the number to Decimal,\n2 to convert it to Octal or,\n3 to convert it to Hexadecimal.\n\n";
				cin >> option;
				if (option == 1)
				{
					b.binToDec(1);
				}
				else if (option == 2)
				{
					b.binToOctal();
				}
				else if (option == 3)
				{
					b.binToHex();
				}
				else
				{
					cout << "\nYou selected an invalid option.\n";
				}
				break;

			case 2:
				cout << "\nLet's make a second binary number first!";
				bb.getInput();
				cout << "\nEnter 1 to add the binary numbers,\n2 to subtract,\n3 to multiply or,\n4 to divide.\n\n";
				cin >> option;
				if (option == 1)
				{
					b + bb;
				}
				else if (option == 2)
				{
					b - bb;
				}
				else if (option == 3)
				{
					b* bb;
				}
				else if (option == 4)
				{
					b / bb;
				}
				else
				{
					cout << "\nYou selected an invalid option.\n";
				}
				break;

			case 3:
				continue;
			}
			break;

		case 2:
			d.getInput();
			cout << "\nEnter 1 to convert the number to other number systems,\n2 to perform arithmetic operations on it or,\n3 to go back to main menu.\n\n";
			cin >> submenu;
			switch (submenu)
			{
			case 1:
				cout << "\nEnter 1 to convert the number to Binary,\n2 to convert it to Octal or,\n3 to convert it to Hexadecimal.\n\n";
				cin >> option;
				if (option == 1)
				{
					d.decToBin();
				}
				else if (option == 2)
				{
					d.decToOctal();
				}
				else if (option == 3)
				{
					d.decToHex();
				}
				else
				{
					cout << "\nYou selected an invalid option.\n";
				}
				break;

			case 2:
				cout << "\nLet's make a second decimal number first!";
				dd.getInput();
				cout << "\nEnter 1 to add the decimal numbers,\n2 to subtract,\n3 to multiply or,\n4 to divide.\n\n";
				cin >> option;
				if (option == 1)
				{
					d + dd;
				}
				else if (option == 2)
				{
					d - dd;
				}
				else if (option == 3)
				{
					d* dd;
				}
				else if (option == 4)
				{
					d / dd;
				}
				else
				{
					cout << "\nYou selected an invalid option.\n";
				}
				break;

			case 3:
				continue;
			}
			break;

		case 3:
			h.getInput();
			cout << "\nEnter 1 to convert the number to other number systems,\n2 to perform arithmetic operations on it or,\n3 to go back to main menu.\n\n";
			cin >> submenu;
			switch (submenu)
			{
			case 1:
				cout << "\nEnter 1 to convert the number to Binary,\n2 to convert it to Decimal or,\n3 to convert it to Octal.\n\n";
				cin >> option;
				if (option == 1)
				{
					h.hexToBin();
				}
				else if (option == 2)
				{
					h.hexToDec(1);
				}
				else if (option == 3)
				{
					h.hexToOctal();
				}
				else
				{
					cout << "\nYou selected an invalid option.\n";
				}
				break;

			case 2:
				cout << "\nLet's make a second hexadecimal number first!";
				hh.getInput();
				cout << "\nEnter 1 to add the hexadecimal numbers,\n2 to subtract,\n3 to multiply or,\n4 to divide.\n\n";
				cin >> option;
				if (option == 1)
				{
					h + hh;
				}
				else if (option == 2)
				{
					h - hh;
				}
				else if (option == 3)
				{
					h* hh;
				}
				else if (option == 4)
				{
					h/ hh;
				}
				else
				{
					cout << "\nYou selected an invalid option.\n";
				}
				break;

			case 3:
				continue;
			}
			break;

		case 4:
			o.getInput();
			cout << "\nEnter 1 to convert the number to other number systems,\n2 to perform arithmetic operations on it or,\n3 to go back to main menu.\n\n";
			cin >> submenu;
			switch (submenu)
			{
			case 1:
				cout << "\nEnter 1 to convert the number to Binary,\n2 to convert it to Decimal or,\n3 to convert it to Hexadecimal.\n\n";
				cin >> option;
				if (option == 1)
				{
					o.octToBin();
				}
				else if (option == 2)
				{
					o.octToDec(1);
				}
				else if (option == 3)
				{
					o.octToHex();
				}
				else
				{
					cout << "\nYou selected an invalid option.\n";
				}
				break;

			case 2:
				cout << "\nLet's make a second octal number first!";
				oo.getInput();
				cout << "\nEnter 1 to add the octal numbers,\n2 to subtract,\n3 to multiply or,\n4 to divide.\n\n";
				cin >> option;
				if (option == 1)
				{
					o + oo;
				}
				else if (option == 2)
				{
					o - oo;
				}
				else if (option == 3)
				{
					o* oo;
				}
				else if (option == 4)
				{
					o / oo;
				}
				else
				{
					cout << "\nYou selected an invalid option.\n";
				}
				break;

			case 3:
				continue;
			}
			break;

		default:
			cout << "You selected an invalid option.\n";
			break;
		}
	}
}
