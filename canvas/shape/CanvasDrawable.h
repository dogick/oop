#pragma once
#include "stdafx.h"
#include "ICanvas.h"

class ICanvasDrawable
{
public:
    virtual void Draw(ICanvas & canvas) const = 0;
};