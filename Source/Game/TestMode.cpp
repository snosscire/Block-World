#include "TestMode.h"
#include "Game.h"
#include "MouseScrollCamera.h"
#include "FollowObjectCamera.h"
#include "WorldGenerator.h"
#include "DefaultBlockFactory.h"
#include "Objects/Player.h"
#include "PlayerController.h"
#include "Crosshair.h"
#include "MapLoader.h"

#include <iostream>

namespace BlockWorld {
	TestMode::TestMode() :
		GameMode(),
		m_world(NULL),
		m_camera(NULL),
		m_player(NULL),
		m_crosshair(NULL)
	{
	}
	
	TestMode::TestMode(Game* game) :
		GameMode(game),
		m_world(NULL),
		m_camera(NULL),
		m_player(NULL),
		m_crosshair(NULL)
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
		m_crosshair = new Crosshair(engine->loadImage("Resources/crosshair.png"), *m_player, *engine);
		delete blockFactory;
		delete worldGenerator;
		
		cout << "-> MapLoader" << endl;
		
		MapLoader* mapLoader = new MapLoader();
		mapLoader->loadDirectory("./Resources/Maps");
		delete mapLoader;
		
		cout << "<- Map Loader" << endl;
	}
	
	void TestMode::performStop()
	{
		delete m_player;
		m_player = NULL;
		delete m_world;
		m_world = NULL;
		delete m_camera;
		m_camera = NULL;
		delete m_crosshair;
		m_crosshair = NULL;
	}
	
	void TestMode::performUpdate(double deltaTime)
	{
		m_player->update(deltaTime);
		m_crosshair->update();
	}
	
	void TestMode::performDraw()
	{
		Engine* engine = m_game->getEngine();
		m_world->draw(*engine, *m_camera);
		m_player->draw(*engine, *m_camera);
		m_crosshair->draw();
	}
	
	void TestMode::onKeyboardButtonDown(KeyboardButtonEvent& event)
	{
		if( event.getButton() == KEYBOARD_BUTTON_ESCAPE )
		{
			m_game->quit();
		}
	}
};
