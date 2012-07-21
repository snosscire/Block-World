#include "SplashMode.h"
#include "Game.h"
#include "NetworkTestMode.h"
#include "ServerListMode.h"
#include "BlockWorld.h"

#include "../Engine/Square.h"

#include <iostream>

using namespace std;

namespace BlockWorld {
	SplashMode::SplashMode() :
		GameMode(),
		m_background(NULL)
	{
	}
	
	SplashMode::SplashMode(Game* game) :
		GameMode(game),
		m_background(NULL)
	{
	}
	
	SplashMode::~SplashMode()
	{
	}
	
	void SplashMode::performStart()
	{
		Engine* engine = m_game->getEngine();
		engine->registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
		m_background = engine->loadImage("Resources/Menu/Splash.png");
	}
	
	void SplashMode::performStop()
	{
		if (m_background) {
			delete m_background;
		}
	}
	
	void SplashMode::performUpdate(double currentTime, double deltaTime)
	{
		if (currentTime > 2500) {
			/*
			NetworkTestMode* mode = dynamic_cast<NetworkTestMode*>(m_game->getMode(BlockWorld::NETWORK_TEST_MODE));
			if (mode) {
				m_game->setCurrentMode(BlockWorld::NETWORK_TEST_MODE);
			}
			*/
			ServerListMode* mode = dynamic_cast<ServerListMode*>(m_game->getMode(BlockWorld::SERVER_LIST_MODE));
			if (mode) {
				m_game->setCurrentMode(BlockWorld::SERVER_LIST_MODE);
			}
		}
	}
	
	void SplashMode::performDraw()
	{
		Engine* engine = m_game->getEngine();
		Square backgroundColor;
		backgroundColor.setX(0);
		backgroundColor.setY(0);
		backgroundColor.setWidth(engine->getScreenWidth());
		backgroundColor.setHeight(engine->getScreenHeight());
		engine->drawSquare(backgroundColor, 10, 56, 84);
		if (m_background) {
			int x = (engine->getScreenWidth() / 2) - (m_background->getWidth() / 2);
			int y = (engine->getScreenHeight() / 2) - (m_background->getHeight() / 2);
			m_background->draw(x, y);
		}
	}
	
	void SplashMode::onKeyboardButtonDown(KeyboardButtonEvent& event)
	{
		if (event.getButton() == KEYBOARD_BUTTON_ESCAPE) {
			m_game->quit();
		}
	}
};

