#include "ServerListMode.h"
#include "Game.h"
#include "NetworkTestMode.h"
#include "BlockWorld.h"
#include "ServerLobbyMode.h"

#include "../Engine/Square.h"

#include <iostream>

namespace BlockWorld {
	ServerListMode::ServerListMode() :
		GameMode(),
		m_background(NULL),
		m_font(NULL),
		m_joinButton(NULL),
		m_joinButtonClick(NULL)
	{
	}
	
	ServerListMode::ServerListMode(Game* game) :
		GameMode(game),
		m_background(NULL),
		m_font(NULL),
		m_joinButton(NULL),
		m_joinButtonClick(NULL)
	{
	}
	
	ServerListMode::~ServerListMode()
	{
	}
	
	void ServerListMode::performStart()
	{
		Engine* engine = m_game->getEngine();
		engine->registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
		engine->registerEventObserver(EVENT_MOUSE_BUTTON_DOWN, this);
		m_background = engine->loadImage("Resources/Menu/ScoreScreen.png");
		m_font = engine->loadBitmapFont("Resources/Fonts/font-menu.png", 20, 20);
		m_joinButton = engine->loadImage("Resources/Menu/join.png");
	}
	
	void ServerListMode::performStop()
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
		if (m_joinButton) {
			delete m_joinButton;
			m_joinButton = NULL;
		}
		if (m_joinButtonClick) {
			delete m_joinButtonClick;
			m_joinButtonClick= NULL;
		}
		if (m_joinButtonRect) {
			delete m_joinButtonRect;
			m_joinButtonRect = NULL;
		}
	}
	
	void ServerListMode::performUpdate(double currentTime, double deltaTime)
	{
	}
	
	void ServerListMode::performDraw()
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
		int x = (engine->getScreenWidth() / 2) - (m_background->getWidth() / 2);
		int y = (engine->getScreenHeight() / 2) - (m_background->getHeight() / 2);
		drawItem(x + 30, y + 30, "bad dudes games public 1");
		//drawItem(x + 30, y + 120, "bad dudes games public 2");
	}
	
	void ServerListMode::drawItem(int x, int y, string name)
	{
		if (m_font) {
			string line = "------------------------";
			m_font->drawText(x, y, name);
			m_font->drawText(x, y + 40, line);
		}
		if (m_joinButton) {
			m_joinButton->draw(x + m_font->getTextWith(name) + 10, y - 4);
			if (m_joinButtonRect) {
				delete m_joinButtonRect;
				m_joinButtonRect = NULL;
			}
			m_joinButtonRect = new Square();
			m_joinButtonRect->setX(x + m_font->getTextWith(name) + 10);
			m_joinButtonRect->setY(y - 4);
			m_joinButtonRect->setWidth(m_joinButton->getWidth());
			m_joinButtonRect->setHeight(m_joinButton->getHeight());
		}
	}
	
	void ServerListMode::onKeyboardButtonDown(KeyboardButtonEvent& event)
	{
		if (event.getButton() == KEYBOARD_BUTTON_ESCAPE) {
			m_game->quit();
		}
	}
	
	void ServerListMode::onMouseButtonDown(MouseButtonEvent& event)
	{
		int left = m_joinButtonRect->getX();
		int right = m_joinButtonRect->getX() + m_joinButtonRect->getWidth();
		int top = m_joinButtonRect->getY();
		int bottom = m_joinButtonRect->getY() + m_joinButtonRect->getHeight();

		if (event.getX() >= left && event.getX() <= right &&
			event.getY() >= top && event.getY() <= bottom)
		{
			ServerLobbyMode* mode = dynamic_cast<ServerLobbyMode*>(m_game->getMode(BlockWorld::SERVER_LOBBY_MODE));
			if (mode) {
				mode->setHost("wedogames.se");
				m_game->setCurrentMode(BlockWorld::SERVER_LOBBY_MODE);
			}
		}
	}
};


