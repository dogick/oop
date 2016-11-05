#include "stdafx.h"
#include "Rectangle.h"

CRectangle::CRectangle(Point leftTop, double height, double width, std::string const& outlineColor, std::string const& fillColor)
    :m_leftTop(std::make_shared<CPoint>(leftTop)),
    m_height(height),
    m_width(width),
    m_fillColor(fillColor),
    m_outlineColor(outlineColor)
{
    m_rightBottom = std::make_shared<CPoint>(CPoint({ leftTop.x + width, leftTop.y + height }));
}

double CRectangle::GetWidth() const
{
    return m_width;
};

double CRectangle::GetHeight() const
{
    return m_height;
};


std::shared_ptr<CPoint> const& CRectangle::GetLeftTop() const
{
    return m_leftTop;
}

std::shared_ptr<CPoint> const& CRectangle::GetRightBottom() const
{
    return m_rightBottom;
}

std::string CRectangle::GetOutlineColor() const
{
    return m_outlineColor;
};

std::string CRectangle::GetFillColor() const
{
    return m_fillColor;
};

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
        << "<" << m_leftTop->GetPoint().x << ", " << m_leftTop->GetPoint().y << ">"
        << "  S = " << GetArea()
        << "  P = " << GetPerimeter()
        << "  ColorOutline = " << GetOutlineColor()
        << "  FillColor = " << GetFillColor();
    return strm.str();
};

