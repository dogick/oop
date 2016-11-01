#pragma once
#include "stdafx.h"
#include "Var.h"
#include "Shape.h"
#include "Color.h"

class CPoint : public IShape
{
public:
    CPoint(std::string const& colorOutline, Point point);
    Point GetPoint() const;
    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
private:
    Point m_point;
};
