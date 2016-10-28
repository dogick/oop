#include "stdafx.h"
#include "StorageVar.h"

Vars CStorageVar::GetVars() const
{
    return m_vars;
}

double CStorageVar::GetValueVar(std::string const& identifier) const
{
    return m_vars.find(identifier)->second;
}

bool CStorageVar::IsIdentifierDeclared(std::string const& identifier) const
{
    return m_vars.find(identifier) != m_vars.end();
}

void CStorageVar::AddIdentifier(std::string const& identifier)
{
    m_vars.emplace(identifier, NAN);
}

void CStorageVar::SetValue(std::string const& identifier, double value)
{
    auto var = m_vars.find(identifier);
    var->second = value;
}

