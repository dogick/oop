#pragma once
#include "stdafx.h"
#include "Var.h"
#include "Shape.h"
#include "Point.h"

class CLineSegment : public IShape
{
public:
    CLineSegment(Point startPosition, Point endPosition, std::string const& outlineColor);
    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
    std::string GetOutlineColor() const override;
    std::shared_ptr<CPoint> const& GetStartPoint() const;
    std::shared_ptr<CPoint> const& GetEndPoint() const;
private:
    std::shared_ptr<CPoint> m_startPoint;
    std::shared_ptr<CPoint> m_endPoint;
    std::string m_outlineColor;
};