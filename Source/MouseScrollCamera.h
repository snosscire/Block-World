#ifndef __BADENGINE_MOUSESCROLLCAMERA_H__
#define __BADENGINE_MOUSESCROLLCAMERA_H__

#include "Engine/Engine.h"
#include "Engine/EventObserver.h"
#include "Engine/MouseButtonEvent.h"
#include "Engine/MouseMovementEvent.h"

#include "Camera.h"
#include "World.h"

using namespace BadEngine;
using namespace BlockWorld;

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

#endif // __BADENGINE_MOUSESCROLLCAMERA_H__