#include "stdafx.h"
#include "Canvas.h"
#include "Shape.h"

CCanvas::CCanvas(int windowWidth, int windowHeight)
    :m_canvas(std::make_shared<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), "Canvas"))
{

}

void CCanvas::Info()
{
    std::cout << m_shapes.size() << std::endl;
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
    m_canvas->clear();
    for (auto shape : m_shapes)
    {
    }
    m_canvas->display();
}

void CCanvas::EnterMainLoop()
{
    sf::CircleShape shape;
    shape.setRadius(100);
    shape.setFillColor(sf::Color::Red);
    while (m_canvas->isOpen())
    {
        HandleEvents();
        Render();
    }
}

void CCanvas::DrawLine(std::shared_ptr<CPoint> startPoint, std::shared_ptr<CPoint> endPoint, std::string const& outlineColor) const
{

}

void CCanvas::FillPolygon(Vertices const& vertices, std::string const& fillColor) const
{

}

void CCanvas::DrawCircle(std::shared_ptr<CPoint> center, double radius, std::string const& outlineColor) const
{

}

void CCanvas::FillCircle(std::shared_ptr<CPoint> center, double radius, std::string const& fillColor) const
{

}