#include "Animation.h"
#include "AnimationFrame.h"
#include "Engine.h"

#include <iostream>

namespace BadEngine {
	Animation::Animation() :
		m_frames(),
		m_currentFrame(NULL),
		m_currentFrameNumber(0),
		m_playing(false)
	{
	}
	
	Animation::~Animation()
	{
		vector<AnimationFrame*>::iterator it;
		it = m_frames.begin();
		for ( ; it != m_frames.end(); it++) {
			AnimationFrame* frame = *it;
			delete frame;
		}
	}
	
	void Animation::addFrame(AnimationFrame* frame)
	{
		m_frames.push_back(frame);
	}
	
	void Animation::play()
	{
		m_playing = true;
		m_currentFrameNumber = 0;
		m_currentFrame = m_frames.at(0);
		m_currentFrame->play();
	}
	
	void Animation::stop()
	{
		m_playing = false;
	}
	
	void Animation::resume()
	{
		m_playing = true;
	}
	
	void Animation::update(double deltaTime)
	{
		if (m_playing && m_currentFrame) {
			m_currentFrame->update(deltaTime);
			if (m_currentFrame->finishedPlaying()) {
				int lastFrameNumber = m_frames.size() - 1;
				int nextFrameNumber = m_currentFrameNumber + 1;
				if (nextFrameNumber > lastFrameNumber) {
					nextFrameNumber = 0;
				}
				m_currentFrameNumber = nextFrameNumber;
				m_currentFrame = m_frames.at(nextFrameNumber);
				m_currentFrame->play();
			}
		}
	}
	
	void Animation::draw(Engine& engine, int x, int y)
	{
		if (m_currentFrame) {
			m_currentFrame->draw(engine, x, y);
		}
	}
	
	int Animation::getWidth() {
		if (m_currentFrame) {
			return m_currentFrame->getWidth();
		}
		return 0;
	}
	
	int Animation::getHeight() {
		if (m_currentFrame) {
			return m_currentFrame->getHeight();
		}
		return 0;
	}
	
	void Animation::flipImages()
	{
		vector<AnimationFrame*>::iterator it;
		it = m_frames.begin();
		for ( ; it != m_frames.end(); it++) {
			AnimationFrame* frame = *it;
			frame->flipImage();
		}
	}
};
