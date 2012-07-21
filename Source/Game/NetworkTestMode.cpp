#include "NetworkTestMode.h"
#include "Game.h"
#include "GameNetworkClient.h"
#include "World.h"
#include "MouseScrollCamera.h"
#include "FollowObjectCamera.h"
#include "Crosshair.h"
#include "Objects/Player.h"
#include "MapLoader.h"
#include "MapDirectory.h"
#include "ImageMapWorldCreator.h"
#include "PlayerController.h"
#include "NetworkController.h"
#include "Weapons/AssaultRifle.h"
#include "ObjectManager.h"
#include "GibResourceLoader.h"
#include "Effects.h"
#include "EndGameMode.h"
#include "BlockWorld.h"

#include "Network/ConnectResponseMessage.h"
#include "Network/IdentityMessage.h"
#include "Network/JoinMessage.h"
#include "Network/ReadyMessage.h"
#include "Network/LoadMapMessage.h"
#include "Network/MapLoadedMessage.h"
#include "Network/SpawnMessage.h"
#include "Network/DeathMessage.h"
#include "Network/EndGameMessage.h"

#include "Console/ReadyCommand.h"

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
		m_thisPlayer(NULL),
		m_weapon(NULL),
		m_thisNetworkID(0),
		m_thisPlayerName(),
		m_objectManager(NULL),
		m_gibLoader(NULL),
		m_gibs()
	{
	}
	
	NetworkTestMode::NetworkTestMode(Game* game) :
		GameMode(game),
		EventObserver(),
		NetworkObserver(),
		m_world(NULL),
		m_camera(NULL),
		m_crosshair(NULL),
		m_thisPlayer(NULL),
		m_weapon(NULL),
		m_thisNetworkID(0),
		m_thisPlayerName(),
		m_objectManager(NULL),
		m_gibLoader(NULL),
		m_gibs()
	{
	}
	
	NetworkTestMode::~NetworkTestMode()
	{
	}
	
	void NetworkTestMode::performStart()
	{
		Engine* engine = m_game->getEngine();
		
		engine->registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
		
		//m_game->getConsole()->registerCommand("ready", new ReadyCommand(*this));
		
		m_game->activateNetwork();
		
		m_game->getNetwork()->registerObserver(this);
		m_game->getNetwork()->registerMessageObserver(this);
		
		if (m_game->getNetwork()->connect("localhost", 7788)) {
			
		} else {
			
		}
	}
	
	void NetworkTestMode::performStop()
	{
		m_thisPlayer = NULL;
		
		if (m_objectManager) {
			delete m_objectManager;
			m_objectManager = NULL;
		}
		
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
		
		if (m_weapon) {
			delete m_weapon;
			m_weapon = NULL;
		}
		
		deque<GameObject*>::reverse_iterator it = m_gibs.rbegin();
		for ( ; it != m_gibs.rend(); it++) {
			GameObject* object = *it;
			delete object;
		}
		m_gibs.clear();
	}
	
	void NetworkTestMode::performUpdate(double currentTime, double deltaTime)
	{
		deque<GameObject*>::reverse_iterator it = m_gibs.rbegin();
		for ( ; it != m_gibs.rend(); it++) {
			(*it)->update(currentTime, deltaTime, NULL);
		}
		
		if (m_objectManager) {
			m_objectManager->spriteUpdate(currentTime, deltaTime, (m_thisPlayer ? m_thisPlayer->getNetworkID() : 0));
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
		
		deque<GameObject*>::iterator it = m_gibs.begin();
		for ( ; it != m_gibs.end(); it++) {
			(*it)->draw(*engine, *m_camera);
		}
				
		if (m_objectManager) {
			m_objectManager->draw(*engine, *m_camera);
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
		m_thisNetworkID = message.getID();
		
		IdentityMessage identityMessage(m_thisNetworkID, m_thisPlayerName);
		m_game->getNetwork()->sendMessage(identityMessage);
		
		sendReadyMessage();
	}
	
	void NetworkTestMode::onJoin(JoinMessage& message)
	{
		// We got a new player playing with us :)
		
		// TODO: We should also add the player to the lobby list
	}
	
	void NetworkTestMode::onLoadMap(LoadMapMessage& message)
	{
		performStop();
		
		MapLoader* loader = new MapLoader();
		MapDirectory* map = NULL;
		
		loader->loadDirectory("Resources/Maps");
		
		list<MapDirectory*>& maps = loader->getMaps();
		list<MapDirectory*>::iterator it = maps.begin();
		
		for ( ; it != maps.end(); it++) {
			if ((*it)->getDirectoryName().compare(message.getName()) == 0) {
				map = *it;
				break;
			}
		}
		
		if (map) {
			Engine* engine = m_game->getEngine();
			
			ImageMapWorldCreator* worldCreator = new ImageMapWorldCreator();
			m_world = worldCreator->createWorld(*engine, *map);
			
			m_camera = new MouseScrollCamera(*m_world, *engine);
			
			delete worldCreator;
			
			m_objectManager = new ObjectManager();
			
			m_gibLoader = new GibResourceLoader(*engine);
			m_gibLoader->loadFile("Resources/Gibs/gibs.xml");
			
			// If we get here the map should be successfully loaded ;)
			// Therefore we send the message to the server.
			MapLoadedMessage loaded(m_thisNetworkID);
			m_game->getNetwork()->sendMessage(loaded);
		}

		delete loader;
	}
	
	void NetworkTestMode::onStartGame(StartGameMessage& message)
	{
		// Delete the temporary camera.
		if (m_camera) {
			delete m_camera;
			m_camera = NULL;
		}
		
		Engine* engine = m_game->getEngine();
		
		Position* spawnPosition = m_world->getRandomOpenPosition(*engine, 96, 96);
		
		m_thisPlayer = new Player(m_thisNetworkID, *engine, *m_world, spawnPosition->getX() + 48, spawnPosition->getY() + 48);
		m_thisPlayer->setCanTakeDamage(true);
		m_thisPlayer->setController(new PlayerController(*m_thisPlayer, *engine, *m_world));
		m_thisPlayer->setDamageHandler(this);
		m_thisPlayer->setHealth(100);
		m_camera = new FollowObjectCamera(*m_world, *m_thisPlayer, *engine);
		m_crosshair = new Crosshair(engine->loadImage("Resources/crosshair.png"), *m_thisPlayer, *engine);
		m_weapon = new AssaultRifle(*engine, *m_world, *m_thisPlayer);
		
		m_thisPlayer->setWeapon(*m_weapon);
		
		m_objectManager->addObject(m_thisPlayer);

		delete spawnPosition;
		
		SpawnMessage spawnMessage(m_thisPlayer->getNetworkID(), m_thisPlayer->getX(), m_thisPlayer->getY());
		m_game->getNetwork()->sendMessage(spawnMessage);
	}
	
	void NetworkTestMode::onSpawn(SpawnMessage& message)
	{
		cout << "onSpawn" << endl;
		
		Engine* engine = m_game->getEngine();
		GameNetworkClient* network = m_game->getNetwork();
		
		// First we need to create he player object
		Player* player = new Player(message.getID(), *engine, *m_world, message.getX(), message.getY());
		player->setController(new NetworkController(*player, *network));
		player->setDamageHandler(this);
		player->setHealth(100);
		
		// TODO: FIX MEMORY LEAK!
		Weapon* weapon = new AssaultRifle(*engine, *m_world, *player);
		player->setWeapon(*weapon);
		
		// Then we add the player to the list of players
		m_objectManager->addObject(player);
	}
	
	void NetworkTestMode::onDeath(DeathMessage& message)
	{
		Engine* engine = m_game->getEngine();
		Effects::bloodSplash(*engine, *m_gibLoader, m_gibs, *m_world, message.getX(), message.getY());
	}
	
	void NetworkTestMode::sendReadyMessage()
	{
		ReadyMessage message(m_thisNetworkID);
		m_game->getNetwork()->sendMessage(message);
	}
	
	void NetworkTestMode::handleDamage(GameObject* object, int damage)
	{
		if (object->getNetworkID() == m_thisNetworkID) {
			object->setHealth(object->getHealth() - damage);
			if (!object->isAlive()) {
				Engine* engine = m_game->getEngine();
				Effects::bloodSplash(*engine, *m_gibLoader, m_gibs, *m_world, object->getX(), object->getY());
				DeathMessage message(object->getNetworkID(), object->getX(), object->getY());
				m_game->getNetwork()->sendMessage(message);
			}
		}
	}
	
	void NetworkTestMode::onEndGame(EndGameMessage& message)
	{
		EndGameMode* mode = dynamic_cast<EndGameMode*>(m_game->getMode(BlockWorld::END_GAME_MODE));
		if (mode) {
			mode->setWinner(message.getWinner());
			m_game->setCurrentMode(BlockWorld::END_GAME_MODE);
		}
	}
};

