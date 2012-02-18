#include "DefaultFallingBehavior.h"

#include "../BlockWorld.h"
#include "../GameObject.h"

namespace BlockWorld {
	DefaultFallingBehavior::DefaultFallingBehavior() :
		ObjectBehavior()
	{
	}
	
	DefaultFallingBehavior::~DefaultFallingBehavior()
	{
	}
	
	void DefaultFallingBehavior::perform(GameObject& object, unsigned int deltaTime)
	{
		if (object.isJumping()) {
			if (!object.isTouchingGround()) {
				double velocity = object.getVelocityY();
				double change = (BlockWorld::DEFAULT_GRAVITY * (deltaTime / 100.0));
				velocity += change;
				if (velocity > BlockWorld::DEFAULT_GRAVITY) {
					velocity = BlockWorld::DEFAULT_GRAVITY;
				}
				object.setVelocityY(velocity);
			}	
		} else {
			object.setVelocityY(BlockWorld::DEFAULT_GRAVITY);
		}
	}
};