#include "stdafx.h"
#include "Circle.h"



CCircle::CCircle(Point center, float radius, float outlineThickness, Color const& outlineColor, Color const& fillColor)
    :m_center(std::make_shared<CPoint>(center)),
    m_radius(radius),
    m_outlineThickness(outlineThickness),
    m_outlineColor(outlineColor),
    m_fillColor(fillColor)
{
}

std::shared_ptr<CPoint> const& CCircle::GetCenter() const
{
    return m_center;
}

float CCircle::GetRadius() const
{
    return m_radius;
}

std::string CCircle::GetOutlineColor() const
{
    return "";
};

std::string CCircle::GetFillColor() const
{
    return "";
};


float CCircle::GetArea() const
{
    return float(M_PI) * std::pow(m_radius, 2);
};

float CCircle::GetPerimeter() const
{
    return 2 * float(M_PI) * m_radius;
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

void CCircle::Draw(ICanvas & canvas) const
{
    canvas.FillCircle(m_center, m_radius, m_fillColor);
    canvas.DrawCircle(m_center, m_radius, m_outlineThickness, m_outlineColor);
}
