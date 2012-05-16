#include "NothingMode.h"
#include "Game.h"

#include <iostream>

namespace BlockWorld {
	NothingMode::NothingMode() :
		GameMode()
	{
	}
	
	NothingMode::NothingMode(Game* game) :
		GameMode(game)
	{
	}
	
	NothingMode::~NothingMode()
	{
	}
	
	void NothingMode::performStart()
	{
		Engine* engine = m_game->getEngine();
		engine->registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
	}
	
	void NothingMode::performStop()
	{
	}
	
	void NothingMode::performUpdate(double currentTime, double deltaTime)
	{
	}
	
	void NothingMode::performDraw()
	{
	}
	
	void NothingMode::onKeyboardButtonDown(KeyboardButtonEvent& event)
	{
		if (event.getButton() == KEYBOARD_BUTTON_ESCAPE) {
			m_game->quit();
		}
	}
};

