#include "DefaultCollidingBehavior.h"

#include "../GameObject.h"
#include "../World.h"

#include <iostream>

namespace BlockWorld {
	DefaultCollidingBehavior::DefaultCollidingBehavior() :
		ObjectBehavior()
	{
	}
	
	DefaultCollidingBehavior::~DefaultCollidingBehavior()
	{
	}
	
	void DefaultCollidingBehavior::perform(GameObject& object, double deltaTime)
	{
		BlockWorld::World* world = object.getWorld();
		list<Rectangle*>& objectRectangles = object.getCollisionRectangles();
		
		bool haveCollisionOnX = false;
		bool haveCollisionOnY = false;
		bool objectIsTouchingGround = false;
		
		double oldX = object.getX();
		double oldY = object.getY();
		double newX = object.getX();
		double newY = object.getY();
		double xChange = 0.0;
		double yChange = 0.0;
		
		newX += (object.getVelocityX() * (deltaTime / 10.0));
		newY += (object.getVelocityY() * (deltaTime / 10.0));
		
		xChange = newX - oldX;
		yChange = newY - oldY;
		
		std::list<Rectangle*>::const_iterator it;
		it = objectRectangles.begin();
		
		for ( ; it != objectRectangles.end(); it++) {
			double oldLeft = (*it)->getX();
			double oldTop = (*it)->getY();
			double newLeft = oldLeft + xChange;
			double newTop = oldTop + yChange;
			
			double width = (*it)->getWidth();
			double height = (*it)->getHeight();
			
			if (world->haveCollision(newLeft, oldTop, width, height)) {
				haveCollisionOnX = true;
			}
			if (world->haveCollision(oldLeft, newTop, width, height)) {
				haveCollisionOnY = true;
				objectIsTouchingGround = true;
			}
		}
		
		if (!haveCollisionOnX) {
			object.setX(newX);
		}
		if (!haveCollisionOnY) {
			object.setY(newY);
		}
		object.setTouchingGround(objectIsTouchingGround);
	}
};
