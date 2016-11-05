#pragma once
#include "stdafx.h"

struct Color
{
    uint32_t R;
    uint32_t G;
    uint32_t B;
};
bool ConvertHexInRGBColor(std::string const& HexColor, Color & RGBColor);
