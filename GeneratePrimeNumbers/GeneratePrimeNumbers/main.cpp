#include "stdafx.h"
#include "GeneratorPrimeNumbers.h"
#include <iostream>

using namespace std;

static const int MAX_NUMBER = 100000000;

int main(int argc, char *argv[])
{
	unsigned int startTime = clock(); 
	if (argc == 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: GeneratePrimeNumbers.exe <Upper Bound>\n";
		return 1;
	}

	int upperBound;
	try
	{
		upperBound = stoi("100000000");
	}
	catch(std::exception const& e)
	{
		cout << "error : " << e.what() << endl;
		return 1;
	}

	if (MAX_NUMBER >= upperBound)
	{
		set<int> primeNumbers = GeneratePrimeNumbersSet(upperBound);
		cout << primeNumbers.size() << endl;
		//PrintPrimeNumbersInOutput(primeNumbers);
	}
	else
	{
		cout << "The number must be less than " << MAX_NUMBER << "!\n";
	}
	unsigned int endTime = clock();
	unsigned int searchTime = endTime - startTime; 
	cout << searchTime / 1000.f << endl;
	return 0;
}