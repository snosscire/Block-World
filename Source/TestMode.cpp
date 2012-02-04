#include "TestMode.h"
#include "Game.h"

#include <iostream>

TestMode::TestMode() :
	GameMode(),
	m_world(NULL)
{
}

TestMode::TestMode(Game* game) :
	GameMode(game),
	m_world(NULL)
{
}

TestMode::~TestMode()
{
}

void TestMode::performStart()
{
	m_game->getEngine()->registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
	m_world = new BlockWorld::World(640, 480);
}

void TestMode::performStop()
{
	delete m_world;
	m_world = NULL;
}

void TestMode::performUpdate()
{
}

void TestMode::performDraw()
{
	//m_world->draw(m_game->getEngine(), NULL);
}

void TestMode::onKeyboardButtonDown(KeyboardButtonEvent& event)
{
	if( event.getButton() == KEYBOARD_BUTTON_ESCAPE )
	{
		m_game->quit();
	}
}
