#ifndef __BLOCKWORLD_NETWORKTESTMODE_H__
#define __BLOCKWORLD_NETWORKTESTMODE_H__

#include "../Engine/EventObserver.h"
#include "../Engine/NetworkObserver.h"

#include "GameMode.h"
#include "MessageObserver.h"

#include "World.h"

#include <list>

using namespace std;
using namespace BadEngine;

namespace BlockWorld {
	class Camera;
	class World;
	class Player;
	class Crosshair;
	class ConnectResponseMessage;
	class JoinMessage;
	
	class NetworkTestMode : public GameMode, public EventObserver, public NetworkObserver, public MessageObserver {
		private:
			World* m_world;
			Camera* m_camera;
			Crosshair* m_crosshair;
			list<Player*> m_players;
			Player* m_thisPlayer;
			
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
	};
};

#endif //  __BLOCKWORLD_NETWORKTESTMODE_H__

