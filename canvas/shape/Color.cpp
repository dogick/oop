#include "stdafx.h"
#include "Color.h"

bool ConvertHexInRGBColor(std::string const& HEXColor, Color & RGBColor)
{
    bool wasError = false;
    if (HEXColor[0] != '#')
    {
        std::cout << "ERROR: not found the special symbol '#'\n";
        return true;
    }
    try
    {
        RGBColor.Red = std::stoi(HEXColor.substr(1, 2), 0, 16);
        RGBColor.Green = std::stoi(HEXColor.substr(3, 2), 0, 16);
        RGBColor.Blue = std::stoi(HEXColor.substr(5, 2), 0, 16);
    }
    catch (std::exception const& e)
    {
        std::cout << e.what() << std::endl;
        wasError = true;
    }
    return wasError;
}