#include "Game.h"
#include "Engine/Engine.h"
#include "GameMode.h"

#include <iostream>

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
	m_engine->start();
	m_engine->registerEventObserver(EVENT_QUIT, this);
	
	setCurrentMode(mode);
	
	m_running = true;
	while( m_running ) {
		m_engine->notifyEventObservers();
		if (m_currentMode) {
			m_currentMode->update();
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