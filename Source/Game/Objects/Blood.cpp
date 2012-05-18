#include "Blood.h"

#include "../../Engine/Engine.h"
#include "../../Engine/Sprite.h"
#include "../../Engine/Animation.h"
#include "../../Engine/AnimationFrame.h"

#include "../Config.h"
#include "../World.h"

#include "../ObjectBehaviors/GibMovingBehavior.h"
#include "../ObjectBehaviors/DefaultFallingBehavior.h"
#include "../ObjectBehaviors/DefaultCollidingBehavior.h"

#include <iostream>

using namespace std;

namespace BlockWorld {
	Blood::Blood(Engine& engine, World& world, double x, double y) :
		GameObject(world)
	{
		m_x = x;
		m_y = y;
		
		initialize(engine, x, y);
	}
	
	Blood::~Blood()
	{
	}
	
	void Blood::initialize(Engine& engine, double x, double y)
	{
		m_jumping = true;
		m_velocityX = engine.getRandomNumber(-Config::BloodMaxSpeedX, Config::BloodMaxSpeedX);
		m_velocityY = engine.getRandomNumber(-Config::BloodMaxSpeedY, Config::BloodMaxSpeedY);
		
		m_movingBehavior = new GibMovingBehavior();
		m_fallingBehavior = new DefaultFallingBehavior();
		m_collidingBehavior = new DefaultCollidingBehavior();
		
		addCollisionRectangle(new Square(x - 1.0, y - 1.0, 2.0, 2.0));
		
		m_sprite = new Sprite();
		
		int type = engine.getRandomNumber(1, 2);
		
		Image* image = NULL;
		switch (type) {
			case 2:          image = engine.loadImage("Resources/Gibs/blood-02.png"); break;
			case 1: default: image = engine.loadImage("Resources/Gibs/blood-01.png"); break;
		}
		
		Animation* defaultAnimation = new Animation();
		defaultAnimation->addFrame(new AnimationFrame(100.0, image));
		
		m_sprite->addAnimation("default", defaultAnimation);
		m_sprite->playAnimation("default");
	}
};

