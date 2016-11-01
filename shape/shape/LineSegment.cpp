#include "stdafx.h"
#include "LineSegment.h"
#include "Point.h"

CLineSegment::CLineSegment(Point startPoint, Point endPoint, std::string const& colorOutlines)
    :IShape(colorOutlines),
    m_startPoint(CPoint(colorOutlines, startPoint)),
    m_endPoint(CPoint(colorOutlines, endPoint))
{
}

double CLineSegment::GetArea() const
{
    return 0;
};

double CLineSegment::GetPerimeter() const
{
    double dx = m_startPoint.GetPoint().x - m_endPoint.GetPoint().x;
    double dy = m_startPoint.GetPoint().y - m_endPoint.GetPoint().y;
    return std::hypot(dx, dy);
};

std::string CLineSegment::ToString() const
{
    std::ostringstream strm;
    strm << "Line: "
        << "<" << m_startPoint.GetPoint().x << ", " << m_startPoint.GetPoint().y << ">"
        << "<" << m_endPoint.GetPoint().x << ", " << m_endPoint.GetPoint().x << ">"
        << "  S = " << GetArea()
        << "  P = " << GetPerimeter()
        << "  ColorOutline = " << GetColorOutlines();
    return strm.str();
};

