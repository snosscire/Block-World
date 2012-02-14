#include "DefaultCollidingBehavior.h"

#include "../GameObject.h"
#include "../../Game/World.h"

namespace BadEngine {
	DefaultCollidingBehavior::DefaultCollidingBehavior() :
		ObjectBehavior()
	{
	}
	
	DefaultCollidingBehavior::~DefaultCollidingBehavior()
	{
	}
	
	void DefaultCollidingBehavior::perform(GameObject& object, unsigned int deltaTime)
	{
		unsigned int objectWidth = object.getSpriteWidth();
		unsigned int objectHeight = object.getSpriteHeight();
		
		double oldX = object.getX();
		double oldY = object.getY();
		double newX = object.getX();
		double newY = object.getY();
		
		newX += (object.getVelocityX() * (deltaTime / 10.0));
		newY += (object.getVelocityY() * (deltaTime / 10.0));
		
		unsigned int oldLeft = oldX - (objectWidth / 2);
		unsigned int oldTop = oldY - (objectHeight / 2);
		unsigned int newLeft = newX - (objectWidth / 2);
		unsigned int newTop = newY - (objectHeight / 2);
		
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
