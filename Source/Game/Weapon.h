#ifndef __BLOCKWORLD_WEAPON_H__
#define __BLOCKWORLD_WEAPON_H__

#include "../Engine/Engine.h"
#include "../Engine/Image.h"

using namespace BadEngine;

namespace BlockWorld {
	class GameObject;
	class GameNetworkClient;
	class Weapon {
		protected:
			GameObject* m_owner;
			Image* m_image;
		
		private:
			Weapon();
		
		protected:
			Weapon(GameObject& owner);
		
		public:
			virtual ~Weapon();
			virtual void update(double currentTime, double deltaTime, GameNetworkClient* network);
			void draw(Engine& engine);
	};
};

#endif
