#include "stdafx.h"
#include "Control.h"
#include "Calculator.h"
#include <boost/optional.hpp>
#include <boost/format.hpp>

using namespace std;
using namespace std::placeholders;


CControl::CControl(CCalculator & calculator, std::istream & input, std::ostream & output)
	: m_calculator(calculator)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "var", bind(&CControl::DefineVar, this, _1) },
		{ "print", bind(&CControl::PrintValueVar, this, _1) },
		{ "printvars", bind(&CControl::PrintVars, this, _1) },
		{ "let", bind(&CControl::SetValueVar, this, _1) },
})
{
}

bool CControl::PrintError(ReturnCode const& code)
{
	bool isWasError = true;
	switch (code)
	{
	case ReturnCode::NOT_FOUND_IDENTIFIER:
		m_output << "NOT FOUND ID!!!\n";
		break;
	case ReturnCode::INCORRECT_IDENTIFIER:
		m_output << "INCORRECT ID!!!\n";
		break;
	case ReturnCode::IDENTIFIER_ALREADY_HAS:
		m_output << "ID ALREADY HAS!!!\n";
			break;
	default:
		isWasError = false;
		break;
	}
	return isWasError;
}

std::string CControl::GetFormatValue(double const& value)
{
	return str(boost::format("%.2f") % value);
}

bool CControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strm);
	}
	else
	{
		return false;
	}

	return true;
}

bool CControl::DefineVar(std::istream & args)
{
	std::string identifier;
	args >> identifier;
	auto code = m_calculator.DefineVar(identifier);
	return PrintError(code);
}

bool CControl::PrintValueVar(std::istream & args)
{
	std::string identifier;
	args >> identifier;
	std::string result;
	if (m_calculator.IsVar(identifier))
	{
		double value = m_calculator.GetValueVar(identifier);
		result = isnan(value) ? "nan" : GetFormatValue(value);
	}
	else
	{
		m_output << "ERROR: Such identifier has not been declared!!!\n";
		return false;
	}
	m_output << result << "\n";
	return true;
}

bool CControl::PrintVars(std::istream & args)
{
	auto vars = m_calculator.GetVars();
	for (auto var : vars)
	{
		std::string value = isnan(var.second) ? "nan" : GetFormatValue(var.second);
		std::cout << var.first << ":" << value << std::endl;
	}
	return true;
}

bool CControl::SetValueVar(std::istream & args)
{
	ReturnCode code;
	std::string determination;
	args >> determination;
	boost::regex identifierAndValue("(\\w+)=([+-]?(\\d*[.,])?\\d*)");
	boost::regex twoIdentifier("(\\w+)=(\\w+)");
	boost::cmatch result;
	double value;
	if (boost::regex_match(determination.c_str(), result, identifierAndValue))
	{
		std::string identifier = std::string(result[1].first, result[1].second);
		std::cout << "dgd" << std::endl;
		value = boost::lexical_cast<double>(std::string(result[2].first, result[2].second));
		m_calculator.SetValueVar(identifier, value);
	}
	else if (boost::regex_match(determination.c_str(), result, twoIdentifier))
	{
		std::string firstIdentifier = std::string(result[1].first, result[1].second);
		std::string secondIdentifier = std::string(result[2].first, result[2].second);
		code = m_calculator.AssignVar(firstIdentifier, secondIdentifier);
		PrintError(code);
		std::cout << "dgnd" << std::endl;
	}
	else
	{
		code = ReturnCode::INCORRECT_PHRASE_ENTERED;
		PrintError(code);
		return false;
	}
	return true;
}