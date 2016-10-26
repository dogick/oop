#pragma once
#include "stdafx.h"

typedef std::map<std::string, double> Var;

enum class ReturnCode
{
	NO_ERRORS,
	NOT_FOUND_IDENTIFIER,
	INCORRECT_IDENTIFIER,
	IDENTIFIER_ALREADY_HAS,
	IDENTIFIER_NOT_FOUND,
	INCORRECT_PHRASE_ENTERED,
	//Identifier not found
};

class CCalculator
{
public:
	ReturnCode DefineVar(std::string const& identifier);
	double GetValueVar(std::string const& identifier) const;
	bool IsVar(std::string const& identifier) const;
	bool SetValueVar(std::string const& identifier, double value);
	Var GetVars();
	ReturnCode AssignVar(std::string const& firstIdentifier, std::string const& secondIdentifier);
	void ChangeValue(std::string const& firstIdentifier, std::string const& secondIdentifier);
private:
	Var m_var;
};
