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
#include "MapDirectory.h"
#include "ImageMapWorldCreator.h"
#include "WorldBackground.h"

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
		Engine* engine = m_game->getEngine();
		engine->registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
				
		//MapLoader* mapLoader = new MapLoader();
		//mapLoader->loadDirectory("Resources/Maps");
		
		MapDirectory* mapDirectory = new MapDirectory("Resources/Maps/test1", "test1", "Resources/Maps/test1/map.png");
		mapDirectory->setXMLPath("Resources/Maps/test1/map.xml");
		
		ImageMapWorldCreator* worldCreator = new ImageMapWorldCreator();
		m_world = worldCreator->createWorld(*engine, *mapDirectory);
		
		Position* spawnPosition = m_world->getRandomOpenPosition(*engine, 64, 64);
		
		m_player = new Player(*engine, *m_world, spawnPosition->getX() + 32, spawnPosition->getY() + 32);
		m_player->setController(new PlayerController(*m_player, *engine));
		m_camera = new FollowObjectCamera(*m_world, *m_player, *engine);
		m_crosshair = new Crosshair(engine->loadImage("Resources/crosshair.png"), *m_player, *engine);
		
		delete spawnPosition;
		delete mapDirectory;
		delete worldCreator;
		//delete mapLoader;		
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
