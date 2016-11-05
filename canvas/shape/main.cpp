#include "stdafx.h"
#include "Color.h"
#include "Const.h"
#include "Canvas.h"
#include "Control.h"

using namespace std;
#include <SFML\Graphics.hpp>
void main()
{
    std::shared_ptr<CCanvas> canvas = std::make_shared<CCanvas>(WINDOW_WIDTH, WINDOW_HEIGHT);
    canvas->Info();
    CRemoteControl remoteControl(cin, cout, canvas);
    while (!cin.eof() && !cin.fail())
    {
        if (!remoteControl.HandleCommand())
        {
            cout << "Unknown command!" << endl;
        }
    }
    canvas->Info();
    canvas->EnterMainLoop();
}