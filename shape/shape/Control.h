#pragma once
#include <boost/noncopyable.hpp>
#include "Point.h"
#include "LineSegment.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

class IShape;

// Íàñëåäîâàíèå îò boost::noncopyable - ÿâíûé ñïîñîá çàïðåòèòü êîïèðîâàíèå è ïðèñâàèâàíèå ýêçåìïëÿðîâ êëàññà
class CRemoteControl : boost::noncopyable
{
public:
    CRemoteControl(std::istream & input, std::ostream & output);
    bool HandleCommand();
    std::vector<std::string> GetTokens(std::string const& shapeSpecification) const;
    // Èçáàâëÿåìñÿ îò ïðåäóïðåæäåíèÿ êîìïèëÿòîðà î òîì, ÷òî îí íå ñìîæåò ñãåíåðèðîâàòü îïåðàòîð ïðèñâàèâàíèÿ
    // CRemoteControl& operator=(const CRemoteControl &) = delete;
private:
    bool CreatePoint(std::istream & args);
    bool CreateLine(std::istream & args);
    bool CreateCircle(std::istream & args);
    bool CreateRectangle(std::istream & args);
    bool CreateTriangle(std::istream & args);
    void PrintInfoShape() const;
private:
    typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;

    std::vector<std::shared_ptr<IShape>> m_shapes;
    std::istream & m_input;
    std::ostream & m_output;

    const ActionMap m_actionMap;
};