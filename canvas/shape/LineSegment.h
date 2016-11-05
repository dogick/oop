#pragma once
#include "stdafx.h"
#include "Var.h"
#include "Shape.h"
#include "Point.h"
#include "ICanvas.h"

class CLineSegment : public IShape//, ICanvasDrawable
{
public:
    CLineSegment(Point startPosition, Point endPosition, std::string const& outlineColor);
    std::shared_ptr<CPoint> const& GetStartPoint() const;
    std::shared_ptr<CPoint> const& GetEndPoint() const;

    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;

    std::string GetOutlineColor() const override;
    void Draw(ICanvas & canvas) const override;
    //void Draw(ICanvas & canvas) const override;
private:
    std::shared_ptr<CPoint> m_startPoint;
    std::shared_ptr<CPoint> m_endPoint;
    std::string m_outlineColor;
};