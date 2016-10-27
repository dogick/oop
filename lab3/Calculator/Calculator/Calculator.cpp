#include "stdafx.h"
#include "Calculator.h"

ReturnCode CCalculator::DefineVar(std::string const& identifier)
{
    ReturnCode returnCode = ReturnCode::NO_ERRORS;
    bool isIdentifier = m_variables.CheckIdentifier(identifier);
    bool isIdentifierDeclared = m_variables.IsIdentifierDeclared(identifier);
    if (!identifier.empty() && isIdentifier && !isIdentifierDeclared)
    {
        m_variables.AddIdentifier(identifier);
    }
    else if (!isIdentifier)
    {
        returnCode = ReturnCode::INCORRECTLY_IDENTIFIER;
    }
    else if (isIdentifierDeclared)
    {
        returnCode = ReturnCode::THIS_IDENTIFIER_ALREADY_DECLARED;
    }
    return returnCode;
}