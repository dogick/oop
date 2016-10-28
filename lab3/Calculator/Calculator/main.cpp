// Car.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "Calculator.h"
#include "Control.h"

int main()
{
	setlocale(LC_ALL, "rus");
	CCalculator calculator;
	CControl control(calculator, std::cin, std::cout);

	//calculator.SetVar("point", 100.2451);
	//calculator.OutputVar();

	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		if (!control.HandleCommand())
		{
			std::cout << "Unknown command!\n";
		}
	}
	return 0;
}

