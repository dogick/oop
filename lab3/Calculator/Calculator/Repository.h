#pragma once
#include "stdafx.h"

enum class Operation
{
    ADD,
    SUB,
    DIV,
    MUL
};

struct FunctionRelease
{
    boost::optional<std::string> firstArgument;
    boost::optional<std::string> secondArgument;
    boost::optional<Operation> action;
};

typedef std::map<std::string, double> Vars;
typedef std::map<std::string, FunctionRelease> Function;

class CRepository
{
public:
    Vars GetVars() const;
    double GetValueVar(std::string const& identifier) const;
    bool IsIdentifierDeclared(std::string const& identifier) const;
    void AddIdentifier(std::string const& identifier);
    void SetValue(std::string const& identifier, double value);
private:
    Vars m_vars;
    Function m_function;
};
