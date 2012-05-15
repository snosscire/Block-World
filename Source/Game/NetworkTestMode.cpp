#include "NetworkTestMode.h"
#include "Game.h"
#include "GameNetworkClient.h"
#include "World.h"
#include "FollowObjectCamera.h"
#include "Crosshair.h"
#include "Objects/Player.h"
#include "MapDirectory.h"
#include "ImageMapWorldCreator.h"
#include "PlayerController.h"
#include "NetworkController.h"

#include "Network/ConnectMessage.h"
#include "Network/ConnectResponseMessage.h"
#include "Network/JoinMessage.h"

#include <iostream>

using namespace std;

namespace BlockWorld {
	NetworkTestMode::NetworkTestMode() :
		GameMode(),
		EventObserver(),
		NetworkObserver(),
		m_world(NULL),
		m_camera(NULL),
		m_crosshair(NULL),
		m_players(),
		m_thisPlayer(NULL)
	{
	}
	
	NetworkTestMode::NetworkTestMode(Game* game) :
		GameMode(game),
		EventObserver(),
		NetworkObserver(),
		m_world(NULL),
		m_camera(NULL),
		m_crosshair(NULL),
		m_players(),
		m_thisPlayer(NULL)
	{
	}
	
	NetworkTestMode::~NetworkTestMode()
	{
	}
	
	void NetworkTestMode::performStart()
	{
		Engine* engine = m_game->getEngine();
		
		engine->registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
		
		m_game->activateNetwork();
		
		m_game->getNetwork()->registerObserver(this);
		m_game->getNetwork()->registerMessageObserver(this);
		
		if (m_game->getNetwork()->connect("localhost", 7788)) {
			
		} else {
			
		}
	}
	
	void NetworkTestMode::performStop()
	{
		list<Player*>::iterator it = m_players.begin();
		for ( ; it != m_players.end(); it++) {
			Player* player = *it;
			delete player;
		}
		m_players.clear();
		
		m_thisPlayer = NULL;
		
		if (m_camera) {
			delete m_camera;
			m_camera = NULL;
		}
		
		if (m_world) {
			delete m_world;
			m_world = NULL;
		}
		
		if (m_crosshair) {
			delete m_crosshair;
			m_crosshair = NULL;
		}
	}
	
	void NetworkTestMode::performUpdate(double currentTime, double deltaTime)
	{
		/*
		list<Player*>::iterator it = m_players.begin();
		for ( ; it != m_players.end(); it++) {
			Player* player = *it;
			GameNetworkClient* network = (player->getNetworkID() == m_thisPlayer->getNetworkID() ? m_game->getNetwork() : NULL);
			player->update(currentTime, deltaTime, network);
		}
		*/
		
		list<Player*>::iterator it = m_players.begin();
		for ( ; it != m_players.end(); it++) {
			Player* player = *it;
			if (player->getNetworkID() != m_thisPlayer->getNetworkID()) {
				player->spriteUpdate(currentTime, deltaTime);
			}
		}
		
		if (m_thisPlayer) {
			m_thisPlayer->update(currentTime, deltaTime, m_game->getNetwork());
		}
		
		if (m_crosshair) {
			m_crosshair->update();
		}
	}
	
	void NetworkTestMode::performDraw()
	{
		Engine* engine = m_game->getEngine();
		
		if (m_world) {
			m_world->draw(*engine, *m_camera);
		}
		
		list<Player*>::iterator it = m_players.begin();
		for ( ; it != m_players.end(); it++) {
			Player* player = *it;
			player->draw(*engine, *m_camera);
		}
		
		if (m_crosshair) {
			m_crosshair->draw();
		}
	}
	
	void NetworkTestMode::onKeyboardButtonDown(KeyboardButtonEvent& event)
	{
		if (event.getButton() == KEYBOARD_BUTTON_ESCAPE) {
			m_game->quit();
		}
	}
	
	void NetworkTestMode::onConnectResponse(ConnectResponseMessage& message)
	{
		cout << "Connected." << endl;
		
		Engine* engine = m_game->getEngine();
		
		MapDirectory* mapDirectory = new MapDirectory("Resources/Maps/test1", "test1", "Resources/Maps/test1/map.png");
		mapDirectory->setXMLPath("Resources/Maps/test1/map.xml");
		
		ImageMapWorldCreator* worldCreator = new ImageMapWorldCreator();
		m_world = worldCreator->createWorld(*engine, *mapDirectory);
		
		Position* spawnPosition = m_world->getRandomOpenPosition(*engine, 64, 64);

		Player* player = new Player(message.getID(), *engine, *m_world, spawnPosition->getX() + 32, spawnPosition->getY() + 32);
		player->setController(new PlayerController(*player, *engine));
		
		m_players.push_back(player);
		m_thisPlayer = player;
			
		m_camera = new FollowObjectCamera(*m_world, *player, *engine);
		m_crosshair = new Crosshair(engine->loadImage("Resources/crosshair.png"), *player, *engine);
		
		ConnectMessage connectMessage(message.getID(), player->getX(), player->getY());
		m_game->getNetwork()->sendMessage(connectMessage);
		
		delete spawnPosition;
		delete mapDirectory;
		delete worldCreator;
	}
	
	void NetworkTestMode::onJoin(JoinMessage& message)
	{
		cout << "Received join message." << endl;
		
		// We got a new player playing with us :)
		
		Engine* engine = m_game->getEngine();
		GameNetworkClient* network = m_game->getNetwork();
		
		// First we need to create he player object
		Player* player = new Player(message.getID(), *engine, *m_world, message.getX(), message.getY());
		player->setController(new NetworkController(*player, *network));
		
		// Then we add the player to the list of players
		m_players.push_back(player);
	}
};

