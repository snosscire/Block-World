#ifndef __BLOCKWORLD_MOUSESCROLLCAMERA_H__
#define __BLOCKWORLD_MOUSESCROLLCAMERA_H__

#include "../Engine/Engine.h"
#include "../Engine/EventObserver.h"
#include "../Engine/MouseButtonEvent.h"
#include "../Engine/MouseMovementEvent.h"

#include "Camera.h"

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
			virtual ~MouseScrollCamera();
			int getLeft();
			int getRight();
			int getTop();
			int getBottom();
			void onMouseButtonDown(MouseButtonEvent& event);
			void onMouseButtonUp(MouseButtonEvent& event);
			void onMouseMovement(MouseMovementEvent& event);
	};
};

#endif // __BLOCKWORLD_MOUSESCROLLCAMERA_H__