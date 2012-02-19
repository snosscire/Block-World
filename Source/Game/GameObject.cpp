#include "GameObject.h"
#include "World.h"
#include "ObjectBehavior.h"
#include "Camera.h"

#include "../Engine/Rectangle.h"

#include <iostream>

namespace BlockWorld {
	GameObject::GameObject() :
		m_world(NULL),
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

	GameObject::GameObject(World& world) :
		m_world(&world),
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
	
	World* GameObject::getWorld()
	{
		return m_world;
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
	
	int GameObject::getSpriteWidth()
	{
		return 32;
	}
	
	int GameObject::getSpriteHeight()
	{
		return 32;
	}
	
	bool GameObject::isJumping()
	{
		return m_jumping;
	}
	
	bool GameObject::isTouchingGround()
	{
		return m_touchingGround;
	}
	
	bool GameObject::wantToMoveLeft()
	{
		return m_moveLeft;
	}
	
	bool GameObject::wantToMoveRight()
	{
		return m_moveRight;
	}
	
	bool GameObject::wantToJump()
	{
		return m_jump;
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
	
	void GameObject::setTouchingGround(bool touching)
	{
		m_touchingGround = touching;
	}
	
	void GameObject::setJump(bool jump)
	{
		m_jump = jump;
	}
	
	void GameObject::setJumping(bool jumping)
	{
		m_jumping = jumping;
	}
	
	void GameObject::update(double deltaTime)
	{
		if (m_movingBehavior) {
			m_movingBehavior->perform(*this, deltaTime);
		}
		if (m_jumpingBehavior) {
			m_jumpingBehavior->perform(*this, deltaTime);
		}
		if (m_fallingBehavior) {
			m_fallingBehavior->perform(*this, deltaTime);
		}
		if (m_collidingBehavior) {
			m_collidingBehavior->perform(*this, deltaTime);
		}
	}
	
	void GameObject::draw(Engine& engine, Camera& camera)
	{
		int x = (m_x) - camera.getLeft() - (getSpriteWidth() / 2);
		int y = (m_y) - camera.getTop() - (getSpriteHeight() / 2);
		Rectangle rectangle(x, y, 32, 32);
		engine.drawRectangle(rectangle, 255, 255, 0);
	}
};
