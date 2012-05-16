#include "TestMode.h"
#include "Game.h"
#include "MouseScrollCamera.h"
#include "FollowObjectCamera.h"
#include "WorldGenerator.h"
#include "DefaultBlockFactory.h"
#include "Objects/Player.h"
#include "Objects/Gib.h"
#include "Objects/Blood.h"
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
		m_crosshair(NULL),
		m_gibs()
	{
	}
	
	TestMode::TestMode(Game* game) :
		GameMode(game),
		m_map(NULL),
		m_world(NULL),
		m_camera(NULL),
		m_player(NULL),
		m_crosshair(NULL),
		m_gibs()
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
			m_player->setController(new PlayerController(*m_player, *engine, *m_world));
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
		
		while (!m_gibs.empty()) {
			GameObject* gib = m_gibs.front();
			m_gibs.pop_front();
			delete gib;
		}
	}
	
	void TestMode::performUpdate(double currentTime, double deltaTime)
	{
		deque<GameObject*>::reverse_iterator it = m_gibs.rbegin();
		for ( ; it != m_gibs.rend(); it++) {
			(*it)->update(currentTime, deltaTime, NULL);
		}
		
		m_player->update(currentTime, deltaTime, NULL);
		m_crosshair->update();
	}
	
	void TestMode::performDraw()
	{
		Engine* engine = m_game->getEngine();
		m_world->draw(*engine, *m_camera);
		
		deque<GameObject*>::iterator it = m_gibs.begin();
		for ( ; it != m_gibs.end(); it++) {
			(*it)->draw(*engine, *m_camera);
		}
		
		if (m_player->isAlive()) {
			m_player->draw(*engine, *m_camera);
			m_crosshair->draw();
		}
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
		// Kill player
		else if (event.getButton() == KEYBOARD_BUTTON_F2) {
			if (m_player->isAlive() && m_player->takeDamage(9999)) {
				Engine* engine = m_game->getEngine();
				
				Gib* gib = new Gib(*engine, *m_world, m_player->getX(), m_player->getY(), engine->getRandomNumber(1, 3));
				m_gibs.push_back(gib);
				
				for (int i = 0; i < 20; i++) {
					double x = m_player->getX() - engine->getRandomNumber(-6, 6);
					double y = m_player->getY() - engine->getRandomNumber(-6, 6);
					Blood* blood = new Blood(*engine, *m_world, x, y);
					m_gibs.push_back(blood);
				}
				
				while (m_gibs.size() > 500) {
					GameObject* object = m_gibs.front();
					delete object;
					m_gibs.pop_front();
				}
			}
		}
		// Kill player in Explosion
		else if (event.getButton() == KEYBOARD_BUTTON_F3) {
			
		}
	}
};

