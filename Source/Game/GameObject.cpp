#include "GameObject.h"
#include "GameNetworkClient.h"
#include "World.h"
#include "ObjectBehavior.h"
#include "ObjectController.h"
#include "Camera.h"
#include "Config.h"

#include "../Engine/Square.h"

#include <iostream>

namespace BlockWorld {
	GameObject::GameObject() :
		m_world(NULL),
		m_x(0.0),
		m_y(0.0),
		m_screenX(0.0),
		m_screenY(0.0),
		m_velocityX(0.0),
		m_velocityY(0.0),
		m_moveLeft(false),
		m_moveRight(false),
		m_jump(false),
		m_jumping(false),
		m_touchingGround(false),
		m_health(1),
		m_movingBehavior(NULL),
		m_jumpingBehavior(NULL),
		m_fallingBehavior(NULL),
		m_collidingBehavior(NULL),
		m_controller(NULL),
		m_sprite(NULL),
		m_collisionRectangles(),
		m_nextNetworkUpdate(0.0),
		m_networkID(0)
	{
	}

	GameObject::GameObject(World& world) :
		m_world(&world),
		m_x(0.0),
		m_y(0.0),
		m_screenX(0.0),
		m_screenY(0.0),
		m_velocityX(0.0),
		m_velocityY(0.0),
		m_moveLeft(false),
		m_moveRight(false),
		m_jump(false),
		m_jumping(false),
		m_touchingGround(false),
		m_health(1),
		m_movingBehavior(NULL),
		m_jumpingBehavior(NULL),
		m_fallingBehavior(NULL),
		m_collidingBehavior(NULL),
		m_controller(NULL),
		m_sprite(NULL),
		m_collisionRectangles(),
		m_nextNetworkUpdate(0.0),
		m_networkID(0)
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
	
	int GameObject::getNetworkID()
	{
		return m_networkID;
	}
	
	double GameObject::getX()
	{
		return m_x;
	}
	
	double GameObject::getY()
	{
		return m_y;
	}
	
	double GameObject::getWorldX()
	{
		return m_x;
	}
	
	double GameObject::getWorldY()
	{
		return m_y;
	}
	
	double GameObject::getScreenX()
	{
		return m_screenX;
	}
	
	double GameObject::getScreenY()
	{
		return m_screenY;
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
		
		list<Square*>::iterator it;
		it = m_collisionRectangles.begin();
		for ( ; it != m_collisionRectangles.end(); it++) {
			(*it)->setX((*it)->getX() + change);
		}
	}
	
	void GameObject::setY(double y)
	{
		double change = y - m_y;
		m_y = y;
		
		list<Square*>::iterator it;
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
	
	void GameObject::spriteUpdate(double currentTime, double deltaTime)
	{
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
	
	void GameObject::update(double currentTime, double deltaTime, GameNetworkClient* network)
	{
		/*
		bool moveLeft = m_moveLeft;
		bool moveRight = m_moveRight;
		bool jump = m_jump;
		*/
		
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
		
		spriteUpdate(currentTime, deltaTime);
		
		if (network) {
			if (currentTime >= m_nextNetworkUpdate /* || moveLeft || moveRight || jump */) {
				network->sendUpdate(*this /* , moveLeft, moveRight, jump */ );
				//std::cout << "Current time: " << currentTime << std::endl;
				//std::cout << "Next update:  " << m_nextNetworkUpdate << std::endl;
				double overflow = (m_nextNetworkUpdate > 0 ? currentTime - m_nextNetworkUpdate : 0);
				m_nextNetworkUpdate = currentTime + (33 - overflow);
				//std::cout << "Overflow:     " << overflow << std::endl;
				//std::cout << "Next update:  " << m_nextNetworkUpdate << std::endl;
			} else {
				//std::cout << "Not yet time to send update. (" << currentTime << ") (" << m_nextNetworkUpdate << ")" << std::endl;
			}
		}
	}
	
	void GameObject::draw(Engine& engine, Camera& camera)
	{
		int x = (m_x) - camera.getLeft() - (getSpriteWidth() / 2);
		int y = (m_y) - camera.getTop() - (getSpriteHeight() / 2);
		/*
		Square rectangle(x, y, 32, 32);
		engine.drawSquare(rectangle, 255, 0, 0);
		*/
		if (m_sprite) {
			m_sprite->draw(engine, x, y);
		}
		
		if (Config::DrawHitBoxes) {
			list<Square*>::iterator it = m_collisionRectangles.begin();
			for ( ; it != m_collisionRectangles.end(); it++) {
				double rectX = (*it)->getX() - camera.getLeft();
				double rectY = (*it)->getY() - camera.getTop();
				Square rectangle(rectX, rectY, (*it)->getWidth(), (*it)->getHeight());
				engine.drawSquare(rectangle, 255, 0, 0);
			}
		}
		
		m_screenX = x;
		m_screenY = y;
	}
	
	void GameObject::clearCollisionRectangles()
	{
		list<Square*>::iterator it = m_collisionRectangles.begin();
		for ( ; it != m_collisionRectangles.end(); it++) {
			Square* rectangle = *it;
			delete rectangle;
		}
	}
	
	void GameObject::addCollisionRectangle(Square* rectangle)
	{
		m_collisionRectangles.push_back(rectangle);
	}
	
	list<Square*>& GameObject::getCollisionRectangles()
	{
		return m_collisionRectangles;
	}
	
	void GameObject::setSpriteAnimation(const string& name)
	{
		m_sprite->playAnimation(name);
	}
	
	const string& GameObject::getCurrentSpriteAnimation()
	{
		return m_sprite->getCurrentAnimationName();
	}
	
	void GameObject::setHealth(int health)
	{
		m_health = health;
	}
	
	bool GameObject::takeDamage(int damage)
	{
		m_health -= damage;
		if (m_health <= 0)
			return true;
		return false;
	}
	
	bool GameObject::isAlive()
	{
		if (m_health > 0)
			return true;
		return false;
	}
};
