#pragma once
#include "stdafx.h"
#include "Color.h"
#include "CanvasDrawable.h"

class IShape: public ICanvasDrawable
{
public:
    IShape();
    ~IShape();
    virtual double GetArea() const = 0;
    virtual double GetPerimeter() const = 0;
    virtual std::string ToString() const = 0;
    virtual std::string GetOutlineColor() const = 0;
};