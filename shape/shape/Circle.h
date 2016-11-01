#pragma once
#include "stdafx.h"
#include "Var.h"
#include "SolidShape.h"

class CCircle : public ISolidShape
{
public:
    CCircle(Point position, double radius, std::string const& colorOutlines, std::string const& fillColor);
    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
private:
    Point m_position;
    double m_radius;
};