#include "stdafx.h"
#include "Circle.h"



CCircle::CCircle(Point center, double radius, std::string const& outlineColor, std::string const& fillColor)
    :m_center(std::make_shared<CPoint>(center)),
    m_radius(radius),
    m_outlineColor(outlineColor),
    m_fillColor(fillColor)
{
}

std::shared_ptr<CPoint> const& CCircle::GetCenter() const
{
    return m_center;
}

double CCircle::GetRadius() const
{
    return m_radius;
}

std::string CCircle::GetOutlineColor() const
{
    return m_outlineColor;
};

std::string CCircle::GetFillColor() const
{
    return m_fillColor;
};


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
        << "<" << m_center->GetPoint().x << ", " << m_center->GetPoint().y << ">"
        << "  R = " << m_radius
        << "  S = " << GetArea()
        << "  P = " << GetPerimeter()
        << "  ColorOutline = " << GetOutlineColor()
        << "  FillColor = " << GetFillColor();
    return strm.str();
};

