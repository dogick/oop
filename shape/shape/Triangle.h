#pragma once
#include "stdafx.h"
#include "Var.h"
#include "Point.h"
#include "SolidShape.h"

typedef std::vector<std::shared_ptr<CPoint>> Vertices;

class CTriangle : public ISolidShape
{
public:
    CTriangle(Point vertex1, Point vertex2, Point vertex3, std::string const& colorOutlines, std::string const& fillColor);
    double GetArea() const override;
    double GetPerimeter() const override;
    double GetLengthLine(std::shared_ptr<CPoint> vertex1, std::shared_ptr<CPoint> vertex2) const;
    std::string ToString() const override;
private:
    Vertices m_vertices;
};