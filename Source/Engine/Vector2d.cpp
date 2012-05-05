#include "Vector2d.h"

namespace BadEngine {
	Vector2d::Vector2d() :
		m_x(0.0),
		m_y(0.0)
	{
	}
	
	Vector2d::Vector2d(double x, double y) :
		m_x(x),
		m_y(y)
	{
	}
	
	Vector2d::~Vector2d()
	{
	}
	
	double Vector2d::getX()
	{
		return m_x;
	}
	
	double Vector2d::getY()
	{
		return m_y;
	}
};
