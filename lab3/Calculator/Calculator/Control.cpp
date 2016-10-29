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
        { "print", bind(&CControl::PrintVar, this, _1) },
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
    if (resultSplit.size() != 2)
    {
        throw runtime_error("Incorrect data entry!!!");
    }
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
    auto wasError = RuntimeError::NO_ERRORS;
    std::string assign;
    args >> assign;
    std::vector<std::string> resultSplit;
    try
    {
        resultSplit = GetSplitResult(assign);
    }
    catch (exception const& error)
    {
        m_output << error.what() << std::endl;
        return false;
    }
    if (!resultSplit.empty() && IsNumber(resultSplit[1]))
    {
        wasError = m_calculator.AssignValue(resultSplit[0], boost::lexical_cast<double>(resultSplit[1]));
    }
    else if(!resultSplit.empty() && m_calculator.CheckIdentifier(resultSplit[1]))
    {
        wasError = m_calculator.AssignIdentifier(resultSplit[0], resultSplit[1]);
    }
    else
    {
        wasError = RuntimeError::INCORRECT_DATA;
    }
    return PrintError(wasError);
}

bool CControl::PrintError(RuntimeError const& code)
{
    bool isWasError = true;
    switch (code)
    {
    case RuntimeError::INCORRECTLY_IDENTIFIER:
        m_output << "INCORRECTLY IDENTIFIER!!!\n";
        break;
    case RuntimeError::THIS_IDENTIFIER_ALREADY_DECLARED:
        m_output << "THIS IDENTIFIER ALREADY DECLARED!!!\n";
        break;
    case RuntimeError::INCORRECT_DATA:
        m_output << "INPUT DATA IS NOT CORRECT!!!\n";
        break;
    case RuntimeError::SECOND_IDENTIFIER_IS_NOT_DIFINE:
        m_output << "SECOND IDENTIFIER IS NOT DIFINE!!!\n";
        break;
    case RuntimeError::IDENTIFIER_IS_NOT_DIFINE:
        m_output << "IDENTIFIER IS NOT DIFINE!!!\n";
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

bool CControl::PrintVars(std::istream & /*args*/)
{
    auto vars = m_calculator.GetRepository().GetVars();
    for (auto var : vars)
    {
        std::string value = isnan(var.second) ? "nan" : GetFormatValue(var.second);
        m_output << var.first << ":" << value << std::endl;
    }
    return true;
}

bool CControl::PrintVar(std::istream & args)
{
    auto wasError = RuntimeError::NO_ERRORS;
    std::string identifier;
    args >> identifier;
    if (m_calculator.CheckIdentifier(identifier))
    {
        auto vars = m_calculator.GetRepository().GetVars();
        auto var = vars.find(identifier);
        if (var != vars.end())
        {
            std::string value = isnan(var->second) ? "nan" : GetFormatValue(var->second);
            m_output << var->first << ":" << value << std::endl;
        }
        else
        {
            wasError = RuntimeError::IDENTIFIER_IS_NOT_DIFINE;
        }
    }
    else
    {
        wasError = RuntimeError::INCORRECTLY_IDENTIFIER;
    }
    return PrintError(wasError);
}

/*bool CControl::PrintVar(std::istream & args)
{
    auto wasError = RuntimeError::NO_ERRORS;
    std::string identifier;
    args >> identifier;

    return PrintError(wasError);
}*/