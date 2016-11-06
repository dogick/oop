#pragma once
#include "stdafx.h"
#include "Var.h"
#include "SolidShape.h"
#include "Point.h"
#include "Color.h"


class CCircle : public ISolidShape
{
public:
    CCircle(Point center, float radius, float outlineThickness, Color const& colorOutlines, Color const& fillColor);
    float GetRadius() const;
    std::shared_ptr<CPoint> const& GetCenter() const;

    float GetArea() const override;
    float GetPerimeter() const override;
    std::string ToString() const override;

    std::string GetOutlineColor() const override;
    std::string GetFillColor() const override;

    void Draw(ICanvas & canvas) const override;
private:
    std::shared_ptr<CPoint> m_center;
    float m_radius;
    float m_outlineThickness;
    Color m_outlineColor;
    Color m_fillColor;
};