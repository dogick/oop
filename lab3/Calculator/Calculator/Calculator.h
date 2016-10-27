#pragma once
#include "stdafx.h"
#include "Variables.h"

enum class ReturnCode
{
    NO_ERRORS,
    INCORRECTLY_IDENTIFIER,
    THIS_IDENTIFIER_ALREADY_DECLARED,
};

class CCalculator
{
public:
    ReturnCode DefineVar(std::string const& identifier);
private:
    CVariables m_variables;
};