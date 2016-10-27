#include "stdafx.h"
#include "Control.h"

using namespace std;
using namespace std::placeholders;

CControl::CControl(CCalculator & calculator, std::istream & input, std::ostream & output)
    : m_calculator(calculator)
    , m_input(input)
    , m_output(output)
    , m_actionMap({
        { "var", bind(&CControl::DefineVar, this, _1) },
        { "let", bind(&CControl::AssignVar, this, _1) },
        { "printvars", bind(&CControl::PrintVars, this, _1) },
})
{
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
    auto wasError = m_calculator.DefineVar(identifier);
    return PrintError(wasError);
}

std::vector<std::string> CControl::GetSplitResult(std::string const& assign)
{
    std::vector<std::string> resultSplit;
    boost::split(resultSplit, assign, boost::is_any_of("="));
    return resultSplit;
}

bool CControl::IsNumber(std::string const& assign)
{
    bool isNumber = true;
    try
    {
        boost::lexical_cast<double>(assign);
    }
    catch (boost::bad_lexical_cast)
    {
        isNumber = false;
    }
    return isNumber;
}

bool CControl::AssignVar(std::istream & args)
{
    auto wasError = ReturnCode::NO_ERRORS;
    std::string assign;
    args >> assign;
    std::vector<std::string> resultSplit = GetSplitResult(assign);
    if (!resultSplit.empty() && m_calculator.CheckIdentifier(resultSplit[0]) && IsNumber(resultSplit[1]))
    {
        m_calculator.AssignValue(resultSplit[0], boost::lexical_cast<double>(resultSplit[1]));
    }
    else if(!resultSplit.empty() && m_calculator.CheckIdentifier(resultSplit[0]) && m_calculator.CheckIdentifier(resultSplit[1]))
    {
        m_calculator.AssignIdentifier(resultSplit[0], resultSplit[1]);
    }
    else
    {
        wasError = ReturnCode::INCORRECT_DATA;
    }
    return PrintError(wasError);
}

bool CControl::PrintError(ReturnCode const& code)
{
    bool isWasError = true;
    switch (code)
    {
    case ReturnCode::INCORRECTLY_IDENTIFIER:
        m_output << "INCORRECTLY IDENTIFIER!!!\n";
        break;
    case ReturnCode::THIS_IDENTIFIER_ALREADY_DECLARED:
        m_output << "THIS IDENTIFIER ALREADY DECLARED!!!\n";
        break;
    case ReturnCode::INCORRECT_DATA:
        m_output << "INCORRECT DATA!!!\n";
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

bool CControl::PrintVars(std::istream & args)
{
	auto vars = m_calculator.GetVariables();
	for (auto var : vars)
	{
		std::string value = isnan(var.second) ? "nan" : GetFormatValue(var.second);
		std::cout << var.first << ":" << value << std::endl;
	}
	return true;
}