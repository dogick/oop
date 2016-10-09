#include "stdafx.h"
#include "GeneratorPrimeNumbers.h"
#include <iterator>

using namespace std;

static const int MIN_PRIME_NUMBER = 2;

set<int> FindPrimeNumbers(vector<bool> const& isPrime, int upperBound)
{
	set<int> primeNumbers;
	for (int i = MIN_PRIME_NUMBER; i <= upperBound; ++i)
	{
		if (isPrime[i])
		{
			primeNumbers.insert(i);
		}
	}
	return primeNumbers;
}

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	vector<bool> isPrime(upperBound + 1, true);
	isPrime[0] = false;
	if (upperBound != 0)
	{
		isPrime[1] = false;
	}
	for (int i = MIN_PRIME_NUMBER; i*i <= upperBound; ++i)
	{
		if (isPrime[i])
		{
			for (int j = i*i; j <= upperBound; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	return FindPrimeNumbers(isPrime, upperBound);
}

void PrintPrimeNumbersInOutput(set<int> const& primeNumbers)
{
	std::copy(primeNumbers.begin(), primeNumbers.end(), std::ostream_iterator<int>(std::cout, " "));
}