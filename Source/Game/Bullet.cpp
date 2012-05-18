#include "Bullet.h"
#include "World.h"
#include "GameObject.h"
#include "Block.h"
#include "Camera.h"

#include <math.h>

namespace BlockWorld {
	Bullet::Bullet(Image* image, World& world, GameObject& owner, double x, double y, double angle, double speed) :
		m_image(image),
		m_world(&world),
		m_owner(&owner),
		m_alive(true),
		m_x(x),
		m_y(y),
		m_angle(angle),
		m_speed(speed)
	{
	}
	
	Bullet::~Bullet()
	{
		if (m_image) {
			delete m_image;
		}
	}
	
	bool Bullet::isAlive()
	{
		return m_alive;
	}
	
	void Bullet::update(double currentTime, double deltaTime, GameNetworkClient* network)
	{
		if (m_alive) {
			double deltaSpeed = m_speed * (deltaTime / 10.0);
			double radianAngle = m_angle * 0.017453292;
			double newX = m_x + (deltaSpeed * cos(radianAngle));
			double newY = m_y + (deltaSpeed * sin(radianAngle));
			Block* block = m_world->haveCollision(newX, newY, m_image->getWidth(), m_image->getHeight());
			if (block) {
				doDamage(*block);
				m_alive = false;
			} else {
				m_x = newX;
				m_y = newY;
			}
		}
	}
	
	void Bullet::draw(Engine& engine, Camera& camera)
	{
		if (m_image && m_alive) {
			int x = m_x - camera.getLeft();
			int y = m_y - camera.getTop();
			if (x > 0 and x < engine.getScreenWidth() and y > 0 and y < engine.getScreenHeight()) {
				Image* rotated = m_image->rotate(m_angle);
				rotated->draw(x, y);
				delete rotated;
			}
		}
	}
};

