#include "AssaultRifle.h"
#include "../GameObject.h"
#include "../Bullet.h"
#include "Bullets/AssaultRifleBullet.h"

namespace BlockWorld {
	AssaultRifle::AssaultRifle(Engine& engine, GameObject& owner) :
		Weapon(owner),
		m_engine(&engine),
		m_withoutMuzzleFlashImage(NULL),
		m_withMuzzleFlashImage(NULL),
		m_firing(false),
		m_fireNextRound(0)
	{
		m_withoutMuzzleFlashImage = engine.loadImage("Resources/Weapons/assault-01.png");
		m_withMuzzleFlashImage = engine.loadImage("Resources/Weapons/assault-02.png");
		m_image = m_withoutMuzzleFlashImage;
	}
	
	AssaultRifle::~AssaultRifle()
	{
		m_image = NULL;
		if (m_withoutMuzzleFlashImage) {
			delete m_withoutMuzzleFlashImage;
		}
		if (m_withMuzzleFlashImage) {
			delete m_withMuzzleFlashImage;
		}
	}
	
	void AssaultRifle::update(double currentTime, double deltaTime, GameNetworkClient* network)
	{
		updateBullets(currentTime, deltaTime, network);
		if (m_firing) {
			if (currentTime >= m_fireNextRound) {
				fireBullet(m_owner->getX(), m_owner->getY(), m_owner->getAngle());
				m_fireNextRound = currentTime + 100;
			}
			m_image = m_withMuzzleFlashImage;
		} else {
			m_fireNextRound = currentTime;
			m_image = m_withoutMuzzleFlashImage;
		}
	}
	
	void AssaultRifle::startFiring()
	{
		m_firing = true;
	}

	void AssaultRifle::stopFiring()
	{
		m_firing = false;
	}
	
	void AssaultRifle::fireBullet(double x, double y, double angle)
	{
		Bullet* bullet = new AssaultRifleBullet(*m_engine, *m_owner, x, y, angle);
		m_bullets.push_back(bullet);
	}
};

