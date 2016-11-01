#pragma once
#include "stdafx.h"

struct Color
{
    unsigned R;
    unsigned G;
    unsigned B;
};
bool ConvertHexInRGB(std::string const& HEXColor, Color & RGBColor);
