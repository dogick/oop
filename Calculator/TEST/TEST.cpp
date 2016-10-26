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
    BOOST_AUTO_TEST_CASE(define_var_x)
    {
	    BOOST_CHECK(calculator.DefineVar("x"));
    }

BOOST_AUTO_TEST_SUITE_END()
