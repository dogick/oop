#include "stdafx.h"
#include "HtmlDecode.h"

using namespace std;
int main()
{
	string encodedHtmlString;
	cin >> encodedHtmlString;
	string decodedHtmlString = HtmlDecode(encodedHtmlString);
	cout << decodedHtmlString << "\n";
	return 0;
}