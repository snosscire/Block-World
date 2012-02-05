#include "Rectangle.h"
#include "Position.h"

namespace BadEngine {
	Rectangle::Rectangle() :
		m_position(),
		m_width(0),
		m_height(0)
	{
	}
	
	Rectangle::Rectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height) :
		m_position(x, y),
		m_width(width),
		m_height(height)
	{
	}
	
	Rectangle::~Rectangle()
	{
	}
	
	unsigned int Rectangle::getX()
	{
		return m_position.getX();
	}
	
	unsigned int Rectangle::getY()
	{
		return m_position.getY();
	}
	
	unsigned int Rectangle::getWidth()
	{
		return m_width;
	}
	
	unsigned int Rectangle::getHeight()
	{
		return m_height;
	}
};