#include "ObjectManager.h"
#include "GameObject.h"
#include "Camera.h"
#include "Weapon.h"

namespace BlockWorld {
	ObjectManager::ObjectManager() :
		m_objects()
	{
	}
	
	ObjectManager::~ObjectManager()
	{
		list<GameObject*>::iterator it = m_objects.begin();
		for ( ; it != m_objects.end(); it++) {
			GameObject* object = *it;
			delete object;
		}
	}
	
	void ObjectManager::addObject(GameObject* object)
	{
		m_objects.push_back(object);
		object->setManager(this);
	}
	
	void ObjectManager::spriteUpdate(double currentTime, double deltaTime, int id)
	{
		list<GameObject*>::iterator it = m_objects.begin();
		for ( ; it != m_objects.end(); it++) {
			GameObject* object = *it;
			if (object->getNetworkID() != id) {
				if (object->isAlive())
					object->spriteUpdate(currentTime, deltaTime);
				Weapon* weapon = object->getWeapon();
				if (weapon) {
					weapon->update(currentTime, deltaTime, NULL);
				}
			}
		}
	}
	
	void ObjectManager::draw(Engine& engine, Camera& camera)
	{
		list<GameObject*>::iterator it = m_objects.begin();
		for ( ; it != m_objects.end(); it++) {
			GameObject* object = *it;
			if (object->isAlive())
				object->draw(engine, camera);
		}
	}
	
	bool ObjectManager::_haveCollision(Square& a, Square& b)
	{
		int aLeft = a.getX();
		int aRight = a.getX() + a.getWidth();
		int aTop = a.getY();
		int aBottom = a.getY() + a.getHeight();
		int bLeft = b.getX();
		int bRight = b.getX() + b.getWidth();
		int bTop = b.getY();
		int bBottom = b.getY() + b.getHeight();
		if (aBottom <= bTop) {
			return false;
		}
		if ( aTop >= bBottom) {
			return false;
		}
		if (aRight <= bLeft) {
			return false;
		}
		if( aLeft >= bRight ) {
			return false;
		}
		return true;
	}
	
	GameObject* ObjectManager::haveCollision(double x, double y, int width, int height, GameObject& ignore)
	{
		GameObject* object = NULL;
		list<GameObject*>::iterator it = m_objects.begin();
		for ( ; it != m_objects.end(); it++) {
			GameObject* o = *it;
			if (o->isAlive() && o->getNetworkID() != ignore.getNetworkID()) {
				list<Square*>& rects = o->getCollisionRectangles();
				list<Square*>::iterator jt = rects.begin();
				for ( ; jt != rects.end(); jt++) {
					Square* a = *jt;
					
					Square b;
					b.setX(x);
					b.setY(y);
					b.setWidth(width);
					b.setHeight(height);
					
					if (_haveCollision(*a, b)) {
						object = o;
						break;
					}
				}
			
				if (object)
					break;
			}
		}
		return object;
	}
};
