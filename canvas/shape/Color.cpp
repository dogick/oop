#include "stdafx.h"
#include "Color.h"

bool ConvertHexInRGBColor(std::string const& HEXColor, Color & RGBColor)
{
    bool wasError = false;
    try
    {
        RGBColor.R = std::stoi(HEXColor.substr(1, 2), 0, 16);
        RGBColor.G = std::stoi(HEXColor.substr(3, 2), 0, 16);
        RGBColor.B = std::stoi(HEXColor.substr(5, 2), 0, 16);
    }
    catch (std::exception const& e)
    {
        std::cout << e.what() << std::endl;
        wasError = true;
    }
    return wasError;
}