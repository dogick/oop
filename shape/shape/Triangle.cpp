#include "stdafx.h"
#include "Triangle.h"
#include "SolidShape.h"

CTriangle::CTriangle(Point vertex1, Point vertex2, Point vertex3, std::string const& colorOutlines, std::string const& fillColor)
    :ISolidShape(colorOutlines, fillColor)
{
    m_vertices.push_back(std::make_shared<CPoint>(CPoint(colorOutlines, vertex1)));
    m_vertices.push_back(std::make_shared<CPoint>(CPoint(colorOutlines, vertex2)));
    m_vertices.push_back(std::make_shared<CPoint>(CPoint(colorOutlines, vertex3)));
}

double CTriangle::GetArea() const
{
    double semiperimeter = GetPerimeter() / 2;
    return std::sqrt(semiperimeter*(semiperimeter - GetLengthLine(m_vertices[0], m_vertices[1]))*
        (semiperimeter - GetLengthLine(m_vertices[1], m_vertices[2]))*
        (semiperimeter - GetLengthLine(m_vertices[2], m_vertices[0]))
    );
};

double CTriangle::GetLengthLine(std::shared_ptr<CPoint> vertex1, std::shared_ptr<CPoint> vertex2) const
{
    double dx = vertex1->GetPoint().x - vertex2->GetPoint().x;
    double dy = vertex1->GetPoint().y - vertex2->GetPoint().y;
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
        << "  ColorOutline = " << GetColorOutlines()
        << "  FillColor = " << GetFillColor();
    return strm.str();
};

