#include "DefaultMovingBehavior.h"

#include "../GameObject.h"

namespace BlockWorld {
	DefaultMovingBehavior::DefaultMovingBehavior() :
		ObjectBehavior()
	{
	}
	
	DefaultMovingBehavior::~DefaultMovingBehavior()
	{
	}
	
	void DefaultMovingBehavior::perform(GameObject& object, unsigned int deltaTime)
	{
		object.setVelocityX(0.0);
		
		if (object.wantToMoveLeft()) {
			object.setVelocityX(-2.0);
		} else if (object.wantToMoveRight()) {
			object.setVelocityX(2.0);
		}
	}
};