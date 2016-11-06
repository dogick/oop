#pragma once
#include "stdafx.h"
#include "ICanvas.h"
#include "Point.h"
#include "Shape.h"
#include "Color.h"

class CCanvas : public ICanvas
{
public:
    CCanvas(int windowWidth, int windowHeight, sf::ContextSettings const& settings);
    std::vector<std::shared_ptr<IShape>> GetShapes() const;
    std::shared_ptr<sf::RenderWindow> GetCanvas() const;
    void SaveShape(std::shared_ptr<IShape> shape);

    void DrawLine(std::shared_ptr<CPoint> startPoint, std::shared_ptr<CPoint> endPoint, Color const& outlineColor) const override;
    void DrawPolygon(Vertices const& vertices, Color const& outlineColor, Color const& fillColor) override;
    void DrawCircle(std::shared_ptr<CPoint> center, float radius, float outlineThickness, Color const& outlineColor) override;
    void FillCircle(std::shared_ptr<CPoint> center, float radius, Color const& fillColor) override;

    void EnterMainLoop();
    void HandleEvents();
    void Render();
private:
    std::shared_ptr<sf::RenderWindow> m_canvas;
    std::vector<std::shared_ptr<IShape>> m_shapes;

    sf::CircleShape m_circle;
    sf::ConvexShape m_polygon;
};