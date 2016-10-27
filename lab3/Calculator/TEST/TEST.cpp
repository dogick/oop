// TrimBlanksTests.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "../Calculator/Calculator.h"
#include <boost/function.hpp>

struct CCalculatorFixture
{
    CCalculator calculator;
};

BOOST_FIXTURE_TEST_SUITE(Calculator, CCalculatorFixture)
    BOOST_AUTO_TEST_CASE(can_determine_the_identifier)
    {
        BOOST_CHECK(calculator.DefineVar("x") == ReturnCode::NO_ERRORS);
    }

    BOOST_AUTO_TEST_CASE(identifier_can_not_start_with_a_digit)
    {
        BOOST_CHECK(calculator.DefineVar("2size") == ReturnCode::INCORRECTLY_IDENTIFIER);
    }

    BOOST_AUTO_TEST_CASE(identifier_can_not_be_empty)
    {
        BOOST_CHECK(calculator.DefineVar("") == ReturnCode::INCORRECTLY_IDENTIFIER);
    }

    BOOST_AUTO_TEST_CASE(identifier_can_not_be_re_declared)
    {
        BOOST_CHECK(calculator.DefineVar("position") == ReturnCode::NO_ERRORS);
        BOOST_CHECK(calculator.DefineVar("position") == ReturnCode::THIS_IDENTIFIER_ALREADY_DECLARED);
    }

    BOOST_AUTO_TEST_CASE(identifier_can_only_be_letters_of_the_english_alphabet)
    {
        BOOST_CHECK(calculator.DefineVar("позиция") == ReturnCode::INCORRECTLY_IDENTIFIER);
        BOOST_CHECK(calculator.DefineVar("position") == ReturnCode::NO_ERRORS);
    }

    BOOST_AUTO_TEST_CASE(in_the_identifier_can_be_an_underscore)
    {
        BOOST_CHECK(calculator.DefineVar("rectangle_position") == ReturnCode::NO_ERRORS);
    }

    BOOST_AUTO_TEST_CASE(in_the_identifier_may_not_be_other_special_characters)
    {
        BOOST_CHECK(calculator.DefineVar("rectangle+position") == ReturnCode::INCORRECTLY_IDENTIFIER);
    }

    BOOST_AUTO_TEST_CASE(after_the_declaration_of_its_identifier_value_equal_to_nan)
    {
        std::string identifier = "position";
        BOOST_CHECK(calculator.DefineVar(identifier) == ReturnCode::NO_ERRORS);
        BOOST_CHECK(isnan(calculator.GetValueVar(identifier)));
    }

    BOOST_AUTO_TEST_CASE(can_assign_a_variable_value)
    {
        std::string identifier = "position";
        double value = 10.3;
        BOOST_CHECK(calculator.DefineVar(identifier) == ReturnCode::NO_ERRORS);
        calculator.AssignValue(identifier, 10.3);
        BOOST_CHECK(calculator.GetValueVar(identifier) == value);
    }

BOOST_AUTO_TEST_SUITE_END()
