#include "stdafx.h"
#include "Point.h"

CPoint::CPoint(Point const& point)
    :m_point(point)
{
}

Point CPoint::GetPoint() const
{
    return m_point;
}
