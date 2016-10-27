#include "stdafx.h"
#include "Calculator.h"

Vars CCalculator::GetVariables() const
{
    return m_variables.GetVars();
}
bool CCalculator::IsDigit(char ch) const
{
    return (ch >= '0') && (ch <= '9');
}

bool CCalculator::CheckIdentifier(std::string const& identifier) const
{
    bool isIdentifier = true;
    if (!identifier.empty() && !IsDigit(identifier[0]))
    {
        for (char symbol : identifier)
        {
            bool isCorrectSymbol = (symbol >= 'A') && (symbol <= 'Z') || (symbol >= 'a') && (symbol <= 'z') || (symbol == '_') || IsDigit(symbol);
            if (!isCorrectSymbol)
            {
                isIdentifier = false;
            }
        }
    }
    else
    {
        isIdentifier = false;
    }
    return isIdentifier;
}

ReturnCode CCalculator::DefineVar(std::string const& identifier)
{
    ReturnCode wasError = ReturnCode::NO_ERRORS;
    bool isIdentifier = CheckIdentifier(identifier);
    bool isIdentifierDeclared = m_variables.IsIdentifierDeclared(identifier);
    if (!identifier.empty() && isIdentifier && !isIdentifierDeclared)
    {
        m_variables.AddIdentifier(identifier);
    }
    else if (!isIdentifier)
    {
        wasError = ReturnCode::INCORRECTLY_IDENTIFIER;
    }
    else if (isIdentifierDeclared)
    {
        wasError = ReturnCode::THIS_IDENTIFIER_ALREADY_DECLARED;
    }
    return wasError;
}

void CCalculator::AssignValue(std::string const& identifier, double value)
{
    bool isIdentifierDeclared = m_variables.IsIdentifierDeclared(identifier);
    if (isIdentifierDeclared)
    {
        m_variables.SetValue(identifier, value);
    }
    else if (!isIdentifierDeclared)
    {
        m_variables.AddIdentifier(identifier);
        m_variables.SetValue(identifier, value);
    }
}

void CCalculator::AssignIdentifier(std::string const& firstIdentifier, std::string const& secondIdentifier)
{
   // ReturnCode wasError = ReturnCode::NO_ERRORS;
   // return wasError;
}