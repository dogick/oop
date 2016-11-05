#include "stdafx.h"
#include "Triangle.h"
#include "SolidShape.h"
#include "Point.h"
CTriangle::CTriangle(Point firstVertex, Point secondVertex, Point thirdVertex, std::string const& outlineColor, std::string const& fillColor)
    :m_fillColor(fillColor),
    m_outlineColor(outlineColor)
{
    m_vertices.push_back(std::make_shared<CPoint>(CPoint(firstVertex)));
    m_vertices.push_back(std::make_shared<CPoint>(CPoint(secondVertex)));
    m_vertices.push_back(std::make_shared<CPoint>(CPoint(thirdVertex)));
}

std::string CTriangle::GetOutlineColor() const
{
    return m_outlineColor;
};

std::string CTriangle::GetFillColor() const
{
    return m_fillColor;
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

double CTriangle::GetArea() const
{
    double semiperimeter = GetPerimeter() / 2;
    return std::sqrt(semiperimeter*(semiperimeter - GetLengthLine(m_vertices[0], m_vertices[1]))*
        (semiperimeter - GetLengthLine(m_vertices[1], m_vertices[2]))*
        (semiperimeter - GetLengthLine(m_vertices[2], m_vertices[0]))
    );
};

double CTriangle::GetLengthLine(std::shared_ptr<CPoint> firstVertex, std::shared_ptr<CPoint> secondVertex) const
{
    double dx = firstVertex->GetPoint().x - secondVertex->GetPoint().x;
    double dy = firstVertex->GetPoint().y - secondVertex->GetPoint().y;
    return std::hypot(dx, dy);
};

double CTriangle::GetPerimeter() const
{
    return GetLengthLine(m_vertices[0], m_vertices[1]) +
        GetLengthLine(m_vertices[1], m_vertices[2]) +
        GetLengthLine(m_vertices[2], m_vertices[0]);
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

