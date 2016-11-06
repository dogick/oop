#pragma once
#include "stdafx.h"
#include "Var.h"
#include "Shape.h"
#include "Point.h"
#include "ICanvas.h"
#include "Color.h"

class CLineSegment : public IShape
{
public:
    CLineSegment(Point startPosition, Point endPosition, Color const& outlineColor);
    std::shared_ptr<CPoint> const& GetStartPoint() const;
    std::shared_ptr<CPoint> const& GetEndPoint() const;

    float GetArea() const override;
    float GetPerimeter() const override;
    std::string ToString() const override;

    std::string GetOutlineColor() const override;

    void Draw(ICanvas & canvas) const override;
private:
    std::shared_ptr<CPoint> m_startPoint;
    std::shared_ptr<CPoint> m_endPoint;
    Color m_outlineColor;
};