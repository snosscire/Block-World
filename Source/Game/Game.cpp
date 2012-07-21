#include "Game.h"
#include "GameMode.h"
#include "GameNetworkClient.h"
#include "Config.h"

#include "Console/QuitCommand.h"
#include "Console/MapCommand.h"
#include "Console/DrawHitBoxesCommand.h"

#include "../Engine/BitmapFont.h"

#include <iostream>

namespace BlockWorld {
	Game::Game() :
		EventObserver(),
		m_running(false),
		m_engine(NULL),
		m_gameModes(),
		m_currentMode(NULL),
		m_network(NULL),
		m_showConsole(false),
		m_shouldGrabMouse(true)
	{
	}
	
	Game::Game(Engine* engine) :
		EventObserver(),
		m_running(false),
		m_engine(engine),
		m_gameModes(),
		m_currentMode(NULL),
		m_network(NULL),
		m_showConsole(false),
		m_shouldGrabMouse(true)
	{
	}
	
	Game::~Game()
	{
		if (m_network) {
			delete m_network;
		}
	}
	
	Engine* Game::getEngine()
	{
		return m_engine;
	}
	
	GameNetworkClient* Game::getNetwork()
	{
		return m_network;
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
	
	GameMode* Game::getMode(const string& name)
	{
		map<const string, GameMode*>::iterator it = m_gameModes.find(name);
		if (it != m_gameModes.end()) {
			return it->second;
		}
		return NULL;
	}
	
	Console* Game::getConsole()
	{
		return m_console;
	}
	
	void Game::activateNetwork()
	{
		if (!m_network) {
			m_network = new GameNetworkClient();
		}
	}
	
	void Game::run(const string& mode)
	{
		double currentTime = 0.0;
		double lastTime = 0.0;
		double deltaTime = 0.0;
		
		m_engine->start();
		m_engine->registerEventObserver(EVENT_QUIT, this);
		m_engine->registerEventObserver(EVENT_VIDEO_RESIZE, this);
		m_engine->registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
		
		Config::loadFile("config.xml");

		BitmapFont* font = m_engine->loadBitmapFont("Resources/Fonts/font-console.png", 10, 10);
		m_console = new Console(*m_engine, *font);

		m_console->registerCommand("quit", new QuitCommand(*this));
		m_console->registerCommand("map", new MapCommand(*this));
		m_console->registerCommand("hitboxes", new DrawHitBoxesCommand());
		
		if (m_shouldGrabMouse) {
			m_engine->grabInput();
		}
		
		setCurrentMode(mode);
		
		currentTime = m_engine->getCurrentTime();
		lastTime = currentTime;
		
		m_running = true;
		while( m_running ) {
			currentTime = m_engine->getCurrentTime();
			deltaTime = currentTime - lastTime;
			lastTime = currentTime;
			if (m_network) {
				m_network->notifyObservers();
			}
			m_engine->notifyEventObservers();
			if (m_currentMode) {
				m_currentMode->update(currentTime, deltaTime);
			}
			m_engine->clearScreen();
			if (m_currentMode) {
				m_currentMode->draw();
			}
			if (m_showConsole) {
				m_console->draw(*m_engine);
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
	
	void Game::onVideoResize(VideoResizeEvent& event)
	{
		m_engine->setVideoMode(event.getWidth(), event.getHeight());
	}
	
	void Game::onKeyboardButtonDown(KeyboardButtonEvent& event)
	{
		if (event.getButton() == KEYBOARD_BUTTON_F1) {
			m_showConsole = (m_showConsole ? false : true);
			m_console->setActive(m_showConsole);
			if (m_shouldGrabMouse) {
				if (m_showConsole) {
					m_engine->releaseInput();
				} else {
					m_engine->grabInput();
				}
			}
		}
	}
	
	void Game::setShouldGrabMouse(bool should)
	{
		m_shouldGrabMouse = should;
	}
};
