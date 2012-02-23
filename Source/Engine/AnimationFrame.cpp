#include "AnimationFrame.h"
#include "Image.h"

#include <iostream>

namespace BadEngine {
	AnimationFrame::AnimationFrame() :
		m_playTime(0.0),
		m_currentPlayTime(0.0),
		m_image(NULL)
	{
	}
	
	AnimationFrame::AnimationFrame(double playTime, Image* image) :
		m_playTime(playTime),
		m_currentPlayTime(0.0),
		m_image(image)
	{
	}
	
	AnimationFrame::~AnimationFrame()
	{
		if (m_image) {
			delete m_image;
		}
	}
	
	void AnimationFrame::play()
	{
		m_currentPlayTime = 0.0;
	}
	
	void AnimationFrame::update(double deltaTime)
	{
		m_currentPlayTime += deltaTime;
	}
	
	bool AnimationFrame::finishedPlaying()
	{
		if (m_currentPlayTime > m_playTime) {
			return true;
		}
		return false;
	}
	
	int AnimationFrame::getWidth()
	{
		if (m_image) {
			return m_image->getWidth();
		}
		return 0;
	}
	
	int AnimationFrame::getHeight()
	{
		if (m_image) {
			return m_image->getHeight();
		}
		return 0;
	}
	
	void AnimationFrame::draw(Engine& engine, int x, int y)
	{
		if (m_image) {
			m_image->draw(x, y);
		}
	}
};
