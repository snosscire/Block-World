#include "DefaultJumpingBehavior.h"

#include "../GameObject.h"

namespace BlockWorld {
	DefaultJumpingBehavior::DefaultJumpingBehavior() :
		ObjectBehavior()
	{
	}
	
	DefaultJumpingBehavior::~DefaultJumpingBehavior()
	{
	}
	
	void DefaultJumpingBehavior::perform(GameObject& object, double deltaTime)
	{
		if (object.wantToJump()) {
			object.setJump(false);
			if (!object.isJumping() && object.isTouchingGround()) {
				object.setVelocityY(-8.0);
				object.setJumping(true);
			}
		} else if (object.isJumping()) {
			if (object.isTouchingGround()) {
				object.setJumping(false);
			}
		}
	}
}
