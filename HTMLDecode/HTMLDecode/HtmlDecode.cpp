#include "stdafx.h"
#include "HtmlDecode.h"
#include <map>

using namespace std;

typedef map<string, string> Html;

string FindAndReplace(string const& inputString, string const& search, string const& replace)
{
	string result;
	size_t startSearchPosition = 0;
	size_t positionReplacedWords = inputString.find(search);
	while (positionReplacedWords != string::npos)
	{
		result.append(inputString, startSearchPosition, positionReplacedWords - startSearchPosition);
		result += replace;
		startSearchPosition = positionReplacedWords + search.length();
		positionReplacedWords = inputString.find(search, startSearchPosition);
	}
	result.append(inputString, startSearchPosition, inputString.length() - startSearchPosition);
	return result;
}

string HtmlDecode(string const& encodedText)
{
	Html htmlCode = {
		{ "\"", "&quot;" },
		{ "\'", "&apos;" },
		{ "<", "&lt;" },
		{ ">", "&gt;" },
		{ "&", "&amp;" }
	};
	string stringDecode = encodedText;
	for (auto ñode : htmlCode)
	{
		string result = FindAndReplace(stringDecode, ñode.second, ñode.first);
		stringDecode = result;
	}
	return stringDecode;
}
