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
        BOOST_CHECK(calculator.DefineVar("x") == RuntimeError::NO_ERRORS);
    }

    BOOST_AUTO_TEST_CASE(identifier_can_not_start_with_a_digit)
    {
        BOOST_CHECK(calculator.DefineVar("2size") == RuntimeError::INCORRECTLY_IDENTIFIER);
    }

    BOOST_AUTO_TEST_CASE(identifier_can_not_be_empty)
    {
        BOOST_CHECK(calculator.DefineVar("") == RuntimeError::INCORRECTLY_IDENTIFIER);
    }

    BOOST_AUTO_TEST_CASE(identifier_can_not_be_re_declared)
    {
        BOOST_CHECK(calculator.DefineVar("position") == RuntimeError::NO_ERRORS);
        BOOST_CHECK(calculator.DefineVar("position") == RuntimeError::THIS_IDENTIFIER_ALREADY_DECLARED);
    }

    BOOST_AUTO_TEST_CASE(identifier_can_only_be_letters_of_the_english_alphabet)
    {
        BOOST_CHECK(calculator.DefineVar("позиция") == RuntimeError::INCORRECTLY_IDENTIFIER);
        BOOST_CHECK(calculator.DefineVar("position") == RuntimeError::NO_ERRORS);
    }

    BOOST_AUTO_TEST_CASE(in_the_identifier_can_be_an_underscore)
    {
        BOOST_CHECK(calculator.DefineVar("rectangle_position") == RuntimeError::NO_ERRORS);
    }

    BOOST_AUTO_TEST_CASE(in_the_identifier_may_not_be_other_special_characters)
    {
        BOOST_CHECK(calculator.DefineVar("rectangle+position") == RuntimeError::INCORRECTLY_IDENTIFIER);
    }

    BOOST_AUTO_TEST_CASE(after_the_declaration_of_its_identifier_value_equal_to_nan)
    {
        std::string identifier = "position";
        BOOST_CHECK(calculator.DefineVar(identifier) == RuntimeError::NO_ERRORS);
        BOOST_CHECK(isnan(calculator.GetRepository().GetValueVar(identifier)));
    }

    BOOST_AUTO_TEST_CASE(can_assign_a_variable_value)
    {
        std::string identifier = "position";
        double value = 10.3;
        BOOST_CHECK(calculator.DefineVar(identifier) == RuntimeError::NO_ERRORS);
        calculator.AssignValue(identifier, 10.3);
        BOOST_CHECK(calculator.GetRepository().GetValueVar(identifier) == value);
    }

    struct when_variables_are_define_ : CCalculatorFixture
    {
        when_variables_are_define_()
        {
            calculator.DefineVar("bodySize");
            calculator.AssignValue("bodySize", 10.2);
            calculator.DefineVar("spriteSize");
            calculator.AssignValue("spriteSize", 4.2);
        }
    };
    BOOST_FIXTURE_TEST_SUITE(when_variables_are_define, when_variables_are_define_)
        BOOST_AUTO_TEST_CASE(can_assign_an_identifier)
        {
            BOOST_CHECK(calculator.AssignIdentifier("bodySize", "spriteSize") == RuntimeError::NO_ERRORS);
            BOOST_CHECK(calculator.GetRepository().GetValueVar("bodySize") == calculator.GetRepository().GetValueVar("spriteSize"));
        }

        BOOST_AUTO_TEST_CASE(can_define_a_variable_if_the_identifier_wast_declared_previously)
        {
            BOOST_CHECK(calculator.AssignIdentifier("sizeX", "spriteSize") == RuntimeError::NO_ERRORS);
            BOOST_CHECK(calculator.GetRepository().GetValueVar("sizeX") == calculator.GetRepository().GetValueVar("spriteSize"));
        }

        BOOST_AUTO_TEST_CASE(can_override)
        {
            double value = 24.74;
            BOOST_CHECK(calculator.AssignValue("spriteSize", value) == RuntimeError::NO_ERRORS);
            BOOST_CHECK(calculator.GetRepository().GetValueVar("spriteSize") == 24.74);
        }
    BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
