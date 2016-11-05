#pragma once
#include "stdafx.h"
#include "Point.h"

class ICanvas
{
public:
    ICanvas();
    ~ICanvas();
    virtual void DrawLine(std::shared_ptr<CPoint> startPoint, std::shared_ptr<CPoint> endPoint, std::string const& outlineColor) const = 0;
    virtual void FillPolygon(Vertices const& vertices, std::string const& fillColor) const = 0;
    virtual void DrawCircle(std::shared_ptr<CPoint> center, double radius, std::string const& outlineColor) const = 0;
    virtual void FillCircle(std::shared_ptr<CPoint> center, double radius, std::string const& fillColor) const = 0;
};