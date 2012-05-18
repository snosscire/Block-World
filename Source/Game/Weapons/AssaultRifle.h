#ifndef __BLOCKWORLD_ASSAULTRIFLE_H__
#define __BLOCKWORLD_ASSAULTRIFLE_H__

#include "../Weapon.h"
#include "../../Engine/Engine.h"
#include "../../Engine/Image.h"

using namespace BadEngine;

namespace BlockWorld {
	class GameObject;
	class AssaultRifle : public Weapon {
		private:
			Engine* m_engine;
			Image* m_withoutMuzzleFlashImage;
			Image* m_withMuzzleFlashImage;
			bool m_firing;
			unsigned int m_fireNextRound;
		
		public:
			AssaultRifle(Engine& engine, GameObject& owner);
			virtual ~AssaultRifle();
			void update(double currentTime, double deltaTime, GameNetworkClient* network);
			void startFiring();
			void stopFiring();
			void fireBullet(double x, double y, double angle);
	};
};

#endif
