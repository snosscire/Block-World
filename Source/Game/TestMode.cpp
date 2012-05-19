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
#include "Config.h"
#include "GibResourceLoader.h"
#include "Effects.h"
#include "Weapons/AssaultRifle.h"

#include <iostream>

namespace BlockWorld {
	TestMode::TestMode() :
		GameMode(),
		m_map(NULL),
		m_world(NULL),
		m_camera(NULL),
		m_player(NULL),
		m_crosshair(NULL),
		m_gibLoader(NULL),
		m_gibs(),
		m_weapon(NULL)
	{
	}
	
	TestMode::TestMode(Game* game) :
		GameMode(game),
		m_map(NULL),
		m_world(NULL),
		m_camera(NULL),
		m_player(NULL),
		m_crosshair(NULL),
		m_gibLoader(NULL),
		m_gibs(),
		m_weapon(NULL)
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
		
			Position* spawnPosition = m_world->getRandomOpenPosition(*engine, 96, 96);
		
			m_player = new Player(*engine, *m_world, spawnPosition->getX() + 48, spawnPosition->getY() + 48);
			m_player->setCanTakeDamage(true);
			m_player->setController(new PlayerController(*m_player, *engine, *m_world));
			m_camera = new FollowObjectCamera(*m_world, *m_player, *engine);
			m_crosshair = new Crosshair(engine->loadImage("Resources/crosshair.png"), *m_player, *engine);
			m_weapon = new AssaultRifle(*engine, *m_world, *m_player);
			
			m_player->setWeapon(*m_weapon);
			
			delete spawnPosition;
			delete worldCreator;
			
			m_gibLoader = new GibResourceLoader(*engine);
			m_gibLoader->loadFile("Resources/Gibs/gibs.xml");
		}
	}
	
	void TestMode::performStop()
	{
		Engine* engine = m_game->getEngine();
		engine->unregisterEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
		
		if (m_player) {
			delete m_player;
			m_player = NULL;
		}
		if (m_world) {
			delete m_world;
			m_world = NULL;
		}
		if (m_camera) {
			delete m_camera;
			m_camera = NULL;
		}
		if (m_crosshair) {
			delete m_crosshair;
			m_crosshair = NULL;
		}
		if (m_gibLoader) {
			delete m_gibLoader;
			m_gibLoader = NULL;
		}
		if (m_weapon) {
			delete m_weapon;
			m_weapon = NULL;
		}
		
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
				Effects::bloodSplash(*engine, *m_gibLoader, m_gibs, *m_world, m_player->getX(), m_player->getY());
			}
		}
		// Kill player in Explosion
		else if (event.getButton() == KEYBOARD_BUTTON_F3) {
			
		}
	}
};

