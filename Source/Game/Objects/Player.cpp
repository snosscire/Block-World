#include "Player.h"

#include "../../Engine/Engine.h"
#include "../../Engine/Sprite.h"
#include "../../Engine/Animation.h"
#include "../../Engine/AnimationFrame.h"

#include "../World.h"

#include "../ObjectBehaviors/DefaultMovingBehavior.h"
#include "../ObjectBehaviors/DefaultFallingBehavior.h"
#include "../ObjectBehaviors/DefaultJumpingBehavior.h"
#include "../ObjectBehaviors/DefaultCollidingBehavior.h"

namespace BlockWorld {
	Player::Player(Engine& engine, World& world, double x, double y) :
		GameObject(world)
	{
		m_x = x;
		m_y = y;
		
		initialize(engine, x, y);
	}
	
	Player::Player(int networkID, Engine& engine, World& world, double x, double y) :
		GameObject(world)
	{
		m_networkID = networkID;
		
		m_x = x;
		m_y = y;
		
		initialize(engine, x, y);
	}
	
	Player::~Player()
	{
	}
	
	void Player::initialize(Engine& engine, double x, double y)
	{
		m_movingBehavior = new DefaultMovingBehavior();
		m_jumpingBehavior = new DefaultJumpingBehavior();
		m_fallingBehavior = new DefaultFallingBehavior();
		m_collidingBehavior = new DefaultCollidingBehavior();

		addCollisionRectangle(new Rectangle(x - 16.0, y - 15.0, 32.0, 32.0));
		addCollisionRectangle(new Rectangle(x - 8.0, y + 17.0, 16.0, 4.0));
		
		m_sprite = new Sprite();
		
		Animation* defaultAnimation = new Animation();
		defaultAnimation->addFrame(new AnimationFrame(100.0, engine.loadImage("Resources/test-player.png")));
		
		Animation* runAnimation = new Animation();
		runAnimation->addFrame(new AnimationFrame(50.0, engine.loadImage("Resources/blockworld-character-run/blockworld-character-run-00.png")));
		runAnimation->addFrame(new AnimationFrame(50.0, engine.loadImage("Resources/blockworld-character-run/blockworld-character-run-01.png")));
		runAnimation->addFrame(new AnimationFrame(50.0, engine.loadImage("Resources/blockworld-character-run/blockworld-character-run-02.png")));
		runAnimation->addFrame(new AnimationFrame(50.0, engine.loadImage("Resources/blockworld-character-run/blockworld-character-run-03.png")));
		runAnimation->addFrame(new AnimationFrame(50.0, engine.loadImage("Resources/blockworld-character-run/blockworld-character-run-04.png")));
		runAnimation->addFrame(new AnimationFrame(50.0, engine.loadImage("Resources/blockworld-character-run/blockworld-character-run-05.png")));
		runAnimation->addFrame(new AnimationFrame(50.0, engine.loadImage("Resources/blockworld-character-run/blockworld-character-run-06.png")));
		runAnimation->addFrame(new AnimationFrame(50.0, engine.loadImage("Resources/blockworld-character-run/blockworld-character-run-07.png")));
		runAnimation->addFrame(new AnimationFrame(50.0, engine.loadImage("Resources/blockworld-character-run/blockworld-character-run-08.png")));
		
		Animation* jumpAnimation = new Animation();
		jumpAnimation->addFrame(new AnimationFrame(100.0, engine.loadImage("Resources/test-player-jump.png")));
		
		m_sprite->addAnimation("default", defaultAnimation);
		m_sprite->addAnimation("run", runAnimation);
		m_sprite->addAnimation("jump", jumpAnimation);
		
		m_sprite->playAnimation("default");
	}
};
