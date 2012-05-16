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
		m_map(NULL),
		m_world(NULL),
		m_camera(NULL),
		m_player(NULL),
		m_crosshair(NULL)
	{
	}
	
	TestMode::TestMode(Game* game) :
		GameMode(game),
		m_map(NULL),
		m_world(NULL),
		m_camera(NULL),
		m_player(NULL),
		m_crosshair(NULL)
	{
	}
	
	TestMode::~TestMode()
	{
		if (m_map) {
			delete m_map;
		}
	}
	
	void TestMode::performStart()
	{
		if (m_map) {
			Engine* engine = m_game->getEngine();
			engine->registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
				
			ImageMapWorldCreator* worldCreator = new ImageMapWorldCreator();
			m_world = worldCreator->createWorld(*engine, *m_map);
		
			Position* spawnPosition = m_world->getRandomOpenPosition(*engine, 64, 64);
		
			m_player = new Player(*engine, *m_world, spawnPosition->getX() + 32, spawnPosition->getY() + 32);
			m_player->setController(new PlayerController(*m_player, *engine));
			m_camera = new FollowObjectCamera(*m_world, *m_player, *engine);
			m_crosshair = new Crosshair(engine->loadImage("Resources/crosshair.png"), *m_player, *engine);
		
			delete spawnPosition;
			delete worldCreator;
		}
	}
	
	void TestMode::performStop()
	{
		Engine* engine = m_game->getEngine();
		engine->unregisterEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
		
		delete m_player;
		m_player = NULL;
		delete m_world;
		m_world = NULL;
		delete m_camera;
		m_camera = NULL;
		delete m_crosshair;
		m_crosshair = NULL;
	}
	
	void TestMode::performUpdate(double currentTime, double deltaTime)
	{
		m_player->update(currentTime, deltaTime, NULL);
		m_crosshair->update();
	}
	
	void TestMode::performDraw()
	{
		Engine* engine = m_game->getEngine();
		m_world->draw(*engine, *m_camera);
		m_player->draw(*engine, *m_camera);
		m_crosshair->draw();
	}
	
	void TestMode::setMap(MapDirectory* map)
	{
		if (m_map) {
			delete m_map;
			m_map = NULL;
		}
		m_map = map->copy();
	}
	
	void TestMode::onKeyboardButtonDown(KeyboardButtonEvent& event)
	{
		if (event.getButton() == KEYBOARD_BUTTON_ESCAPE) {
			m_game->quit();
		}
	}
};

