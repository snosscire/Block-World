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
	
	void DefaultCollidingBehavior::perform(GameObject& object, unsigned int deltaTime)
	{
		int objectWidth = object.getSpriteWidth();
		int objectHeight = object.getSpriteHeight();
		
		double oldX = object.getX();
		double oldY = object.getY();
		double newX = object.getX();
		double newY = object.getY();
		
		newX += (object.getVelocityX() * (deltaTime / 10.0));
		newY += (object.getVelocityY() * (deltaTime / 10.0));
		
		double oldLeft = oldX - (objectWidth / 2);
		double oldTop = oldY - (objectHeight / 2);
		double newLeft = newX - (objectWidth / 2);
		double newTop = newY - (objectHeight / 2);
		
		BlockWorld::World* world = object.getWorld();
		
		
		if (!world->haveCollision(newLeft, newTop, objectWidth, objectHeight)) {
			object.setX(newX);
			object.setY(newY);
			object.setTouchingGround(false);
		} else {
			if (!world->haveCollision(newLeft, oldTop, objectWidth, objectHeight)) {
				object.setX(newX);
				object.setTouchingGround(true);
			} else {
				if (!world->haveCollision(oldLeft, newTop, objectWidth, objectHeight)) {
					object.setY(newY);
					object.setTouchingGround(false);
				} else {
					object.setTouchingGround(true);
				}
			}
		}
		
	}
};
