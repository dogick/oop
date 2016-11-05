#pragma once
#include "stdafx.h"
#include "Var.h"
#include "Color.h"
class CPoint
{
public:
    CPoint(Point const& point);
    Point CPoint::GetPoint() const;
private:
    Point m_point;
};

typedef std::vector<std::shared_ptr<CPoint>> Vertices;