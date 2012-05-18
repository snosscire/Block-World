#include "AssaultRifle.h"
#include "../GameObject.h"

namespace BlockWorld {
	AssaultRifle::AssaultRifle(Engine& engine, GameObject& owner) :
		Weapon(owner)
	{
		m_image = engine.loadImage("Resources/Weapons/assault-01.png");
	}
	
	AssaultRifle::~AssaultRifle()
	{
	}
};

