#pragma once
#include "stdafx.h"
#include <boost/noncopyable.hpp>
#include "Calculator.h"


class CControl : boost::noncopyable
{
public:
	CControl(CCalculator & calculator, std::istream & input, std::ostream & output);
	bool HandleCommand();
private:
	bool PrintError(ReturnCode const& code);
	bool DefineVar(std::istream & args);
	bool PrintValueVar(std::istream & args);
	bool PrintVars(std::istream & args);
	bool SetValueVar(std::istream & args);
	std::string GetFormatValue(double const& value);
private:
	typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;

	CCalculator & m_calculator;
	std::istream & m_input;
	std::ostream & m_output;

	const ActionMap m_actionMap;
};
