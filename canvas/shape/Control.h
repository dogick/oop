﻿#pragma once
#include <boost/noncopyable.hpp>
#include "Point.h"
#include "LineSegment.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Canvas.h"
#include <fstream>
#include "Color.h"

class IShape;

// Íàñëåäîâàíèå îò boost::noncopyable - ÿâíûé ñïîñîá çàïðåòèòü êîïèðîâàíèå è ïðèñâàèâàíèå ýêçåìïëÿðîâ êëàññà
class CRemoteControl : boost::noncopyable
{
public:
    CRemoteControl(std::ifstream & inputFile, std::ostream & output, std::shared_ptr<CCanvas> canvas);
    bool HandleCommand();
    std::vector<std::string> GetTokens(std::string const& shapeSpecification) const;
    // Èçáàâëÿåìñÿ îò ïðåäóïðåæäåíèÿ êîìïèëÿòîðà î òîì, ÷òî îí íå ñìîæåò ñãåíåðèðîâàòü îïåðàòîð ïðèñâàèâàíèÿ
    // CRemoteControl& operator=(const CRemoteControl &) = delete;
private:
    bool CreateLine(std::istream & args);
    bool CreateCircle(std::istream & args);
    bool CreateRectangle(std::istream & args);
    bool CreateTriangle(std::istream & args);
private:
    typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;

    std::ifstream & m_input;
    std::ostream & m_output;
    std::shared_ptr<CCanvas> m_canvas;
    const ActionMap m_actionMap;
};