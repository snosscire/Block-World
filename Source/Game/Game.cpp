#include "Game.h"
#include "GameMode.h"

#include <iostream>

namespace BlockWorld {
	Game::Game() :
		EventObserver(),
		m_running(false),
		m_engine(NULL),
		m_gameModes(),
		m_currentMode(NULL)
	{
	}
	
	Game::Game(Engine* engine) :
		EventObserver(),
		m_running(false),
		m_engine(engine),
		m_gameModes(),
		m_currentMode(NULL)
	{
	}
	
	Game::~Game()
	{
	}
	
	Engine* Game::getEngine()
	{
		return m_engine;
	}
	
	void Game::registerMode(const string& name, GameMode* mode)
	{
		m_gameModes[name] = mode;
	}
	
	void Game::setCurrentMode(const string& name)
	{
		if (m_currentMode) {
			m_currentMode->stop();
		}
		m_currentMode = m_gameModes[name];
		if (m_currentMode) {
			m_currentMode->start();
		}
	}
	
	void Game::run(const string& mode)
	{
		unsigned int currentTime = 0;
		unsigned int lastTime = 0;
		unsigned int deltaTime = 0;
		
		m_engine->start();
		m_engine->registerEventObserver(EVENT_QUIT, this);
		
		setCurrentMode(mode);
		
		currentTime = m_engine->getCurrentTime();
		lastTime = currentTime;
		
		m_running = true;
		while( m_running ) {
			currentTime = m_engine->getCurrentTime();
			deltaTime = currentTime - lastTime;
			lastTime = currentTime;
			m_engine->notifyEventObservers();
			if (m_currentMode) {
				m_currentMode->update(deltaTime);
			}
			m_engine->clearScreen();
			if (m_currentMode) {
				m_currentMode->draw();
			}
			m_engine->updateScreen();
		}
		
		if (m_currentMode) {
			m_currentMode->stop();
		}
		
		m_engine->stop();
	}
	
	void Game::quit()
	{
		m_running = false;
	}
	
	void Game::onQuit()
	{
		quit();
	}
};
