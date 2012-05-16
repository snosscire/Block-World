#include "GibMovingBehavior.h"

#include "../GameObject.h"

namespace BlockWorld {
	GibMovingBehavior::GibMovingBehavior() :
		ObjectBehavior()
	{
	}
	
	GibMovingBehavior::~GibMovingBehavior()
	{
	}
	
	void GibMovingBehavior::perform(GameObject& object, double deltaTime)
	{
		double velocity = object.getVelocityX();
		
		if (velocity > 0.0) {
			velocity -= (deltaTime * 0.01);
			if (velocity < 0.0) {
				velocity = 0.0;
			}
		} else if (velocity < 0.0) {
			velocity += (deltaTime * 0.01);
			if (velocity > 0.0) {
				velocity = 0.0;
			}
		}
		
		object.setVelocityX(velocity);
	}
};

