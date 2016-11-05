#pragma once
#include "stdafx.h"

struct Color
{
    unsigned R;
    unsigned G;
    unsigned B;
};
bool ConvertHexInRGBColor(std::string const& HexColor, Color & RGBColor);
