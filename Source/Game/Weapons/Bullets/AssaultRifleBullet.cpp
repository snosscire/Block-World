#include "AssaultRifleBullet.h"
#include "../../GameObject.h"
#include "../../World.h"
#include "../../Block.h"

namespace BlockWorld {
	AssaultRifleBullet::AssaultRifleBullet(Engine& engine, World& world, GameObject& owner, double x, double y, double angle):
		Bullet(engine.loadImage("Resources/Weapons/Bullets/assault.png"), world, owner, x, y, angle, 4.0)
	{
	}
	
	AssaultRifleBullet::~AssaultRifleBullet()
	{
	}
	
	void AssaultRifleBullet::doDamage(GameObject& object)
	{
	}
	
	void AssaultRifleBullet::doDamage(Block& block)
	{
		Block* takenBlock = m_world->takeBlock(block.getX(), block.getY());
		delete takenBlock;
	}
};

