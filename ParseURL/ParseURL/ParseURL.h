#pragma once
#include "stdafx.h"
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>  

static const int MAX_NUMBER_PROTOCOL = 65535;
static const int MIN_NUMBER_PROTOCOL = 1;

enum class Protocol
{
	HTTP = 80,
	HTTPS = 443,
	FTP = 21
};

struct Parse
{
	Protocol protocol;
	int port;
	std::string host;
	std::string document;
};

Protocol GetProtocol(std::string protocol);
bool ParseURL(std::string const& url, Parse &parse);
void OutputParseURL(Parse const& parse);