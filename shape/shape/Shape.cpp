#include "stdafx.h"
#include "Shape.h"

IShape::IShape(std::string const& colorOutlines)
    :m_colorOutlines(colorOutlines)
{
}

std::string IShape::GetColorOutlines() const
{ 
    return m_colorOutlines; 
};