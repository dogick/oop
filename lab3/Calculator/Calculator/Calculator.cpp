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
            bool isCorrectSymbol = (symbol >= 'A') && (symbol <= 'Z') || (symbol >= 'a') && 
                (symbol <= 'z') || (symbol == '_') || IsDigit(symbol);
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
        if (m_repository.IsVar(secondIdentifier))
        {
            if (!m_repository.IsVar(firstIdentifier))
            {
                wasError = DefineVar(firstIdentifier);
            }
            double value = m_repository.GetValueVar(secondIdentifier);
            m_repository.SetValue(firstIdentifier, value);
        }
        else if (m_repository.IsFunction(secondIdentifier))
        {
            if (!m_repository.IsVar(firstIdentifier))
            {
                wasError = DefineVar(firstIdentifier);
            }
            double value = GetFnResult(secondIdentifier);
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

double CCalculator::CalculationValue(double firstOperandValue, double secondOperandValue, Operation const& operation) const
{
    double result;
    switch (operation)
    {
    case Operation::ADD:
        result = firstOperandValue + secondOperandValue;
        break;
    case Operation::DIV:
        result = firstOperandValue / secondOperandValue;
        break;
    case Operation::MUL:
        result = firstOperandValue * secondOperandValue;
        break;
    case Operation::SUB:
        result = firstOperandValue - secondOperandValue;
        break;
    default:
        break;
    }
    return result;
}

double CCalculator::GetFnResult(std::string const& fnIdentifier) const
{
    double result;
    auto fns = m_repository.GetFunctions();
    auto fn = fns.find(fnIdentifier);
    if (fn->second.isTwoIdentifier)
    {
        double firstOperandValue = m_repository.IsVar(fn->second.firstOperand) ? m_repository.GetValueVar(fn->second.firstOperand) :
            GetFnResult(fn->second.firstOperand);
        double secondOperandValue = m_repository.IsVar(fn->second.secondOperand) ? m_repository.GetValueVar(fn->second.secondOperand) :
            GetFnResult(fn->second.secondOperand);
        result = CalculationValue(firstOperandValue, secondOperandValue, fn->second.operation);
    }
    else 
    {
        result = m_repository.IsVar(fn->second.firstOperand) ? m_repository.GetValueVar(fn->second.firstOperand) :
            GetFnResult(fn->second.firstOperand);
    }

    return result;
}

RuntimeError CCalculator::DefineFunction(std::string const& functionIdentifier, FunctionRelease const& functionRelease)
{
    RuntimeError wasError = RuntimeError::NO_ERRORS;
    if (CheckIdentifier(functionIdentifier) && !m_repository.IsIdentifierDeclared(functionIdentifier))
    {
        if (functionRelease.isTwoIdentifier)
        {
            bool isDeclared = m_repository.IsIdentifierDeclared(functionRelease.firstOperand) &&
                m_repository.IsIdentifierDeclared(functionRelease.secondOperand);
            if (isDeclared)
            {
                m_repository.AddFunction(functionIdentifier, functionRelease);
            }
        }
        else if (m_repository.IsIdentifierDeclared(functionRelease.firstOperand))
        {
            m_repository.AddFunction(functionIdentifier, functionRelease);
        }
    }
    else if (m_repository.IsIdentifierDeclared(functionIdentifier))
    {
        wasError = RuntimeError::THIS_IDENTIFIER_ALREADY_DECLARED;
    }
    else
    {
        wasError = RuntimeError::INCORRECTLY_IDENTIFIER;
    }
    return wasError;
}