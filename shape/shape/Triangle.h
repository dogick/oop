#pragma once
#include "stdafx.h"
#include "Var.h"
#include "Point.h"
#include "SolidShape.h"

typedef std::vector<std::shared_ptr<CPoint>> Vertices;

class CTriangle : public ISolidShape
{
public:
    CTriangle(Point firstVertex, Point secondVertex, Point thirdVertex, std::string const& colorOutlines, std::string const& fillColor);
    double GetArea() const override;
    double GetPerimeter() const override;
    double GetLengthLine(std::shared_ptr<CPoint> firstVertex, std::shared_ptr<CPoint> secondVertex) const;
    std::string ToString() const override;
    std::string GetOutlineColor() const override;
    std::string GetFillColor() const override;
    std::shared_ptr<CPoint> const& GetVertex1() const;
    std::shared_ptr<CPoint> const& GetVertex2() const;
    std::shared_ptr<CPoint> const& GetVertex3() const;
private:
    Vertices m_vertices;
    std::string m_outlineColor;
    std::string m_fillColor;
};