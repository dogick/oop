#include "stdafx.h"
#include "LineSegment.h"


CLineSegment::CLineSegment(Point startPoint, Point endPoint, Color const& outlineColor)
    :m_startPoint(std::make_shared<CPoint>(startPoint)),
    m_endPoint(std::make_shared<CPoint>(endPoint)),
    m_outlineColor(outlineColor)
{
}

float CLineSegment::GetArea() const
{
    return 0;
};

std::string CLineSegment::GetOutlineColor() const
{
    return "";
};

std::shared_ptr<CPoint> const& CLineSegment::GetStartPoint() const
{
    return m_startPoint;
}

std::shared_ptr<CPoint> const& CLineSegment::GetEndPoint() const
{
    return m_endPoint;
}

float CLineSegment::GetPerimeter() const
{
    float dx = m_startPoint->GetPoint().x - m_endPoint->GetPoint().x;
    float dy = m_startPoint->GetPoint().y - m_endPoint->GetPoint().y;
    return std::hypot(dx, dy);
};

std::string CLineSegment::ToString() const
{
    std::ostringstream strm;
    strm << "Line: "
        << "<" << m_startPoint->GetPoint().x << ", " << m_startPoint->GetPoint().y << ">"
        << "<" << m_endPoint->GetPoint().x << ", " << m_endPoint->GetPoint().x << ">"
        << "  S = " << GetArea()
        << "  P = " << GetPerimeter()
        << "  ColorOutline = " << GetOutlineColor();
    return strm.str();
};

void CLineSegment::Draw(ICanvas & canvas) const
{
    canvas.DrawLine(m_startPoint, m_endPoint, m_outlineColor);
}