#include "stdafx.h"
#include "Point.h"
#include "LineSegment.h"
#include "Color.h"
#include "Control.h"

using namespace std;

void main()
{
    CRemoteControl remoteControl(cin, cout);
    while (!cin.eof() && !cin.fail())
    {
        if (!remoteControl.HandleCommand())
        {
            cout << "Unknown command!" << endl;
        }
    }
}