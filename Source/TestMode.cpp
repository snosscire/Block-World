#include "TestMode.h"
#include "Game.h"
#include "MouseScrollCamera.h"
#include "WorldGenerator.h"

#include <iostream>

TestMode::TestMode() :
	GameMode(),
	m_world(NULL),
	m_camera(NULL)
{
}

TestMode::TestMode(Game* game) :
	GameMode(game),
	m_world(NULL),
	m_camera(NULL)
{
}

TestMode::~TestMode()
{
}

void TestMode::performStart()
{
	WorldGenerator* worldGenerator = new WorldGenerator();
	Engine* engine = m_game->getEngine();
	engine->registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
	m_world = worldGenerator->createWorld(*engine, 60, 30);
	m_camera = new MouseScrollCamera(*m_world, *engine);
	delete worldGenerator;
}

void TestMode::performStop()
{
	delete m_world;
	m_world = NULL;
	delete m_camera;
	m_camera = NULL;
}

void TestMode::performUpdate()
{
}

void TestMode::performDraw()
{
	Engine* engine = m_game->getEngine();
	m_world->draw(*engine, *m_camera);
}

void TestMode::onKeyboardButtonDown(KeyboardButtonEvent& event)
{
	if( event.getButton() == KEYBOARD_BUTTON_ESCAPE )
	{
		m_game->quit();
	}
}
