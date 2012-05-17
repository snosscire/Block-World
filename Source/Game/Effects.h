#ifndef __BLOCKWORLD_EFFECTS_H__
#define __BLOCKWORLD_EFFECTS_H__

#include "../Engine/Engine.h"

#include <deque>

using namespace std;
using namespace BadEngine;

namespace BlockWorld {
	class World;
	class GameObject;
	class GibResourceLoader;
	class Effects {
		public:
			static void bloodSplash(Engine& engine, GibResourceLoader& gibLoader, deque<GameObject*>& list, World& world, GameObject& origin);
	};
};

#endif
