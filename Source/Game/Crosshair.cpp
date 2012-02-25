#include "Crosshair.h"
#include "GameObject.h"

#include <iostream>

namespace BlockWorld {
	Crosshair::Crosshair() :
		EventObserver(),
		m_x(0.0),
		m_y(0.0),
		m_object(NULL),
		m_image(NULL),
		m_engine(NULL)
	{
	}
	
	Crosshair::Crosshair(Image* image, GameObject& object, Engine& engine) :
		EventObserver(),
		m_x(0.0),
		m_y(0.0),
		m_object(&object),
		m_image(image),
		m_engine(&engine)
	{
		m_x = engine.getScreenWidth() / 2;
		m_y = engine.getScreenHeight() / 2;
		
		engine.registerEventObserver(EVENT_MOUSE_MOVEMENT, this);
	}
	
	Crosshair::~Crosshair()
	{
		if (m_image) {
			delete m_image;
		}
	}
	
	void Crosshair::update()
	{
		
	}
	
	void Crosshair::draw()
	{
		if (m_image) {
			m_image->draw(m_x, m_y);
		}
	}
	
	void Crosshair::onMouseMovement(MouseMovementEvent& event)
	{
		m_x = event.getX() - (m_image->getWidth() / 2);
		m_y = event.getY() - (m_image->getHeight() / 2);
	}
};
