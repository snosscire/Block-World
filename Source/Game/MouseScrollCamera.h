#ifndef __BLOCKWORLD_MOUSESCROLLCAMERA_H__
#define __BLOCKWORLD_MOUSESCROLLCAMERA_H__

#include "../Engine/Engine.h"
#include "../Engine/EventObserver.h"
#include "../Engine/MouseButtonEvent.h"
#include "../Engine/MouseMovementEvent.h"
#include "../Engine/Camera.h"

using namespace BadEngine;

namespace BlockWorld {
	class World;
	class MouseScrollCamera : public Camera, public EventObserver {
		private:
			bool m_holdingButton;
			int m_left;
			int m_top;
			World* m_world;
			Engine* m_engine;
		
		private:
			MouseScrollCamera();
		
		public:
			MouseScrollCamera(World& world, Engine& engine);
			~MouseScrollCamera();
			unsigned int getLeft();
			unsigned int getRight();
			unsigned int getTop();
			unsigned int getBottom(); 
			void onMouseButtonDown(MouseButtonEvent& event);
			void onMouseButtonUp(MouseButtonEvent& event);
			void onMouseMovement(MouseMovementEvent& event);
	};
};

#endif // __BLOCKWORLD_MOUSESCROLLCAMERA_H__