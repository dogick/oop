#pragma once
#include "stdafx.h"
#include "Point.h"
#include "Color.h"

class ICanvas
{
public:
    ICanvas();
    ~ICanvas();
    virtual void DrawLine(std::shared_ptr<CPoint> startPoint, std::shared_ptr<CPoint> endPoint, Color const& outlineColor) const = 0;
    virtual void DrawPolygon(Vertices const& vertices, Color const& outlineColor, Color const& fillColor) = 0;
    virtual void DrawCircle(std::shared_ptr<CPoint> center, float radius, float outlineThickness, Color const& outlineColor) = 0;
    virtual void FillCircle(std::shared_ptr<CPoint> center, float radius, Color const& fillColor) = 0;
};