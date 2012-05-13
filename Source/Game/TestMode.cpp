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
		//WorldGenerator* worldGenerator = new WorldGenerator();
		//BlockFactory* blockFactory = new DefaultBlockFactory();
		Engine* engine = m_game->getEngine();
		engine->registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
		
		//m_world = worldGenerator->createWorld(*engine, *blockFactory, 60, 30);
		
		//MapLoader* mapLoader = new MapLoader();
		//mapLoader->loadDirectory("Resources/Maps");
		
		MapDirectory* mapDirectory = new MapDirectory("Resources/Maps/test1", "test1", "Resources/Maps/test1/map.png");
		
		ImageMapWorldCreator* worldCreator = new ImageMapWorldCreator();
		m_world = worldCreator->createWorld(*engine, mapDirectory->getImagePath(), mapDirectory->getXMLPath());
		
		Image* backgroundImage = NULL;
		backgroundImage = engine->loadImage("Resources/Maps/test1/background1.png");
		m_world->addBackground(new WorldBackground(0, 0, 0, 0.0, *backgroundImage));
		backgroundImage = engine->loadImage("Resources/Maps/test1/background2.png");
		m_world->addBackground(new WorldBackground(1, 0, 0, 0.5, *backgroundImage));
		
		
		Position* spawnPosition = m_world->getRandomOpenPosition(*engine, 64, 64);
		
		m_player = new Player(*engine, *m_world, spawnPosition->getX(), spawnPosition->getY());
		m_player->setController(new PlayerController(*m_player, *engine));
		m_camera = new FollowObjectCamera(*m_world, *m_player, *engine);
		m_crosshair = new Crosshair(engine->loadImage("Resources/crosshair.png"), *m_player, *engine);
		
		//delete blockFactory;
		//delete worldGenerator;
		
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
