#include "stdafx.h"
#include "Calculator.h"

CStorageVar CCalculator::GetStorageVar() const
{
    return m_storageVar;
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
    bool isIdentifierDeclared = m_storageVar.IsIdentifierDeclared(identifier);
    if (!identifier.empty() && isIdentifier && !isIdentifierDeclared)
    {
        m_storageVar.AddIdentifier(identifier);
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
    bool isIdentifierDeclared = m_storageVar.IsIdentifierDeclared(identifier);
    if (CheckIdentifier(identifier))
    {
        if (isIdentifierDeclared)
        {
            m_storageVar.SetValue(identifier, value);
        }
        else if (!isIdentifierDeclared)
        {
            m_storageVar.AddIdentifier(identifier);
            m_storageVar.SetValue(identifier, value);
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
        bool isfirstIdentifierDeclared = m_storageVar.IsIdentifierDeclared(firstIdentifier);
        bool issecondIdentifierDeclared = m_storageVar.IsIdentifierDeclared(secondIdentifier);
        if (isfirstIdentifierDeclared && issecondIdentifierDeclared)
        {
            double value = m_storageVar.GetValueVar(secondIdentifier);
            m_storageVar.SetValue(firstIdentifier, value);
        }
        else if (!isfirstIdentifierDeclared && issecondIdentifierDeclared)
        {
            wasError = DefineVar(firstIdentifier);
            double value = m_storageVar.GetValueVar(secondIdentifier);
            m_storageVar.SetValue(firstIdentifier, value);
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