#include "ServerLobbyMode.h"
#include "Game.h"
#include "NetworkTestMode.h"
#include "BlockWorld.h"

#include "../Engine/Square.h"

#include <iostream>

namespace BlockWorld {
	ServerLobbyMode::ServerLobbyMode() :
		GameMode(),
		m_background(NULL),
		m_font(NULL),
		m_host()
	{
	}
	
	ServerLobbyMode::ServerLobbyMode(Game* game) :
		GameMode(game),
		m_background(NULL),
		m_font(NULL),
		m_host()
	{
	}
	
	ServerLobbyMode::~ServerLobbyMode()
	{
	}
	
	void ServerLobbyMode::performStart()
	{
		Engine* engine = m_game->getEngine();
		engine->registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
		engine->registerEventObserver(EVENT_MOUSE_BUTTON_DOWN, this);
		m_background = engine->loadImage("Resources/Menu/ScoreScreen.png");
		m_font = engine->loadBitmapFont("Resources/Fonts/font-menu.png", 20, 20);
	}
	
	void ServerLobbyMode::performStop()
	{
		Engine* engine = m_game->getEngine();
		engine->unregisterEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
		engine->unregisterEventObserver(EVENT_MOUSE_BUTTON_DOWN, this);
		
		if (m_background) {
			delete m_background;
			m_background = NULL;
		}
		if (m_font) {
			delete m_font;
			m_font = NULL;
		}
	}
	
	void ServerLobbyMode::performUpdate(double currentTime, double deltaTime)
	{
	}
	
	void ServerLobbyMode::performDraw()
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
	
	void ServerLobbyMode::setHost(string host)
	{
		m_host = host;
	}
	
	void ServerLobbyMode::onKeyboardButtonDown(KeyboardButtonEvent& event)
	{
		if (event.getButton() == KEYBOARD_BUTTON_ESCAPE) {
			m_game->quit();
		}
	}
	
	void ServerLobbyMode::onMouseButtonDown(MouseButtonEvent& event)
	{
		/*
		int left = m_joinButtonRect->getX();
		int right = m_joinButtonRect->getX() + m_joinButtonRect->getWidth();
		int top = m_joinButtonRect->getY();
		int bottom = m_joinButtonRect->getY() + m_joinButtonRect->getHeight();

		if (event.getX() >= left && event.getX() <= right &&
			event.getY() >= top && event.getY() <= bottom)
		{
		}
		*/
	}
};


