#pragma once
#include "stdafx.h"
#include "Var.h"
#include "Point.h"
#include "SolidShape.h"
#include "Color.h"

class CTriangle : public ISolidShape//, ICanvasDrawable
{
public:
    CTriangle(Point firstVertex, Point secondVertex, Point thirdVertex, Color const& colorOutlines, Color const& fillColor);
    float GetSideLength(std::shared_ptr<CPoint> firstVertex, std::shared_ptr<CPoint> secondVertex) const;
    std::shared_ptr<CPoint> const& GetVertex1() const;
    std::shared_ptr<CPoint> const& GetVertex2() const;
    std::shared_ptr<CPoint> const& GetVertex3() const;

    float GetArea() const override;
    float GetPerimeter() const override;
    std::string ToString() const override;

    std::string GetOutlineColor() const override;
    std::string GetFillColor() const override;

    void Draw(ICanvas & canvas) const override;
private:
    Vertices m_vertices;
    Color m_outlineColor;
    Color m_fillColor;
};