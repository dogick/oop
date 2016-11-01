#include "stdafx.h"
#include "Control.h"
#include "Shape.h"


using namespace std;
using namespace std::placeholders;

CRemoteControl::CRemoteControl(std::istream & input, std::ostream & output)
    :m_input(input)
    , m_output(output)
    , m_actionMap({
        { "point", bind(&CRemoteControl::CreatePoint, this, _1) },
        { "line", bind(&CRemoteControl::CreateLine, this, _1) },
        { "circle", bind(&CRemoteControl::CreateCircle, this, _1) },
        { "rectangle", bind(&CRemoteControl::CreateRectangle, this, _1) },
        { "triangle", bind(&CRemoteControl::CreateRectangle, this, _1) },
})
{
}

void CRemoteControl::PrintInfoShape() const
{
    for (auto shape : m_shapes)
    {
       m_output << ">" << shape->ToString() << "\n";
    }
}

bool CRemoteControl::HandleCommand()
{
    PrintInfoShape();
    string commandLine;
    getline(m_input, commandLine);
    istringstream strm(commandLine);
    string action;
    strm >> action;
    auto it = m_actionMap.find(action);
    if (it != m_actionMap.end())
    {
        it->second(strm);
        return true;
    }
    return false;
}

std::vector<std::string> CRemoteControl::GetTokens(std::string const& shapeSpecification) const
{
    std::vector<std::string> tokens;
    const boost::char_separator<char> delimiters(", ");
    boost::tokenizer<boost::char_separator<char>> tokenizer(shapeSpecification, delimiters);
    std::transform(tokenizer.begin(), tokenizer.end(), std::back_inserter(tokens), [](auto const& token) { return token; });
    return tokens;
}


bool CRemoteControl::CreatePoint(std::istream & args)
{
    std::string shapeSpecification;
    getline(args, shapeSpecification);
    std::vector<std::string> tokens = GetTokens(shapeSpecification);
    if (tokens.size() != 3)
    {
        m_output << "Invalid number of parameters!!!\n"
            << "Usage: <x1> <y1> <colorOutline>\n";
        return false;
    }
    Point point;
    try
    {
        point.x = boost::lexical_cast<double>(tokens[0]);
        point.y = boost::lexical_cast<double>(tokens[1]);
    }
    catch (boost::bad_lexical_cast&)
    {
        m_output << "Invalid coordinate point!!!\n";
        return false;
    }
    m_shapes.push_back(std::make_shared<CPoint>(CPoint(tokens[2], point)));
    return true;
}

bool CRemoteControl::CreateLine(std::istream & args)
{
    std::string shapeSpecification;
    getline(args, shapeSpecification);
    std::vector<std::string> tokens = GetTokens(shapeSpecification);
    if (tokens.size() != 5)
    {
        m_output << "Invalid number of parameters!!!\n"
            << "Usage: <x1> <y1> <x2> <y2> <colorOutline>\n";
        return false;
    }
    Point startPoint, endPoint;
    try
    {
        startPoint.x = boost::lexical_cast<double>(tokens[0]);
        startPoint.y = boost::lexical_cast<double>(tokens[1]);
        endPoint.x = boost::lexical_cast<double>(tokens[2]);
        endPoint.y = boost::lexical_cast<double>(tokens[3]);
    }
    catch (boost::bad_lexical_cast&)
    {
        m_output << "Invalid coordinate point!!!\n";
        return false;
    }
    m_shapes.push_back(std::make_shared<CLineSegment>(CLineSegment(startPoint, endPoint, tokens[4])));
    return true;
}

bool CRemoteControl::CreateCircle(std::istream & args)
{
    std::string shapeSpecification;
    getline(args, shapeSpecification);
    std::vector<std::string> tokens = GetTokens(shapeSpecification);
    if (tokens.size() != 5)
    {
        m_output << "Invalid number of parameters!!!\n"
            << "Usage: <x1> <y1> <radius> <colorOutline> <fillColor>\n";
        return false;
    }
    Point position;
    double radius;
    try
    {
        position.x = boost::lexical_cast<double>(tokens[0]);
        position.y = boost::lexical_cast<double>(tokens[1]);
        radius = boost::lexical_cast<double>(tokens[2]);
    }
    catch (boost::bad_lexical_cast&)
    {
        m_output << "Invalid coordinate point!!!\n";
        return false;
    }
    m_shapes.push_back(std::make_shared<CCircle>(CCircle(position, radius, tokens[3], tokens[4])));
    return true;
}

bool CRemoteControl::CreateRectangle(std::istream & args)
{
    std::string shapeSpecification;
    getline(args, shapeSpecification);
    std::vector<std::string> tokens = GetTokens(shapeSpecification);
    if (tokens.size() != 6)
    {
        m_output << "Invalid number of parameters!!!\n"
            << "Usage: <x1> <y1> <width> <height> <colorOutline> <fillColor>\n";
        return false;
    }
    Point position;
    double width;
    double height;
    try
    {
        position.x = boost::lexical_cast<double>(tokens[0]);
        position.y = boost::lexical_cast<double>(tokens[1]);
        width = boost::lexical_cast<double>(tokens[2]);
        height = boost::lexical_cast<double>(tokens[3]);
    }
    catch (boost::bad_lexical_cast&)
    {
        m_output << "Invalid coordinate point!!!\n";
        return false;
    }
    m_shapes.push_back(std::make_shared<CRectangle>(CRectangle(position, width, height, tokens[3], tokens[4])));
    return true;
}

bool CRemoteControl::CreateTriangle(std::istream & args)
{
    std::string shapeSpecification;
    getline(args, shapeSpecification);
    std::vector<std::string> tokens = GetTokens(shapeSpecification);
    if (tokens.size() != 8)
    {
        m_output << "Invalid number of parameters!!!\n"
            << "Usage: <x1> <y1> <x2> <y2> <x3> <y3> <colorOutline> <fillColor>\n";
        return false;
    }
    Point vertex1;
    Point vertex2;
    Point vertex3;
    try
    {
        vertex1.x = boost::lexical_cast<double>(tokens[0]);
        vertex1.y = boost::lexical_cast<double>(tokens[1]);
        vertex2.x = boost::lexical_cast<double>(tokens[2]);
        vertex2.y = boost::lexical_cast<double>(tokens[3]);
        vertex3.x = boost::lexical_cast<double>(tokens[4]);
        vertex3.y = boost::lexical_cast<double>(tokens[5]);
    }
    catch (boost::bad_lexical_cast&)
    {
        m_output << "Invalid coordinate point!!!\n";
        return false;
    }
    m_shapes.push_back(std::make_shared<CTriangle>(CTriangle(vertex1, vertex2, vertex3, tokens[6], tokens[7])));
    return true;
}