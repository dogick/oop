#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(Point firstVertex, Point secondVertex, Point thirdVertex, Color const& outlineColor, Color const& fillColor)
    :m_fillColor(fillColor),
    m_outlineColor(outlineColor)
{
    m_vertices.push_back(std::make_shared<CPoint>(firstVertex));
    m_vertices.push_back(std::make_shared<CPoint>(secondVertex));
    m_vertices.push_back(std::make_shared<CPoint>(thirdVertex));
}

std::string CTriangle::GetOutlineColor() const
{
    return "";
};

std::string CTriangle::GetFillColor() const
{
    return "";
};

std::shared_ptr<CPoint> const& CTriangle::GetVertex1() const
{
    return m_vertices[0];
}

std::shared_ptr<CPoint> const& CTriangle::GetVertex2() const
{
    return m_vertices[1];
}

std::shared_ptr<CPoint> const& CTriangle::GetVertex3() const
{
    return m_vertices[2];
}

float CTriangle::GetArea() const
{
    float semiperimeter = GetPerimeter() / 2;
    return std::sqrt(semiperimeter*(semiperimeter - GetSideLength(m_vertices[0], m_vertices[1]))*
        (semiperimeter - GetSideLength(m_vertices[1], m_vertices[2]))*
        (semiperimeter - GetSideLength(m_vertices[2], m_vertices[0]))
    );
};

float CTriangle::GetSideLength(std::shared_ptr<CPoint> firstVertex, std::shared_ptr<CPoint> secondVertex) const
{
    float dx = firstVertex->GetPoint().x - secondVertex->GetPoint().x;
    float dy = firstVertex->GetPoint().y - secondVertex->GetPoint().y;
    return std::hypot(dx, dy);
};

float CTriangle::GetPerimeter() const
{
    return GetSideLength(m_vertices[0], m_vertices[1]) +
        GetSideLength(m_vertices[1], m_vertices[2]) +
        GetSideLength(m_vertices[2], m_vertices[0]);
};

std::string CTriangle::ToString() const
{
    std::ostringstream strm;
    strm << "Triangle: "
        << "  S = " << GetArea()
        << "  P = " << GetPerimeter()
        << "  ColorOutline = " << GetOutlineColor()
        << "  FillColor = " << GetFillColor();
    return strm.str();
};

void CTriangle::Draw(ICanvas & canvas) const
{
    canvas.DrawPolygon(m_vertices, m_outlineColor, m_fillColor);
}