#ifndef __BLOCKWORLD_CROSSHAIR_H__
#define __BLOCKWORLD_CROSSHAIR_H__

#include "../Engine/Engine.h"
#include "../Engine/EventObserver.h"
#include "../Engine/Image.h"

using namespace BadEngine;

namespace BlockWorld {
	class GameObject;
	class Crosshair : public EventObserver {
		private:
			double m_x;
			double m_y;
			GameObject* m_object;
			Image* m_image;
			Engine* m_engine;
			
		private:
			Crosshair();
		
		public:
			Crosshair(Image* image, GameObject& object, Engine& engine);
			virtual ~Crosshair();
			double getX();
			double getY();
			void update();
			void draw();
			void onMouseMovement(MouseMovementEvent& event);
	};
};

#endif // __BLOCKWORLD_CROSSHAIR_H__
