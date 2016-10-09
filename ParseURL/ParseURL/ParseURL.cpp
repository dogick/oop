#include "ParseURL.h"

Protocol GetProtocol(std::string protocol)
{
	Protocol resultProtocol;
	boost::to_lower(protocol);
	if (protocol == "http")
	{
		resultProtocol = Protocol::HTTP;
	}
	else if (protocol == "https")
	{
		resultProtocol = Protocol::HTTPS;
	}
	else if (protocol == "ftp")
	{
		resultProtocol = Protocol::FTP;
	}
	return resultProtocol;
}

bool ParseURL(std::string const& url, Parse &parse)
{
	bool isValidURL = true;
	boost::regex regex("(http|https|ftp)://([^/ :]+):?([^/ ]*)/([^ ]*)", boost::regex::icase);
	boost::cmatch result;
	if (boost::regex_match(url.c_str(), result, regex))
	{
		parse.protocol = GetProtocol(std::string(result[1].first, result[1].second));
		parse.host = std::string(result[2].first, result[2].second);
		parse.port = atoi(std::string(result[3].first, result[3].second).c_str());
		if (parse.port == 0)
		{
			parse.port = static_cast<int>(parse.protocol);
		}
		isValidURL = (parse.port <= MAX_NUMBER_PROTOCOL) && (parse.port >= MIN_NUMBER_PROTOCOL);
		parse.document = std::string(result[4].first, result[4].second);
	}
	else
	{
		isValidURL = false;
	}
	return isValidURL;
}

void OutputParseURL(Parse const& parse)
{
	std::cout << "Host: " << parse.host << "\n";
	std::cout << "Port: " << parse.port << "\n";
	std::cout << "DOC: " << parse.document << "\n";
}
