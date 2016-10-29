#include "stdafx.h"
#include "Repository.h"

Vars CRepository::GetVars() const
{
    return m_vars;
}

double CRepository::GetValueVar(std::string const& identifier) const
{
    return m_vars.find(identifier)->second;
}

bool CRepository::IsIdentifierDeclared(std::string const& identifier) const
{
    return m_vars.find(identifier) != m_vars.end();
}

void CRepository::AddIdentifier(std::string const& identifier)
{
    m_vars.emplace(identifier, NAN);
}

void CRepository::SetValue(std::string const& identifier, double value)
{
    auto var = m_vars.find(identifier);
    var->second = value;
}

