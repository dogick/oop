#include "stdafx.h"
#include "ProcessVector.h"

std::vector<double> GetNumbers()
{
	std::cout << "Enter the numbers separated by spaces: ";
	std::string inputString;
	std::getline(std::cin, inputString);

	std::vector<std::string> resultSplit;
	boost::split(resultSplit, inputString, boost::is_any_of(" "));

	std::vector<double> numbers;
	std::transform(resultSplit.begin(), resultSplit.end(), std::back_inserter(numbers), boost::lexical_cast<int, std::string>);

	return numbers;
}

double GetArithmeticalMean(std::vector<double> const& numbers)
{
	int count = 0;
	double sum = 0;
	for (auto number : numbers)
	{
		if (number >= 0)
		{
			++count;
			sum += number;
		}
	}
	return sum / count;
}

void OutputNumber(std::vector<double> const& numbers)
{
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(std::cout << std::setprecision(3), " "));
}

void ProcessVector(std::vector<double> & numbers)
{
	if (!numbers.empty())
	{
		double arithmeticalMean = GetArithmeticalMean(numbers);
		std::transform(numbers.begin(), numbers.end(), numbers.begin(), [arithmeticalMean](double number) {return  number + arithmeticalMean; });
		std::sort(numbers.begin(), numbers.end());
		OutputNumber(numbers);
	}
}