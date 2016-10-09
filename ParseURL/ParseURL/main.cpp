#include "stdafx.h"
#include "ParseURL.h"

using namespace std;

int main(int argc, char *argv[])
{
	Parse parse;
	std::string url;
	cin >> url;
	cout << url << "\n";
	if (ParseURL(url, parse))
	{
		OutputParseURL(parse);
	}
	else
	{
		std::cout << "Invalid URL!!!\n";
	}
	return 0;
}