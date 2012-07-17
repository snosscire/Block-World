#include "EndGameMode.h"
#include "Game.h"

#include "../Engine/Square.h"

#include <iostream>
#include <sstream>

namespace BlockWorld {
	EndGameMode::EndGameMode() :
		GameMode(),
		m_background(NULL),
		m_winner(),
		m_font(NULL)
	{
	}
	
	EndGameMode::EndGameMode(Game* game) :
		GameMode(game),
		m_background(NULL),
		m_winner(),
		m_font(NULL)
	{
	}
	
	EndGameMode::~EndGameMode()
	{
	}
	
	void EndGameMode::performStart()
	{
		Engine* engine = m_game->getEngine();
		engine->registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
		m_background = engine->loadImage("Resources/Menu/ScoreScreen.png");
		m_font = engine->loadBitmapFont("Resources/Fonts/font-big.png", 40, 40);
	}
	
	void EndGameMode::performStop()
	{
		if (m_background) {
			delete m_background;
		}
		if (m_font) {
			delete m_font;
		}
	}
	
	void EndGameMode::performUpdate(double currentTime, double deltaTime)
	{
	}
	
	void EndGameMode::performDraw()
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
		if (m_font) {
			int x = (engine->getScreenWidth() / 2) - (m_background->getWidth() / 2) + 30;
			int y = (engine->getScreenHeight() / 2) - (m_background->getHeight() / 2) + 30;
			ostringstream headline;
			headline << "--- winner ---";
			m_font->drawText(x, y, headline);
			m_font->drawText(x, y + 60, m_winner);
		}
	}
	
	void EndGameMode::onKeyboardButtonDown(KeyboardButtonEvent& event)
	{
		if (event.getButton() == KEYBOARD_BUTTON_ESCAPE) {
			m_game->quit();
		}
	}
	
	void EndGameMode::setWinner(string winner)
	{
		m_winner = winner;
	}
};

