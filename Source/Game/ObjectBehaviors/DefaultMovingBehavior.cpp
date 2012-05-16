#include "DefaultMovingBehavior.h"

#include "../Config.h"
#include "../GameObject.h"

namespace BlockWorld {
	DefaultMovingBehavior::DefaultMovingBehavior() :
		ObjectBehavior()
	{
	}
	
	DefaultMovingBehavior::~DefaultMovingBehavior()
	{
	}
	
	void DefaultMovingBehavior::perform(GameObject& object, double deltaTime)
	{
		object.setVelocityX(0.0);
		
		if (object.wantToMoveLeft()) {
			object.setVelocityX(-Config::PlayerMoveSpeed);
		} else if (object.wantToMoveRight()) {
			object.setVelocityX(Config::PlayerMoveSpeed);
		}
	}
};
