// TrimBlanksTests.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "../ParseURL/ParseURL.h"

BOOST_AUTO_TEST_SUITE(ParseURL_function)
	BOOST_AUTO_TEST_CASE(check_empty_url)
	{
		std::string url = "";
		Parse parse;
		BOOST_CHECK(ParseURL(url, parse) == false);
	}

	BOOST_AUTO_TEST_CASE(check_url_https_vk_com_dolbnorm)
	{
		std::string url = "https://vk.com/dolbnorm";
		Parse parse;
		BOOST_CHECK(ParseURL(url, parse) == true);
	}
	BOOST_AUTO_TEST_CASE(check_port_url_https_vk_com_dolbnorm)
	{
		std::string url = "https://vk.com/dolbnorm";
		Parse parse;
		ParseURL(url, parse);
		BOOST_CHECK(parse.port == 443);
	}

	BOOST_AUTO_TEST_CASE(check_url_https_mysite_com)
	{
		std::string url = "http://www.mysite.com/docs/document1.html?page=30&lang=en#title";
		Parse parse;
		BOOST_CHECK(ParseURL(url, parse) == true);
	}
	BOOST_AUTO_TEST_CASE(check_port_url_https_mysite_com)
	{
		std::string url = "http://www.mysite.com/docs/document1.html?page=30&lang=en#title";
		Parse parse;
		ParseURL(url, parse);
		BOOST_CHECK(parse.port == 80);
	}

	BOOST_AUTO_TEST_CASE(check_document_url_https_mysite_com)
	{
		std::string url = "http://www.mysite.com/docs/document1.html?page=30&lang=en#title";
		Parse parse;
		ParseURL(url, parse);
		BOOST_CHECK(parse.document == "docs/document1.html?page=30&lang=en#title");
	}

	BOOST_AUTO_TEST_CASE(check_port_url_http_localhost_253)
	{
		std::string url = "http://www.localhost:253/page.php?name=vadim";
		Parse parse;
		ParseURL(url, parse);
		BOOST_CHECK(parse.port == 253);
	}

	BOOST_AUTO_TEST_CASE(check_url_http_localhost_65536)
	{
		std::string url = "http://www.localhost:65536/page.php?name=vadim";
		Parse parse;
		BOOST_CHECK(ParseURL(url, parse) == false);
	}

	BOOST_AUTO_TEST_CASE(check_url_localhost_65535)
	{
		std::string url = "www.localhost:65535/page.php?name=vadim";
		Parse parse;
		BOOST_CHECK(ParseURL(url, parse) == false);
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(GetProtocol_function)
	BOOST_AUTO_TEST_CASE(check_url_localhost_65535)
	{
		BOOST_CHECK(GetProtocol("ftp") == Protocol::FTP);
	}
BOOST_AUTO_TEST_SUITE_END()