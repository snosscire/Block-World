#include "MouseScrollCamera.h"
#include "BlockWorld.h"

#include <iostream>

MouseScrollCamera::MouseScrollCamera() :
	Camera(),
	EventObserver(),
	m_holdingButton(false),
	m_left(0),
	m_top(0),
	m_world(NULL),
	m_engine(NULL)
{
}

MouseScrollCamera::MouseScrollCamera(World& world, Engine& engine) :
	Camera(),
	EventObserver(),
	m_holdingButton(false),
	m_left(0),
	m_top(0),
	m_world(&world),
	m_engine(&engine)
{
	engine.registerEventObserver(EVENT_MOUSE_BUTTON_DOWN, this);
	engine.registerEventObserver(EVENT_MOUSE_BUTTON_UP, this);
	engine.registerEventObserver(EVENT_MOUSE_MOVEMENT, this);
}

MouseScrollCamera::~MouseScrollCamera()
{
}

unsigned int MouseScrollCamera::getLeft()
{
	return m_left;
}

unsigned int MouseScrollCamera::getRight()
{
	return m_left + m_engine->getScreenWidth();
}

unsigned int MouseScrollCamera::getTop()
{
	return m_top;
}

unsigned int MouseScrollCamera::getBottom()
{
	return m_top + m_engine->getScreenHeight();
}

void MouseScrollCamera::onMouseButtonDown(MouseButtonEvent& event)
{
	m_holdingButton = true;
}

void MouseScrollCamera::onMouseButtonUp(MouseButtonEvent& event)
{
	m_holdingButton = false;
}

void MouseScrollCamera::onMouseMovement(MouseMovementEvent& event)
{
	int maxLeft = (m_world->getWidth() * BlockWorld::BLOCK_WIDTH) - m_engine->getScreenWidth();
	int maxTop = (m_world->getHeight() * BlockWorld::BLOCK_HEIGHT) - m_engine->getScreenHeight();
	
	if (m_holdingButton) {
		m_left -= event.getRelativeX();
		
		if (m_left < 0) {
			m_left = 0;
		} else if (m_left > maxLeft) {
			m_left = maxLeft;
			
			if (m_left < 0) {
				m_left = 0;
			}
		}
		
		m_top -= event.getRelativeY();
		
		if (m_top < 0) {
			m_top = 0;
		} else if (m_top > maxTop) {
			m_top = maxTop;
			
			if (m_top < 0) {
				m_top = 0;
			}
		}
	}
}
