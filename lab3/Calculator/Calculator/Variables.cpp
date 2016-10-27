#include "stdafx.h"
#include "Variables.h"

bool CVariables::IsIdentifierDeclared(std::string const& identifier) const
{
    return m_vars.find(identifier) != m_vars.end();
}

bool CVariables::CheckIdentifier(std::string const& identifier) const
{
    bool wasError = false;
    if (identifier.empty() && !isdigit(identifier[0]))
    {
        for (char symbol : identifier)
        {
            if (!(isalpha(symbol) || (symbol == '_') || isdigit(symbol)))
            {
                wasError = true;
            }
        }
    }
    else
    {
        wasError = true;
    }
    return wasError;
}

void CVariables::AddIdentifier(std::string const& identifier) //создание переменного
{
    m_vars.emplace(identifier, NAN);
}