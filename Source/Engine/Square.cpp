#include "Square.h"
#include "Position.h"

namespace BadEngine {
	Square::Square() :
		m_position(),
		m_width(0),
		m_height(0)
	{
	}
	
	Square::Square(double x, double y, double width, double height) :
		m_position(x, y),
		m_width(width),
		m_height(height)
	{
	}
	
	Square::~Square()
	{
	}
	
	void Square::setX(double x)
	{
		m_position.setX(x);
	}
	
	void Square::setY(double y)
	{
		m_position.setY(y);
	}
	
	void Square::setWidth(double width)
	{
		m_width = width;
	}
	
	void Square::setHeight(double height)
	{
		m_height = height;
	}
	
	double Square::getX()
	{
		return m_position.getX();
	}
	
	double Square::getY()
	{
		return m_position.getY();
	}
	
	double Square::getWidth()
	{
		return m_width;
	}
	
	double Square::getHeight()
	{
		return m_height;
	}
};