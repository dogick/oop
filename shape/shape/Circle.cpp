#include "stdafx.h"
#include "Circle.h"
#include "SolidShape.h"

CCircle::CCircle(Point position, double radius, std::string const& colorOutlines, std::string const& fillColor)
    :ISolidShape(colorOutlines, fillColor),
    m_position(position),
    m_radius(radius)
{
}

double CCircle::GetArea() const
{
    return M_PI * std::pow(m_radius, 2);
};

double CCircle::GetPerimeter() const
{
    return 2 * M_PI * m_radius;
};

std::string CCircle::ToString() const
{
    std::ostringstream strm;
    strm << "Circle: "
        << "<" << m_position.x << ", " << m_position.y << ">"
        << "  R = " << m_radius
        << "  S = " << GetArea()
        << "  P = " << GetPerimeter()
        << "  ColorOutline = " << GetColorOutlines()
        << "  FillColor = " << GetFillColor();
    return strm.str();
};

