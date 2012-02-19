#ifndef __BLOCKWORLD_FOLLOWOBJECTCAMERA_H__
#define __BLOCKWORLD_FOLLOWOBJECTCAMERA_H__

#include "Camera.h"

#include "../Engine/Engine.h"

using namespace BadEngine;

namespace BlockWorld {
	class GameObject;
	class World;
	class FollowObjectCamera : public Camera {
		private:
			World* m_world;
			GameObject* m_object;
			Engine* m_engine;
		
		private:
			FollowObjectCamera();
		
		public:
			FollowObjectCamera(World& world, GameObject& object, Engine& engine);
			virtual ~FollowObjectCamera();
			int getLeft();
			int getRight();
			int getTop();
			int getBottom();
	};
};

#endif // __BLOCKWORLD_FOLLOWOBJECTCAMERA_H__
