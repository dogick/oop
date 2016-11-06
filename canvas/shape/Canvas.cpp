#include "stdafx.h"
#include "Canvas.h"
#include "Shape.h"

CCanvas::CCanvas(int windowWidth, int windowHeight, sf::ContextSettings const& settings)
    :m_canvas(std::make_shared<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), "Canvas", sf::Style::Default, settings))
{
}

std::vector<std::shared_ptr<IShape>> CCanvas::GetShapes() const
{
    return m_shapes;
}

void CCanvas::SaveShape(std::shared_ptr<IShape> shape)
{
    m_shapes.push_back(shape);
}

std::shared_ptr<sf::RenderWindow> CCanvas::GetCanvas() const
{
    return m_canvas;
}

void CCanvas::HandleEvents()
{
    sf::Event event;
    while (m_canvas->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_canvas->close();
        }
    }
}

void CCanvas::Render()
{
    m_canvas->clear(sf::Color::White);
    for (auto shape : m_shapes)
    {
        shape->Draw(*this);
    }
    m_canvas->display();
}

void CCanvas::EnterMainLoop()
{
    while (m_canvas->isOpen())
    {
        HandleEvents();
        Render();
    }
}

void CCanvas::DrawLine(std::shared_ptr<CPoint> startPoint, std::shared_ptr<CPoint> endPoint, Color const& outlineColor) const
{
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(startPoint->GetPoint().x, startPoint->GetPoint().y)),
        sf::Vertex(sf::Vector2f(endPoint->GetPoint().x, endPoint->GetPoint().y))
    };
    line[0].color = sf::Color(outlineColor.Red, outlineColor.Green, outlineColor.Blue);
    line[1].color = sf::Color(outlineColor.Red, outlineColor.Green, outlineColor.Blue);
    m_canvas->draw(line, 2, sf::Lines);
}

void CCanvas::DrawPolygon(Vertices const& vertices, Color const& outlineColor, Color const& fillColor)
{
    m_polygon.setPointCount(vertices.size());
    for (size_t i = 0; i < vertices.size(); ++i)
    {
        m_polygon.setPoint(i, sf::Vector2f(vertices[i]->GetPoint().x, vertices[i]->GetPoint().y));
    }
    m_polygon.setFillColor(sf::Color(fillColor.Red, fillColor.Green, fillColor.Blue));
    m_polygon.setOutlineThickness(2);
    m_polygon.setOutlineColor(sf::Color(outlineColor.Red, outlineColor.Green, outlineColor.Blue));
    m_canvas->draw(m_polygon);
}


void CCanvas::FillCircle(std::shared_ptr<CPoint> center, float radius, Color const& fillColor)
{
    m_circle.setFillColor(sf::Color(fillColor.Red, fillColor.Green, fillColor.Blue));
}

void CCanvas::DrawCircle(std::shared_ptr<CPoint> center, float radius, float outlineThickness, Color const& outlineColor)
{
    m_circle.setRadius(radius);
    m_circle.setOrigin(radius / 2, radius / 2);
    m_circle.setPosition(center->GetPoint().x, center->GetPoint().y);
    m_circle.setOutlineThickness(outlineThickness);
    m_circle.setOutlineColor(sf::Color(outlineColor.Red, outlineColor.Green, outlineColor.Blue));
    m_canvas->draw(m_circle);
}