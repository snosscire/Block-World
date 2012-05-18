#include "AssaultRifleBullet.h"
#include "../../GameObject.h"
#include "../../Block.h"

namespace BlockWorld {
	AssaultRifleBullet::AssaultRifleBullet(Engine& engine, GameObject& owner, double x, double y, double angle):
		Bullet(engine.loadImage("Resources/Weapons/Bullets/assault.png"), owner, x, y, angle, 4.0)
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
	}
};

