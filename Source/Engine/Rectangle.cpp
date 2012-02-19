#include "Rectangle.h"
#include "Position.h"

namespace BadEngine {
	Rectangle::Rectangle() :
		m_position(),
		m_width(0),
		m_height(0)
	{
	}
	
	Rectangle::Rectangle(int x, int y, int width, int height) :
		m_position(x, y),
		m_width(width),
		m_height(height)
	{
	}
	
	Rectangle::~Rectangle()
	{
	}
	
	void Rectangle::setX(int x)
	{
		m_position.setX(x);
	}
	
	void Rectangle::setY(int y)
	{
		m_position.setY(y);
	}
	
	void Rectangle::setWidth(int width)
	{
		m_width = width;
	}
	
	void Rectangle::setHeight(int height)
	{
		m_height = height;
	}
	
	int Rectangle::getX()
	{
		return m_position.getX();
	}
	
	int Rectangle::getY()
	{
		return m_position.getY();
	}
	
	int Rectangle::getWidth()
	{
		return m_width;
	}
	
	int Rectangle::getHeight()
	{
		return m_height;
	}
};