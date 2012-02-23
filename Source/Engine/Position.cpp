#include "Position.h"

namespace BadEngine {
	Position::Position() :
		m_x(0),
		m_y(0)
	{
	}
	
	Position::Position(double x, double y) :
		m_x(x),
		m_y(y)
	{
	}
	
	Position::~Position()
	{
	}
	
	void Position::setX(double x)
	{
		m_x = x;
	}
	
	void Position::setY(double y)
	{
		m_y = y;
	}
	
	double Position::getX()
	{
		return m_x;
	}
	
	double Position::getY()
	{
		return m_y;
	}
};
