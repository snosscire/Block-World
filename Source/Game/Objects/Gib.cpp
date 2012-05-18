#include "Gib.h"

#include "../../Engine/Engine.h"
#include "../../Engine/Sprite.h"
#include "../../Engine/Animation.h"
#include "../../Engine/AnimationFrame.h"
#include "../../Engine/Image.h"

#include "../Config.h"
#include "../World.h"

#include "../ObjectBehaviors/GibMovingBehavior.h"
#include "../ObjectBehaviors/DefaultFallingBehavior.h"
#include "../ObjectBehaviors/DefaultCollidingBehavior.h"

#include <iostream>

using namespace std;

namespace BlockWorld {
	Gib::Gib(Engine& engine, Image* image, World& world, double x, double y) :
		GameObject(world)
	{
		m_x = x;
		m_y = y;
		
		initialize(engine, image, x, y);
	}
	
	Gib::~Gib()
	{
	}
	
	void Gib::initialize(Engine& engine, Image* image, double x, double y)
	{
		m_jumping = true;
		m_velocityX = engine.getRandomNumber(-Config::GibMaxSpeedX, Config::GibMaxSpeedX);
		m_velocityY = engine.getRandomNumber(-Config::GibMaxSpeedY, Config::GibMaxSpeedY);
		
		m_movingBehavior = new GibMovingBehavior();
		m_fallingBehavior = new DefaultFallingBehavior();
		m_collidingBehavior = new DefaultCollidingBehavior();
		
		m_sprite = new Sprite();
		
		double angle = 0.0;
		
		int rotation = engine.getRandomNumber(1, 4);
		switch (rotation) {
			case 4:          angle = 270.0; break;
			case 3:          angle = 180.0; break;
			case 2:          angle =  90.0; break;
			case 1: default: angle =   0.0; break;
		}
		
		Image* rotatedImage = image->rotate(angle);
		delete image;
		image = rotatedImage;
		
		Animation* defaultAnimation = new Animation();
		defaultAnimation->addFrame(new AnimationFrame(100.0, image));
		
		m_sprite->addAnimation("default", defaultAnimation);
		m_sprite->playAnimation("default");

		addCollisionRectangle(new Square(x - (image->getWidth() / 2), y - (image->getHeight() / 2), image->getWidth(), image->getHeight()));
	}
};

