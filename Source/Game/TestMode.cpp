#include "TestMode.h"
#include "Game.h"
#include "MouseScrollCamera.h"
#include "FollowObjectCamera.h"
#include "WorldGenerator.h"
#include "DefaultBlockFactory.h"
#include "Objects/Player.h"
#include "PlayerController.h"

#include <iostream>

namespace BlockWorld {
	TestMode::TestMode() :
		GameMode(),
		m_world(NULL),
		m_camera(NULL),
		m_player(NULL)
	{
	}
	
	TestMode::TestMode(Game* game) :
		GameMode(game),
		m_world(NULL),
		m_camera(NULL),
		m_player(NULL)
	{
	}
	
	TestMode::~TestMode()
	{
	}
	
	void TestMode::performStart()
	{
		WorldGenerator* worldGenerator = new WorldGenerator();
		BlockFactory* blockFactory = new DefaultBlockFactory();
		Engine* engine = m_game->getEngine();
		engine->registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
		m_world = worldGenerator->createWorld(*engine, *blockFactory, 60, 30);
		m_player = new Player(*engine, *m_world, 20, 20);
		m_player->setController(new PlayerController(*m_player, *engine));
		m_camera = new FollowObjectCamera(*m_world, *m_player, *engine);
		delete blockFactory;
		delete worldGenerator;
	}
	
	void TestMode::performStop()
	{
		delete m_world;
		m_world = NULL;
		delete m_camera;
		m_camera = NULL;
	}
	
	void TestMode::performUpdate(double deltaTime)
	{
		m_player->update(deltaTime);
	}
	
	void TestMode::performDraw()
	{
		Engine* engine = m_game->getEngine();
		m_world->draw(*engine, *m_camera);
		m_player->draw(*engine, *m_camera);
	}
	
	void TestMode::onKeyboardButtonDown(KeyboardButtonEvent& event)
	{
		if( event.getButton() == KEYBOARD_BUTTON_ESCAPE )
		{
			m_game->quit();
		}
	}
};
