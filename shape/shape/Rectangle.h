#pragma once
#include "stdafx.h"
#include "Var.h"
#include "Point.h"
#include "SolidShape.h"

class CRectangle : public ISolidShape
{
public:
    CRectangle(Point leftTop, double height, double width, std::string const& colorOutlines, std::string const& fillColor);
    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
    std::string GetOutlineColor() const override;
    std::string GetFillColor() const override;
    std::shared_ptr<CPoint> const& GetLeftTop() const;
    std::shared_ptr<CPoint> const& GetRightBottom() const;
    double GetWidth() const;
    double GetHeight() const;
private:
    std::shared_ptr<CPoint> m_leftTop;
    std::shared_ptr<CPoint> m_rightBottom;
    double m_width;
    double m_height;
    std::string m_outlineColor;
    std::string m_fillColor;
};