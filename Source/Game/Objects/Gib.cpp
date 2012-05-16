#include "Gib.h"

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
	Gib::Gib(Engine& engine, World& world, double x, double y) :
		GameObject(world)
	{
		m_x = x;
		m_y = y;
		
		initialize(engine, x, y);
	}
	
	Gib::~Gib()
	{
	}
	
	void Gib::initialize(Engine& engine, double x, double y)
	{
		m_jumping = true;
		m_velocityX = engine.getRandomNumber(-Config::GibMaxSpeedX, Config::GibMaxSpeedX);
		m_velocityY = engine.getRandomNumber(-Config::GibMaxSpeedY, Config::GibMaxSpeedY);
		
		m_movingBehavior = new GibMovingBehavior();
		m_fallingBehavior = new DefaultFallingBehavior();
		m_collidingBehavior = new DefaultCollidingBehavior();
		
		addCollisionRectangle(new Square(x - 11.0, y - 11.0, 23.0, 23.0));
		
		m_sprite = new Sprite();
		
		int type = engine.getRandomNumber(1, 3);
		
		Image* image = NULL;
		switch (type) {
			case 3:          image = engine.loadImage("Resources/Gibs/skull-gib-03.png"); break;
			case 2:          image = engine.loadImage("Resources/Gibs/skull-gib-02.png"); break;
			case 1: default: image = engine.loadImage("Resources/Gibs/skull-gib-01.png"); break;
		}
		
		Animation* defaultAnimation = new Animation();
		defaultAnimation->addFrame(new AnimationFrame(100.0, image));
		
		m_sprite->addAnimation("default", defaultAnimation);
		m_sprite->playAnimation("default");
	}
};

