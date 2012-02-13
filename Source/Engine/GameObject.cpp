#include "GameObject.h"
#include "ObjectBehavior.h"

#include <iostream>

namespace BadEngine {
	GameObject::GameObject() :
		m_x(0.0),
		m_y(0.0),
		m_velocityX(0.0),
		m_velocityY(0.0),
		m_moveLeft(false),
		m_moveRight(false),
		m_jump(false),
		m_jumping(false),
		m_touchingGround(false),
		m_movingBehavior(NULL),
		m_jumpingBehavior(NULL),
		m_fallingBehavior(NULL),
		m_collidingBehavior(NULL)
	{
	}
	
	GameObject::~GameObject()
	{
		if (m_movingBehavior) {
			delete m_movingBehavior;
		}
		if (m_jumpingBehavior) {
			delete m_jumpingBehavior;
		}
		if (m_fallingBehavior) {
			delete m_fallingBehavior;
		}
		if (m_collidingBehavior) {
			delete m_collidingBehavior;
		}
	}
	
	double GameObject::getX()
	{
		return m_x;
	}
	
	double GameObject::getY()
	{
		return m_y;
	}
	
	double GameObject::getVelocityX()
	{
		return m_velocityX;
	}
	
	double GameObject::getVelocityY()
	{
		return m_velocityY;
	}
	
	unsigned int GameObject::getSpriteWidth()
	{
		return 32;
	}
	
	unsigned int GameObject::getSpriteHeight()
	{
		return 32;
	}
	
	void GameObject::setX(double x)
	{
		m_x = x;
	}
	
	void GameObject::setY(double y)
	{
		m_y = y;
	}
	
	void GameObject::setVelocityX(double velocity)
	{
		m_velocityX = velocity;
	}
	
	void GameObject::setVelocityY(double velocity)
	{
		m_velocityY = velocity;
	}
	
	void GameObject::setMoveLeft(bool move)
	{
		m_moveLeft = move;
	}
	
	void GameObject::setMoveRight(bool move)
	{
		m_moveRight = move;
	}
	
	void GameObject::update(unsigned int deltaTime)
	{
	}
	
	void GameObject::draw(Engine& engine, Camera& camera)
	{
	}
};
