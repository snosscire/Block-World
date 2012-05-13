#include "WorldBackground.h"
#include "Camera.h"

namespace BlockWorld {
	WorldBackground::WorldBackground() :
		m_layer(0),
		m_x(0),
		m_y(0),
		m_speed(1.0),
		m_image(NULL)
	{
	}
	
	WorldBackground::WorldBackground(int layer, int x, int y, double speed, Image& image) :
		m_layer(layer),
		m_x(x),
		m_y(y),
		m_speed(speed),
		m_image(&image)
	{
	}
	
	WorldBackground::~WorldBackground()
	{
		if (m_image) {
			delete m_image;
		}
	}
	
	int WorldBackground::getLayer()
	{
		return m_layer;
	}
	
	void WorldBackground::draw(Engine& engine, Camera& camera)
	{
		int x = (m_x - camera.getLeft()) * m_speed;
		int y = m_y - camera.getTop();
		if (m_image) {
			m_image->draw(x, y);
		}
	}
};
