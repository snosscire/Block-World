#ifndef __BLOCKWORLD_PLAYERCONTROLLER_H__
#define __BLOCKWORLD_PLAYERCONTROLLER_H__

#include "ObjectController.h"

#include "../Engine/Engine.h"
#include "../Engine/EventObserver.h"

using namespace BadEngine;

namespace BlockWorld {
	class PlayerController : public ObjectController, public EventObserver {
		private:
			Engine* m_engine;
		
		private:
			PlayerController();
		
		public:
			PlayerController(GameObject& object, Engine& engine);
			virtual ~PlayerController();
			void onKeyboardButtonDown(KeyboardButtonEvent& event);
			void onKeyboardButtonUp(KeyboardButtonEvent& event);
	};
};

#endif // __BLOCKWORLD_PLAYERCONTROLLER_H__
