#ifndef __BADENGINE_ANIMATION_H__
#define __BADENGINE_ANIMATION_H__

#include <vector>

using namespace std;

namespace BadEngine {
	class AnimationFrame;
	class Engine;
	class Animation {
		private:
			vector<AnimationFrame*> m_frames;
			AnimationFrame* m_currentFrame;
			int m_currentFrameNumber;
			bool m_playing;
		
		public:
			Animation();
			virtual ~Animation();
			void addFrame(AnimationFrame* frame);
			void play();
			void stop();
			void resume();
			void update(double deltaTime);
			void draw(Engine& engine, int x, int y);
			int getWidth();
			int getHeight();
			void flipImages();
	};
};

#endif // __BADENGINE_ANIMATION_H__
