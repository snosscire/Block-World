#ifndef __TESTMODE_H__
#define __TESTMODE_H__

#include "GameMode.h"
#include "World.h"
#include "Engine/EventObserver.h"

using namespace BadEngine;

class TestMode : public GameMode, public EventObserver {
	private:
		BlockWorld::World* m_world;
	
	private:
		TestMode();
		void performStart();
		void performStop();
		void performUpdate();
		void performDraw();
		
	public:
		TestMode(Game* game);
		~TestMode();
		void onKeyboardButtonDown(KeyboardButtonEvent& event);
};

#endif //  __TESTMODE_H__
