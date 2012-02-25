#include "GameObject.h"
#include "World.h"
#include "ObjectBehavior.h"
#include "ObjectController.h"
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
		m_collidingBehavior(NULL),
		m_controller(NULL),
		m_sprite(NULL),
		m_collisionRectangles()
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
		m_collidingBehavior(NULL),
		m_controller(NULL),
		m_sprite(NULL),
		m_collisionRectangles()
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
		if (m_controller) {
			delete m_controller;
		}
		if (m_sprite) {
			delete m_sprite;
		}
		clearCollisionRectangles();
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
		return m_sprite->getWidth();
	}
	
	int GameObject::getSpriteHeight()
	{
		return m_sprite->getHeight();
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
	
	void GameObject::setController(ObjectController* controller)
	{
		if (m_controller) {
			delete m_controller;
			m_controller = NULL;
		}
		m_controller = controller;
	}
	
	void GameObject::setX(double x)
	{
		double change = x - m_x;
		m_x = x;
		
		list<Rectangle*>::iterator it;
		it = m_collisionRectangles.begin();
		for ( ; it != m_collisionRectangles.end(); it++) {
			(*it)->setX((*it)->getX() + change);
		}
	}
	
	void GameObject::setY(double y)
	{
		double change = y - m_y;
		m_y = y;
		
		list<Rectangle*>::iterator it;
		it = m_collisionRectangles.begin();
		for ( ; it != m_collisionRectangles.end(); it++) {
			(*it)->setY((*it)->getY() + change);
		}
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
		
		if (m_jumping && !m_touchingGround) {
			m_sprite->playAnimation("jump");
		} else {
			if (m_velocityX < 0.0) {
				m_sprite->flipImages(true);
				m_sprite->playAnimation("run");
			} else if (m_velocityX > 0.0) {
				m_sprite->flipImages(false);
				m_sprite->playAnimation("run");
			} else {
				if (m_sprite->getCurrentAnimationName() == "run") {
					m_sprite->stopCurrentAnimation();
				} else {
					m_sprite->playAnimation("default");
				}
			}
		}
		
		m_sprite->update(deltaTime);
	}
	
	void GameObject::draw(Engine& engine, Camera& camera)
	{
		int x = (m_x) - camera.getLeft() - (getSpriteWidth() / 2);
		int y = (m_y) - camera.getTop() - (getSpriteHeight() / 2);
		/*
		Rectangle rectangle(x, y, 32, 32);
		engine.drawRectangle(rectangle, 255, 0, 0);
		*/
		if (m_sprite) {
			m_sprite->draw(engine, x, y);
		}
		/*
		list<Rectangle*>::iterator it = m_collisionRectangles.begin();
		for ( ; it != m_collisionRectangles.end(); it++) {
			double rectX = (*it)->getX() - camera.getLeft();
			double rectY = (*it)->getY() - camera.getTop();
			Rectangle rectangle(rectX, rectY, (*it)->getWidth(), (*it)->getHeight());
			engine.drawRectangle(rectangle, 255, 0, 0);
		}
		*/
	}
	
	void GameObject::clearCollisionRectangles()
	{
		list<Rectangle*>::iterator it = m_collisionRectangles.begin();
		for ( ; it != m_collisionRectangles.end(); it++) {
			Rectangle* rectangle = *it;
			delete rectangle;
		}
	}
	
	void GameObject::addCollisionRectangle(Rectangle* rectangle)
	{
		m_collisionRectangles.push_back(rectangle);
	}
	
	list<Rectangle*>& GameObject::getCollisionRectangles()
	{
		return m_collisionRectangles;
	}
	
	void GameObject::setSpriteAnimation(const string& name)
	{
		m_sprite->playAnimation(name);
	}
};
