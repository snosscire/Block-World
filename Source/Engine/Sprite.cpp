#include "Sprite.h"
#include "Animation.h"
#include "Engine.h"

#include <iostream>

namespace BadEngine {
	Sprite::Sprite() :
		m_animations(),
		m_currentAnimation(NULL),
		m_currentAnimationName(NULL),
		leftFlipped(false)
	{
	}
	
	Sprite::~Sprite()
	{
		map<const string, Animation*>::iterator it;
		it = m_animations.begin();
		for ( ; it != m_animations.end(); it++) {
			Animation* animation = it->second;
			delete animation;
		}
	}
	
	void Sprite::addAnimation(const string& name, Animation* animation) {
		m_animations[name] = animation;
	}
	
	void Sprite::playAnimation(const string& name)
	{
		map<const string, Animation*>::iterator it;
		it = m_animations.find(name);
		if (it != m_animations.end()) {
			if (it->second != m_currentAnimation) {
				m_currentAnimationName = &it->first;
				m_currentAnimation = it->second;
				m_currentAnimation->play();
			} else {
				m_currentAnimation->resume();
			}
		}
	}
	
	void Sprite::stopCurrentAnimation()
	{
		if (m_currentAnimation) {
			m_currentAnimation->stop();
		}
	}
	
	const string& Sprite::getCurrentAnimationName()
	{
		return *m_currentAnimationName;
	}
	
	void Sprite::update(double deltaTime)
	{
		if (m_currentAnimation) {
			m_currentAnimation->update(deltaTime);
		}
	}
	
	void Sprite::draw(Engine& engine, int x, int y)
	{
		if (m_currentAnimation) {
			m_currentAnimation->draw(engine, x, y);
		}
	}
	
	int Sprite::getWidth()
	{
		if (m_currentAnimation) {
			return m_currentAnimation->getWidth();
		}
		return 0;
	}
	
	int Sprite::getHeight() {
		if (m_currentAnimation) {
			return m_currentAnimation->getHeight();
		}
		return 0;
	}
	
	void Sprite::flipImages(bool flipLeft)
	{
		if ((!leftFlipped && flipLeft) || (leftFlipped && !flipLeft)) {
			leftFlipped = flipLeft;
			map<const string, Animation*>::iterator it;
			it = m_animations.begin();
			for ( ; it != m_animations.end(); it++) {
				Animation* animation = it->second;
				animation->flipImages();
			}
		}
	}
};
