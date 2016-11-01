#pragma once
#include "stdafx.h"
#include "Shape.h"

class ISolidShape : public IShape
{
public:
    ISolidShape(std::string const& colorOutlines, std::string const& fillColor);
    std::string GetFillColor() const;
private:
    std::string m_fillColor;
};