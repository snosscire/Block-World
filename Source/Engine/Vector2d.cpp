#include "Vector2d.h"

#include <math.h>

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
	
	double Vector2d::length()
	{
		return sqrt(m_x * m_x + m_y * m_y);
	}
	
	void Vector2d::normalize()
	{
		double magnitude = length();
		m_x = m_x / magnitude;
		m_y = m_y / magnitude;
	}
	
	double Vector2d::angle(Vector2d& other)
	{
		double value = m_x * other.getX() + m_y * other.getY();
		double radians = acos(value);
		double degrees = radians * (180 / 3.14159265);
		return degrees;
	}
};
