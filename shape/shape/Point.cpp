#include "stdafx.h"
#include "Point.h"

CPoint::CPoint(std::string const& colorOutline, Point point)
    :IShape(colorOutline),
    m_point(point) 
{
}

Point CPoint::GetPoint() const
{
    return m_point;
}
double CPoint::GetArea() const 
{
    return 0; 
};

double CPoint::GetPerimeter() const 
{ 
    return 0;
};

std::string CPoint::ToString() const
{
    std::ostringstream strm;
    strm << "Point: "
        << "<" << m_point.x << ", " << m_point.y << ">"
        << "  S = " << GetArea()
        << "  P = " << GetPerimeter()
        << "  ColorOutline = " << GetColorOutlines();
    return strm.str();
};