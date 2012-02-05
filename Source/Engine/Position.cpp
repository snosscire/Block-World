#include "Position.h"

namespace BadEngine {
	Position::Position() :
		m_x(0),
		m_y(0)
	{
	}
	
	Position::Position(unsigned int x, unsigned int y) :
		m_x(x),
		m_y(y)
	{
	}
	
	Position::~Position()
	{
	}
	
	void Position::setX(unsigned int x)
	{
		m_x = x;
	}
	
	void Position::setY(unsigned int y)
	{
		m_y = y;
	}
	
	unsigned int Position::getX()
	{
		return m_x;
	}
	
	unsigned int Position::getY()
	{
		return m_y;
	}
};
