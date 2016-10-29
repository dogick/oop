#include "stdafx.h"
#include "Calculator.h"

CRepository CCalculator::GetRepository() const
{
    return m_repository;
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

RuntimeError CCalculator::DefineVar(std::string const& identifier)
{
    RuntimeError wasError = RuntimeError::NO_ERRORS;
    bool isIdentifier = CheckIdentifier(identifier);
    bool isIdentifierDeclared = m_repository.IsIdentifierDeclared(identifier);
    if (!identifier.empty() && isIdentifier && !isIdentifierDeclared)
    {
        m_repository.AddIdentifier(identifier);
    }
    else if (!isIdentifier)
    {
        wasError = RuntimeError::INCORRECTLY_IDENTIFIER;
    }
    else if (isIdentifierDeclared)
    {
        wasError = RuntimeError::THIS_IDENTIFIER_ALREADY_DECLARED;
    }
    return wasError;
}

RuntimeError CCalculator::AssignValue(std::string const& identifier, double value)
{
    RuntimeError wasError = RuntimeError::NO_ERRORS;
    bool isIdentifierDeclared = m_repository.IsIdentifierDeclared(identifier);
    if (CheckIdentifier(identifier))
    {
        if (isIdentifierDeclared)
        {
            m_repository.SetValue(identifier, value);
        }
        else if (!isIdentifierDeclared)
        {
            m_repository.AddIdentifier(identifier);
            m_repository.SetValue(identifier, value);
        }
    }
    else
    {
        wasError = RuntimeError::INCORRECTLY_IDENTIFIER;
    }
    return wasError;
}

RuntimeError CCalculator::AssignIdentifier(std::string const& firstIdentifier, std::string const& secondIdentifier)
{
    RuntimeError wasError = RuntimeError::NO_ERRORS;
    if (CheckIdentifier(firstIdentifier) && CheckIdentifier(secondIdentifier))
    {
        bool isfirstIdentifierDeclared = m_repository.IsIdentifierDeclared(firstIdentifier);
        bool issecondIdentifierDeclared = m_repository.IsIdentifierDeclared(secondIdentifier);
        if (isfirstIdentifierDeclared && issecondIdentifierDeclared)
        {
            double value = m_repository.GetValueVar(secondIdentifier);
            m_repository.SetValue(firstIdentifier, value);
        }
        else if (!isfirstIdentifierDeclared && issecondIdentifierDeclared)
        {
            wasError = DefineVar(firstIdentifier);
            double value = m_repository.GetValueVar(secondIdentifier);
            m_repository.SetValue(firstIdentifier, value);
        }
        else
        {
            wasError = RuntimeError::SECOND_IDENTIFIER_IS_NOT_DIFINE;
        }
    }
    else
    {
        wasError = RuntimeError::INCORRECTLY_IDENTIFIER;
    }
    return wasError;
}