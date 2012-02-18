#include "Player.h"

#include "../World.h"

#include "../ObjectBehaviors/DefaultMovingBehavior.h"
#include "../ObjectBehaviors/DefaultFallingBehavior.h"
#include "../ObjectBehaviors/DefaultJumpingBehavior.h"
#include "../ObjectBehaviors/DefaultCollidingBehavior.h"

namespace BlockWorld {
	Player::Player(World& world, unsigned int x, unsigned int y) :
		GameObject(world)
	{
		m_x = x;
		m_y = y;
		m_movingBehavior = new DefaultMovingBehavior();
		m_jumpingBehavior = new DefaultJumpingBehavior();
		m_fallingBehavior = new DefaultFallingBehavior();
		m_collidingBehavior = new DefaultCollidingBehavior();
	}
	
	Player::~Player()
	{
	}
};