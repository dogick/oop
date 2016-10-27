#include "stdafx.h"
#include "Variables.h"

Vars CVariables::GetVars() const
{
    return m_vars;
}

bool CVariables::IsIdentifierDeclared(std::string const& identifier) const
{
    return m_vars.find(identifier) != m_vars.end();
}

void CVariables::AddIdentifier(std::string const& identifier) //добавление идентификатора
{
    m_vars.emplace(identifier, NAN);
}

void CVariables::SetValue(std::string const& identifier, double value) //добавление идентификатора
{
    auto var = m_vars.find(identifier);
    var->second = value;
}