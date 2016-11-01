#pragma once
#include "stdafx.h"
#include "Var.h"
#include "Point.h"
#include "SolidShape.h"

class CRectangle : public ISolidShape
{
public:
    CRectangle(Point vertex, double height, double width, std::string const& colorOutlines, std::string const& fillColor);
    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
private:
    CPoint m_vertex;
    double m_width;
    double m_height;
};