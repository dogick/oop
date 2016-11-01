#include "stdafx.h"
#include "Rectangle.h"
#include "SolidShape.h"

CRectangle::CRectangle(Point vertex, double height, double width, std::string const& colorOutlines, std::string const& fillColor)
    :ISolidShape(colorOutlines, fillColor),
    m_vertex(colorOutlines, vertex),
    m_height(height),
    m_width(width)
{
}

double CRectangle::GetArea() const
{
    return m_width * m_height;
};

double CRectangle::GetPerimeter() const
{
    return 2 * (m_width + m_height);
};

std::string CRectangle::ToString() const
{
    std::ostringstream strm;
    strm << "Rectangle: "
        << "<" << m_vertex.GetPoint().x << ", " << m_vertex.GetPoint().y << ">"
        << "  S = " << GetArea()
        << "  P = " << GetPerimeter()
        << "  ColorOutline = " << GetColorOutlines()
        << "  FillColor = " << GetFillColor();
    return strm.str();
};

