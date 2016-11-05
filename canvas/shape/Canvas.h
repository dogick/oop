#pragma once
#include "stdafx.h"
#include "ICanvas.h"
#include "Point.h"
#include "Shape.h"

class CCanvas : public ICanvas
{
public:
    CCanvas(int windowWidth, int windowHeight);
    std::vector<std::shared_ptr<IShape>> GetShapes() const;
    void DrawLine(std::shared_ptr<CPoint> startPoint, std::shared_ptr<CPoint> endPoint, std::string const& outlineColor) const override;
    void FillPolygon(Vertices const& vertices, std::string const& fillColor) const override;
    void DrawCircle(std::shared_ptr<CPoint> center, double radius, std::string const& outlineColor) const override;
    void FillCircle(std::shared_ptr<CPoint> center, double radius, std::string const& fillColor) const override;
    std::shared_ptr<sf::RenderWindow> GetCanvas() const;
    void SaveShape(std::shared_ptr<IShape> shape);

    void EnterMainLoop();
    void HandleEvents();
    void Render();

    void Info();
private:
    std::shared_ptr<sf::RenderWindow> m_canvas;
    std::vector<std::shared_ptr<IShape>> m_shapes;
};