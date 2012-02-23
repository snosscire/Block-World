#include "Rectangle.h"
#include "Position.h"

namespace BadEngine {
	Rectangle::Rectangle() :
		m_position(),
		m_width(0),
		m_height(0)
	{
	}
	
	Rectangle::Rectangle(double x, double y, double width, double height) :
		m_position(x, y),
		m_width(width),
		m_height(height)
	{
	}
	
	Rectangle::~Rectangle()
	{
	}
	
	void Rectangle::setX(double x)
	{
		m_position.setX(x);
	}
	
	void Rectangle::setY(double y)
	{
		m_position.setY(y);
	}
	
	void Rectangle::setWidth(double width)
	{
		m_width = width;
	}
	
	void Rectangle::setHeight(double height)
	{
		m_height = height;
	}
	
	double Rectangle::getX()
	{
		return m_position.getX();
	}
	
	double Rectangle::getY()
	{
		return m_position.getY();
	}
	
	double Rectangle::getWidth()
	{
		return m_width;
	}
	
	double Rectangle::getHeight()
	{
		return m_height;
	}
};