#include "stdafx.h"
#include "Rectangle.h"

CRectangle::CRectangle(Point leftTop, float height, float width, Color const& outlineColor, Color const& fillColor)
    :m_leftTop(std::make_shared<CPoint>(leftTop)),
    m_height(height),
    m_width(width),
    m_fillColor(fillColor),
    m_outlineColor(outlineColor)
{
    m_vertices.push_back(m_leftTop);
    m_vertices.push_back(std::make_shared<CPoint>(CPoint({ leftTop.x + width, leftTop.y })));
    m_vertices.push_back(std::make_shared<CPoint>(CPoint({ leftTop.x + width, leftTop.y + height })));
    m_vertices.push_back(std::make_shared<CPoint>(CPoint({ leftTop.x, leftTop.y + height })));
}

float CRectangle::GetWidth() const
{
    return m_width;
};

float CRectangle::GetHeight() const
{
    return m_height;
};


std::shared_ptr<CPoint> const& CRectangle::GetLeftTop() const
{
    return m_leftTop;
}

std::shared_ptr<CPoint> const& CRectangle::GetRightBottom() const
{
    return m_vertices[2];
}

std::string CRectangle::GetOutlineColor() const
{
    return "";
};

std::string CRectangle::GetFillColor() const
{
    return "";
};

float CRectangle::GetArea() const
{
    return m_width * m_height;
};

float CRectangle::GetPerimeter() const
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

void CRectangle::Draw(ICanvas & canvas) const
{
    canvas.DrawPolygon(m_vertices, m_outlineColor, m_fillColor);
}