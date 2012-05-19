#ifndef __BLOCKWORLD_OBJECTMANAGER_H__
#define __BLOCKWORLD_OBJECTMANAGER_H__

#include "../Engine/Engine.h"
#include "../Engine/Square.h"

#include <list>

using namespace std;
using namespace BadEngine;

namespace BlockWorld {
	class Camera;
	class GameObject;
	class ObjectManager {
		private:
			list<GameObject*> m_objects;
		
		public:
			ObjectManager();
			~ObjectManager();
			void addObject(GameObject* object);
			void spriteUpdate(double currentTime, double deltaTime, int id);
			void draw(Engine& engine, Camera& camera);
			bool _haveCollision(Square& a, Square& b);
			GameObject* haveCollision(double x, double y, int width, int height, GameObject& ignore);
	};
};

#endif
