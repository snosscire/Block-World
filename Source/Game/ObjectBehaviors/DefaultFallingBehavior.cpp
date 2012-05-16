#include "DefaultFallingBehavior.h"

#include "../Config.h"
#include "../GameObject.h"

namespace BlockWorld {
	DefaultFallingBehavior::DefaultFallingBehavior() :
		ObjectBehavior()
	{
	}
	
	DefaultFallingBehavior::~DefaultFallingBehavior()
	{
	}
	
	void DefaultFallingBehavior::perform(GameObject& object, double deltaTime)
	{
		if (object.isJumping()) {
			if (!object.isTouchingGround()) {
				double velocity = object.getVelocityY();
				double change = (Config::DefaultGravity * (deltaTime / 100.0));
				velocity += change;
				if (velocity > Config::DefaultGravity ) {
					velocity = Config::DefaultGravity ;
				}
				object.setVelocityY(velocity);
			}	
		} else {
			object.setVelocityY(Config::DefaultGravity );
		}
	}
};
