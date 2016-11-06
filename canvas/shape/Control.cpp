#include "stdafx.h"
#include "Control.h"
#include "Shape.h"


using namespace std;
using namespace std::placeholders;

CRemoteControl::CRemoteControl(std::ifstream & inputFile, std::ostream & output, std::shared_ptr<CCanvas> canvas)
    :m_input(inputFile)
    , m_output(output)
    , m_canvas(canvas)
    , m_actionMap({
        { "line", bind(&CRemoteControl::CreateLine, this, _1) },
        { "circle", bind(&CRemoteControl::CreateCircle, this, _1) },
        { "rectangle", bind(&CRemoteControl::CreateRectangle, this, _1) },
        { "triangle", bind(&CRemoteControl::CreateTriangle, this, _1) },
})
{
}

bool CRemoteControl::HandleCommand()
{
    m_output << ">";
    string commandLine;
    getline(m_input, commandLine);
    istringstream strm(commandLine);
    string action;
    strm >> action;
    if (action.empty() && strm.eof())
    {
        std::cout << "EOF" << std::endl;
        return true;
    }
    auto it = m_actionMap.find(action);
    if (it != m_actionMap.end())
    {
        return it->second(strm);
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
        startPoint.x = boost::lexical_cast<float>(tokens[0]);
        startPoint.y = boost::lexical_cast<float>(tokens[1]);
        endPoint.x = boost::lexical_cast<float>(tokens[2]);
        endPoint.y = boost::lexical_cast<float>(tokens[3]);
    }
    catch (boost::bad_lexical_cast&)
    {
        m_output << "Invalid coordinate point!!!\n";
        return false;
    }
    Color outlineColor;
    if (!ConvertHexInRGBColor(tokens[4], outlineColor))
    {
        std::shared_ptr<IShape> shape = std::make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
        m_canvas->SaveShape(shape);
        return true;
    }
    return false;
}

bool CRemoteControl::CreateCircle(std::istream & args)
{
    std::string shapeSpecification;
    getline(args, shapeSpecification);
    std::vector<std::string> tokens = GetTokens(shapeSpecification);
    if (tokens.size() != 6)
    {
        m_output << "Invalid number of parameters!!!\n"
            << "Usage: <x1> <y1> <radius> <outlineThickness> <colorOutline> <fillColor>\n";
        return false;
    }
    Point position;
    float radius;
    float outlineThickness;
    try
    {
        position.x = boost::lexical_cast<float>(tokens[0]);
        position.y = boost::lexical_cast<float>(tokens[1]);
        radius = boost::lexical_cast<float>(tokens[2]);
        outlineThickness = boost::lexical_cast<float>(tokens[3]);
    }
    catch (boost::bad_lexical_cast&)
    {
        m_output << "Invalid coordinate point!!!\n";
        return false;
    }
    Color outlineColor;
    Color fillColor;
    if (!ConvertHexInRGBColor(tokens[4], outlineColor) && !ConvertHexInRGBColor(tokens[5], fillColor))
    {
        std::shared_ptr<IShape> shape = std::make_shared<CCircle>(position, radius, outlineThickness, outlineColor, fillColor);
        m_canvas->SaveShape(shape);
        return true;
    }
    return false;
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
    float width;
    float height;
    try
    {
        position.x = boost::lexical_cast<float>(tokens[0]);
        position.y = boost::lexical_cast<float>(tokens[1]);
        width = boost::lexical_cast<float>(tokens[2]);
        height = boost::lexical_cast<float>(tokens[3]);
    }
    catch (boost::bad_lexical_cast&)
    {
        m_output << "Invalid coordinate point!!!\n";
        return false;
    }
    Color outlineColor;
    Color fillColor;
    if (!ConvertHexInRGBColor(tokens[4], outlineColor) && !ConvertHexInRGBColor(tokens[5], fillColor))
    {
        std::shared_ptr<IShape> shape = std::make_shared<CRectangle>(position, width, height, outlineColor, fillColor);
        m_canvas->SaveShape(shape);
        return true;
    }
    return false;
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
        vertex1.x = boost::lexical_cast<float>(tokens[0]);
        vertex1.y = boost::lexical_cast<float>(tokens[1]);
        vertex2.x = boost::lexical_cast<float>(tokens[2]);
        vertex2.y = boost::lexical_cast<float>(tokens[3]);
        vertex3.x = boost::lexical_cast<float>(tokens[4]);
        vertex3.y = boost::lexical_cast<float>(tokens[5]);
    }
    catch (boost::bad_lexical_cast&)
    {
        m_output << "Invalid coordinate point!!!\n";
        return false;
    }
    Color outlineColor;
    Color fillColor;
    if (!ConvertHexInRGBColor(tokens[6], outlineColor) && !ConvertHexInRGBColor(tokens[7], fillColor))
    {
        std::shared_ptr<IShape> shape = std::make_shared<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
        m_canvas->SaveShape(shape);
        return true;
    }
    return false;
}