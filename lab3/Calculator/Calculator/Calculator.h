#pragma once
#include "stdafx.h"
#include "Variables.h"

enum class ReturnCode
{
    NO_ERRORS,
    INCORRECTLY_IDENTIFIER,
    THIS_IDENTIFIER_ALREADY_DECLARED,
    INCORRECT_DATA,
    //incorrect data
};

class CCalculator
{
public:
    Vars GetVariables()const;

    bool CheckIdentifier(std::string const& identifier) const;
    bool IsDigit(char ch) const;
    ReturnCode DefineVar(std::string const& identifier);
    void AssignValue(std::string const& identifier, double value);
    void AssignIdentifier(std::string const& firstIdentifier, std::string const& secondIdentifier);
private:
    CVariables m_variables;
};