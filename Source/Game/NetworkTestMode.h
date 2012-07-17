#ifndef __BLOCKWORLD_NETWORKTESTMODE_H__
#define __BLOCKWORLD_NETWORKTESTMODE_H__

#include "../Engine/EventObserver.h"
#include "../Engine/NetworkObserver.h"

#include "GameMode.h"
#include "MessageObserver.h"
#include "DamageHandler.h"

#include "World.h"

#include <string>
#include <deque>

using namespace std;
using namespace BadEngine;

namespace BlockWorld {
	class GibResourceLoader;
	class ObjectManager;
	class Camera;
	class World;
	class Player;
	class Weapon;
	class Crosshair;
	class ConnectResponseMessage;
	class JoinMessage;
	class LoadMapMessage;
	class ShotMessage;
	class EndGameMessage;
	class NetworkTestMode : public GameMode, public EventObserver, public NetworkObserver, public MessageObserver, public DamageHandler {
		private:
			World* m_world;
			Camera* m_camera;
			Crosshair* m_crosshair;
			Player* m_thisPlayer;
			Weapon* m_weapon;
			int m_thisNetworkID;
			string m_thisPlayerName;
			ObjectManager* m_objectManager;
			GibResourceLoader* m_gibLoader;
			deque<GameObject*> m_gibs;
			
		private:
			NetworkTestMode();
			void performStart();
			void performStop();
			void performUpdate(double currentTime, double deltaTime);
			void performDraw();
			
		public:
			NetworkTestMode(Game* game);
			~NetworkTestMode();
			void onKeyboardButtonDown(KeyboardButtonEvent& event);
			void onConnectResponse(ConnectResponseMessage& message);
			void onJoin(JoinMessage& message);
			void onLoadMap(LoadMapMessage& message);
			void onStartGame(StartGameMessage& message);
			void onSpawn(SpawnMessage& message);
			void onDeath(DeathMessage& message);
			void sendReadyMessage();
			void handleDamage(GameObject* object, int damage);
			void onEndGame(EndGameMessage& message);
	};
};

#endif //  __BLOCKWORLD_NETWORKTESTMODE_H__

