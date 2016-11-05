#pragma once
#include "stdafx.h"
#include "Shape.h"

class ISolidShape : public IShape
{
public:
    ISolidShape();
    ~ISolidShape();
    virtual std::string GetFillColor() const = 0;
};