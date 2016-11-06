#include "stdafx.h"
#include "Color.h"
#include "Const.h"
#include "Canvas.h"
#include "Control.h"

using namespace std;


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Invalid arguments count\n"
            << "Usage: shape.exe <input file>\n";
        return 1;
    }
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
    {
        cout << "Failed to open " << argv[1] << " for writing\n";
        return 1;
    }
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    std::shared_ptr<CCanvas> canvas = std::make_shared<CCanvas>(WINDOW_WIDTH, WINDOW_HEIGHT, settings);
    CRemoteControl remoteControl(inputFile, cout, canvas);
    while (!inputFile.eof() && !inputFile.fail())
    {
        if (!remoteControl.HandleCommand())
        {
            return 1;
        }
    }
    canvas->EnterMainLoop();
    return 0;
}