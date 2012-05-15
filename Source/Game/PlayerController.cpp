#include "PlayerController.h"
#include "GameObject.h"

#include "../Engine/EventType.h"

namespace BlockWorld {
	PlayerController::PlayerController() :
		ObjectController(NULL),
		EventObserver()
	{
	}
	
	PlayerController::PlayerController(GameObject& object, Engine& engine) :
		ObjectController(&object),
		EventObserver(),
		m_engine(&engine)
	{
		engine.registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
		engine.registerEventObserver(EVENT_KEYBOARD_BUTTON_UP, this);
		engine.registerEventObserver(EVENT_MOUSE_MOVEMENT, this);
	}
	
	PlayerController::~PlayerController()
	{
		// TODO: Implement unregistering of event observers
	}
	
	void PlayerController::onKeyboardButtonDown(KeyboardButtonEvent& event)
	{
		if (event.getButton() == KEYBOARD_BUTTON_A) {
			m_object->setMoveLeft(true);
		} else if (event.getButton() == KEYBOARD_BUTTON_D) {
			m_object->setMoveRight(true);
		} else if (event.getButton() == KEYBOARD_BUTTON_SPACE) {
			m_object->setJump(true);
		}
	}
	
	void PlayerController::onKeyboardButtonUp(KeyboardButtonEvent& event)
	{
		if (event.getButton() == KEYBOARD_BUTTON_A) {
			m_object->setMoveLeft(false);
		} else if (event.getButton() == KEYBOARD_BUTTON_D) {
			m_object->setMoveRight(false);
		}
	}	
};
