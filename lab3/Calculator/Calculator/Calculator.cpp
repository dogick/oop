#include "stdafx.h"
#include "Calculator.h"

Vars CCalculator::GetVariables() const
{
    return m_variables.GetVars();
}

double CCalculator::GetValueVar(std::string const& identifier) const
{
    return GetVariables().find(identifier)->second;
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

ReturnCode CCalculator::AssignIdentifier(std::string const& firstIdentifier, std::string const& secondIdentifier)
{
    ReturnCode wasError = ReturnCode::NO_ERRORS;
    bool isfirstIdentifierDeclared = m_variables.IsIdentifierDeclared(firstIdentifier);
    bool issecondIdentifierDeclared = m_variables.IsIdentifierDeclared(secondIdentifier);
    if (isfirstIdentifierDeclared && issecondIdentifierDeclared)
    {
        double value = GetValueVar(secondIdentifier);
        m_variables.SetValue(firstIdentifier, value);
    }
    else if (!isfirstIdentifierDeclared && issecondIdentifierDeclared)
    {
        m_variables.AddIdentifier(firstIdentifier);
        double value = GetValueVar(secondIdentifier);
        m_variables.SetValue(firstIdentifier, value);
    }
    else
    {
        wasError = ReturnCode::SECOND_IDENTIFIER_IS_NOT_DIFINE;
    }
    return wasError;
}