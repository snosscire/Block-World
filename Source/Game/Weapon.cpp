#include "Weapon.h"
#include "Bullet.h"
#include "GameObject.h"
#include "GameNetworkClient.h"
#include "Camera.h"

#include <iostream>

using namespace std;

namespace BlockWorld {
	bool deadBullet(Bullet* bullet) {
		return bullet->isAlive();
	}
	
	Weapon::Weapon() :
		m_owner(NULL),
		m_image(NULL),
		m_bullets()
	{
	}
	
	Weapon::Weapon(GameObject& owner) :
		m_owner(&owner),
		m_image(NULL),
		m_bullets()
	{
	}
	
	Weapon::~Weapon()
	{
		if (m_image) {
			delete m_image;
		}
	}
	
	void Weapon::updateBullets(double currentTime, double deltaTime, GameNetworkClient* network)
	{
		
		list<Bullet*>::iterator it = m_bullets.begin();
		for ( ; it != m_bullets.end(); it++) {
			(*it)->update(currentTime, deltaTime, network);
		}
		
		//m_bullets.remove_if(deadBullet);
	}
	
	void Weapon::drawBullets(Engine& engine, Camera& camera)
	{
		list<Bullet*>::iterator it = m_bullets.begin();
		for ( ; it != m_bullets.end(); it++) {
			(*it)->draw(engine, camera);
		}
	}
	
	void Weapon::draw(Engine& engine, Camera& camera)
	{
		if (m_image && m_owner) {
			double angle = m_owner->getAngle();
			bool pointingRight = false;
			bool flipRotatedImage = false;
			
			// Right
			if ((angle >= 270.0 && angle <= 360.0) || (angle >= 0.0 && angle <= 90.0)) {
				pointingRight = true;
			}
			// Left
			//else if (angle > 90.0 && angle < 270.0) {
			//	m_pointingRight = false;
			//}
			
			// Up
			//if (angle > 180.0 && angle <= 360.0) {
			//}
			// Down
			//else {
			//}
			
			angle = -m_owner->getAngle();
			
			if (!pointingRight) {
				flipRotatedImage = true;
				angle = m_owner->getAngle() - 180.0;
				if (angle < 0.0) {
					angle = 360 + angle;
				} else if (angle > 360.0) {
					angle = 0.0 + (angle - 360.0);
				}
			}
			
			
			Image* rotatedImage = m_image->rotate(angle);

			int x = m_owner->getScreenX() - (rotatedImage->getWidth() / 2);
			int y = m_owner->getScreenY() - (rotatedImage->getHeight() / 2) + 5;

			if (flipRotatedImage) {
				rotatedImage->flip();
			}
			
			rotatedImage->draw(x, y);
			delete rotatedImage;
		}
	}
};

