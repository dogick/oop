#pragma once
#include <boost/noncopyable.hpp>
#include "Calculator.h"

// ???????????? ?? boost::noncopyable - ????? ?????? ????????? ??????????? ? ???????????? ??????????? ??????
class CControl : boost::noncopyable
{
public:
    CControl(CCalculator & calculator, std::istream & input, std::ostream & output);
    bool HandleCommand();

    // ??????????? ?? ?????????????? ??????????? ? ???, ??? ?? ?? ?????? ????????????? ???????? ????????????
    // CRemoteControl& operator=(const CRemoteControl &) = delete;
private:
    bool DefineVar(std::istream & args);
    bool PrintError(ReturnCode const& code);
private:
    typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;

    CCalculator & m_calculator;
    std::istream & m_input;
    std::ostream & m_output;

    const ActionMap m_actionMap;
};