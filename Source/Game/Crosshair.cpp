#include "Crosshair.h"
#include "GameObject.h"
#include "BlockWorld.h"

#include <math.h>

#include <iostream>

#include <SDL/SDL.h>

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
		//engine.grabInput();
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
		double newX = m_x + event.getRelativeX();
		double newY = m_y + event.getRelativeY();
		
		double originX = m_object->getScreenX();
		double originY = m_object->getScreenY();
		
		double x = newX - originX;
		double y = newY - originY;
		double length = sqrt(x * x + y * y);
		
		if (length > BlockWorld::MAX_CROSSHAIR_DISTANCE) {
			double modifiedX = newX - originX;
			double modifiedY = newY - originY;
			double magnitude = sqrt((modifiedX * modifiedX) + (modifiedY * modifiedY));

			double normalizedX = modifiedX / magnitude;
			double normalizedY = modifiedY / magnitude;

			newX = (normalizedX * BlockWorld::MAX_CROSSHAIR_DISTANCE);
			newY = (normalizedY * BlockWorld::MAX_CROSSHAIR_DISTANCE);
			
			newX += originX;
			newY += originY;
		}
		
		m_x = newX;
		m_y = newY;
	}
};
