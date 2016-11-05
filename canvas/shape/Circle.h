#pragma once
#include "stdafx.h"
#include "Var.h"
#include "SolidShape.h"
#include "Point.h"


class CCircle : public ISolidShape
{
public:
    CCircle(Point center, double radius, std::string const& colorOutlines, std::string const& fillColor);
    double GetRadius() const;
    std::shared_ptr<CPoint> const& GetCenter() const;

    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;

    std::string GetOutlineColor() const override;
    std::string GetFillColor() const override;

private:
    std::shared_ptr<CPoint> m_center;
    double m_radius;
    std::string m_outlineColor;
    std::string m_fillColor;
};