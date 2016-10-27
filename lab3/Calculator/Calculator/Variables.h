#pragma once

typedef std::map<std::string, double> Vars;

class CVariables
{
public:
    Vars GetVars() const;
    bool IsIdentifierDeclared(std::string const& identifier) const;
    void AddIdentifier(std::string const& identifier);
    void SetValue(std::string const& identifier, double value);
private:
    Vars m_vars;
};