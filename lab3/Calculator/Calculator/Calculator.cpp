#include "stdafx.h"
#include "Calculator.h"

/*Var CCalculator::GetVars()
{
	return m_var;
}*/

bool IsDigitTheFirstElement(std::string const& identifier)
{
	return isdigit(identifier[0]) ? true : false; // isdigit не возвращает булево значение
}

Var CCalculator::GetVars()
{
	return m_var;
}

bool CCalculator::IsVar(std::string const& identifier) const
{
	auto var = m_var.find(identifier);
	return var != m_var.end();
}

ReturnCode CCalculator::DefineVar(std::string const& identifier) 
{
	ReturnCode wasError = ReturnCode::NO_ERRORS;
	auto var = m_var.find(identifier);
	if (!identifier.empty() && (var == m_var.end()) && !IsDigitTheFirstElement(identifier))
	{
		m_var.emplace(identifier, NAN);
	}
	else if (IsDigitTheFirstElement(identifier))
	{
		wasError = ReturnCode::INCORRECT_IDENTIFIER;
	}
	else if (var != m_var.end())
	{
		wasError = ReturnCode::IDENTIFIER_ALREADY_HAS;
	}
	return wasError;
}

void CCalculator::ChangeValue(std::string const& firstIdentifier, std::string const& secondIdentifier)
{
	auto secondIdentifierValue = m_var.find(secondIdentifier);
	auto firstIdentifierValue = m_var.find(firstIdentifier);
	firstIdentifierValue->second = secondIdentifierValue->second;
}

ReturnCode CCalculator::AssignVar(std::string const& firstIdentifier, std::string const& secondIdentifier)
{
	ReturnCode wasError = ReturnCode::NO_ERRORS;
	if (IsVar(firstIdentifier) && IsVar(secondIdentifier))
	{
		ChangeValue(firstIdentifier, secondIdentifier);
	}
	else if (!IsVar(firstIdentifier) && IsVar(secondIdentifier))
	{
		DefineVar(firstIdentifier);
		ChangeValue(firstIdentifier, secondIdentifier);
	}
	else
	{
		wasError = ReturnCode::IDENTIFIER_NOT_FOUND;
	}
	return wasError;
}

bool CCalculator::SetValueVar(std::string const& identifier, double value)
{
	bool isSetValueVar = true;
	if (IsVar(identifier))
	{
		auto var = m_var.find(identifier);
		var->second = value;
	}
	else
	{
		DefineVar(identifier);	
		auto var = m_var.find(identifier);
		var->second = value;
	}
	return isSetValueVar;
}

double CCalculator::GetValueVar(std::string const& identifier) const
{
	auto var = m_var.find(identifier);
	return var != m_var.end() ? var->second : NAN;
}
