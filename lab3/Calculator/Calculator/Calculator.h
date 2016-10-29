#pragma once
#include "stdafx.h"
#include "Repository.h"
enum class RuntimeError
{
    NO_ERRORS,
    INCORRECTLY_IDENTIFIER,
    THIS_IDENTIFIER_ALREADY_DECLARED,
    INCORRECT_DATA,
    SECOND_IDENTIFIER_IS_NOT_DIFINE,
    IDENTIFIER_IS_NOT_DIFINE,
    //incorrect data
};

class CCalculator
{
public:
    CRepository GetRepository() const;

    bool CheckIdentifier(std::string const& identifier) const;
    bool IsDigit(char ch) const;
    RuntimeError DefineVar(std::string const& identifier);
    RuntimeError AssignValue(std::string const& identifier, double value);
    RuntimeError AssignIdentifier(std::string const& firstIdentifier, std::string const& secondIdentifier);
private:
    CRepository m_repository;
};