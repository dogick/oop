// TrimBlanksTests.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "../ParseURL/ParseURL.h"

BOOST_AUTO_TEST_SUITE(ParseURL_function)
	BOOST_AUTO_TEST_CASE(search_in_an_empty_dictionary)
	{
		std::string url = "https://vk.com/dolbnorm";
		Parse parse;
		BOOST_CHECK(ParseURL(url, parse) == true);
	}

BOOST_AUTO_TEST_SUITE_END()
