#pragma once
#include "stdafx.h"
#include "Var.h"
#include "Point.h"
#include "SolidShape.h"


class CTriangle : public ISolidShape//, ICanvasDrawable
{
public:
    CTriangle(Point firstVertex, Point secondVertex, Point thirdVertex, std::string const& colorOutlines, std::string const& fillColor);
    double GetSideLength(std::shared_ptr<CPoint> firstVertex, std::shared_ptr<CPoint> secondVertex) const;
    std::shared_ptr<CPoint> const& GetVertex1() const;
    std::shared_ptr<CPoint> const& GetVertex2() const;
    std::shared_ptr<CPoint> const& GetVertex3() const;

    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;

    std::string GetOutlineColor() const override;
    std::string GetFillColor() const override;

    //void Draw(ICanvas & canvas) const override;
private:
    Vertices m_vertices;
    std::string m_outlineColor;
    std::string m_fillColor;
};