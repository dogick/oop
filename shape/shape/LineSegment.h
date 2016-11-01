#pragma once
#include "stdafx.h"
#include "Var.h"
#include "Shape.h"
#include "Point.h"

class CLineSegment : public IShape
{
public:
    CLineSegment(Point startPosition, Point endPosition, std::string const& colorOutlines);
    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
private:
    CPoint m_startPoint;
    CPoint m_endPoint;
};