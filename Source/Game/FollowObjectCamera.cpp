#include "FollowObjectCamera.h"
#include "World.h"
#include "GameObject.h"
#include "BlockWorld.h"

#include <iostream>

namespace BlockWorld {
	FollowObjectCamera::FollowObjectCamera() :
		Camera(),
		m_world(NULL),
		m_object(NULL),
		m_engine(NULL)
	{
	}
	
	FollowObjectCamera::FollowObjectCamera(World& world, GameObject& object, Engine& engine) :
		Camera(),
		m_world(&world),
		m_object(&object),
		m_engine(&engine)
	{
	}
	
	FollowObjectCamera::~FollowObjectCamera()
	{
	}
	
	int FollowObjectCamera::getLeft()
	{
		int left = m_object->getX() - (m_engine->getScreenWidth() / 2);
		int worldPixelWidth = m_world->getWidth() * BlockWorld::BLOCK_WIDTH;
		
		if (m_engine->getScreenWidth() > worldPixelWidth) {
			left = 0;
		} else {
			int maxLeft = worldPixelWidth - m_engine->getScreenWidth();
			if (left < 0) {
				left = 0;
			} else if (left > maxLeft) {
				left = maxLeft;
			}
		}
		
		return left;
	}
	
	int FollowObjectCamera::getRight()
	{
		return getLeft() + m_engine->getScreenWidth();
	}
	
	int FollowObjectCamera::getTop()
	{
		int top = m_object->getY() - (m_engine->getScreenHeight() / 2);
		int worldPixelHeight = m_world->getHeight() * BlockWorld::BLOCK_HEIGHT;
		
		if (m_engine->getScreenHeight() > worldPixelHeight) {
			top = 0;
		} else {
			int maxTop = worldPixelHeight - m_engine->getScreenHeight();
			
			if (top < 0) {
				top = 0;
			} else if (top > maxTop) {
				top = maxTop;
			}
		}
		
		return top;
	}
	
	int FollowObjectCamera::getBottom()
	{
		return getTop() + m_engine->getScreenHeight();
	}
};
