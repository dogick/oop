#include "stdafx.h"
#include "SolidShape.h"

ISolidShape::ISolidShape(std::string const& colorOutlines, std::string const& fillColor)
    :IShape(colorOutlines),
    m_fillColor(fillColor)
{
}

std::string ISolidShape::GetFillColor() const
{
    return m_fillColor;
}