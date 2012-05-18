#include "PlayerController.h"
#include "GameObject.h"
#include "World.h"

#include "../Engine/EventType.h"

namespace BlockWorld {
	PlayerController::PlayerController() :
		ObjectController(NULL),
		EventObserver(),
		m_engine(NULL),
		m_world(NULL)
	{
	}
	
	PlayerController::PlayerController(GameObject& object, Engine& engine, World& world) :
		ObjectController(&object),
		EventObserver(),
		m_engine(&engine),
		m_world(&world)
	{
		engine.registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
		engine.registerEventObserver(EVENT_KEYBOARD_BUTTON_UP, this);
		engine.registerEventObserver(EVENT_MOUSE_BUTTON_DOWN, this);
	}
	
	PlayerController::~PlayerController()
	{
		m_engine->unregisterEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
		m_engine->unregisterEventObserver(EVENT_KEYBOARD_BUTTON_UP, this);
		m_engine->unregisterEventObserver(EVENT_MOUSE_BUTTON_DOWN, this);
	}
	
	void PlayerController::onKeyboardButtonDown(KeyboardButtonEvent& event)
	{
		if (m_object->isAlive()) {
			if (event.getButton() == KEYBOARD_BUTTON_A) {
				m_object->setMoveLeft(true);
			} else if (event.getButton() == KEYBOARD_BUTTON_D) {
				m_object->setMoveRight(true);
			} else if (event.getButton() == KEYBOARD_BUTTON_SPACE) {
				m_object->setJump(true);
			}
		}
	}
	
	void PlayerController::onKeyboardButtonUp(KeyboardButtonEvent& event)
	{
		if (event.getButton() == KEYBOARD_BUTTON_A) {
			m_object->setMoveLeft(false);
		} else if (event.getButton() == KEYBOARD_BUTTON_D) {
			m_object->setMoveRight(false);
		}
	};
	
	void PlayerController::onMouseButtonDown(MouseButtonEvent& event) {
		if (!m_object->isAlive()) {
			Position* spawnPosition = m_world->getRandomOpenPosition(*m_engine, 96, 96);
			m_object->setX(spawnPosition->getX() + 48);
			m_object->setY(spawnPosition->getY() + 48);
			m_object->setHealth(100);
			delete spawnPosition;
		}
	}
};

