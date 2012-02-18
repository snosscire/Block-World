#include "GameMode.h"
#include "Game.h"

namespace BlockWorld {
	GameMode::GameMode() :
		m_started(false),
		m_game(0)
	{
	}
	
	GameMode::GameMode(Game *game) :
		m_started(false),
		m_game(game)
	{
	}
	
	GameMode::~GameMode()
	{
	}
	
	void GameMode::start()
	{
		if (!m_started) {
			performStart();
			m_started = true;
		}
	}
	
	void GameMode::stop()
	{
		if (m_started) {
			performStop();
			m_started = false;
		}
	}
	
	void GameMode::update(unsigned int deltaTime)
	{
		if (m_started) {
			performUpdate(deltaTime);
		}
	}
	
	void GameMode::draw()
	{
		if (m_started) {
			performDraw();
		}
	}
};
