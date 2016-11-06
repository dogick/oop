#pragma once
#include "stdafx.h"
#include "Var.h"
#include "Point.h"
#include "SolidShape.h"
#include "Color.h"
class CRectangle : public ISolidShape//, ICanvasDrawable
{
public:
    CRectangle(Point leftTop, float height, float width, Color const& colorOutlines, Color const& fillColor);
    std::shared_ptr<CPoint> const& GetLeftTop() const;
    std::shared_ptr<CPoint> const& GetRightBottom() const;
    float GetWidth() const;
    float GetHeight() const;

    float GetArea() const override;
    float GetPerimeter() const override;
    std::string ToString() const override;

    std::string GetOutlineColor() const override;
    std::string GetFillColor() const override;

    void Draw(ICanvas & canvas) const override;
private:
    std::shared_ptr<CPoint> m_leftTop;
    Vertices m_vertices;
    float m_width;
    float m_height;
    Color m_outlineColor;
    Color m_fillColor;
};