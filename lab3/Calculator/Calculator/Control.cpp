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
    auto code = m_calculator.DefineVar(identifier);
    return PrintError(code);
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
    default:
        isWasError = false;
        break;
    }
    return isWasError;
}