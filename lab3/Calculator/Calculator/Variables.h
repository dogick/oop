#pragma once

typedef std::map<std::string, double> Vars;

class CVariables
{
public:
    bool IsIdentifierDeclared(std::string const& identifier) const;
    bool CheckIdentifier(std::string const& identifier) const;
    void AddIdentifier(std::string const& identifier);
private:
    Vars m_vars;
};