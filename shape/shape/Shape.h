#pragma once
#include "stdafx.h"
#include "Color.h"

class IShape
{
public:
    IShape(std::string const& colorOutlines);
    virtual double GetArea() const = 0;
    virtual double GetPerimeter() const = 0;
    virtual std::string ToString() const = 0;
    std::string GetColorOutlines() const;
private:
    std::string m_colorOutlines;
};