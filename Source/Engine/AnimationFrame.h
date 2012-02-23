#ifndef __BADENGINE_ANIMATIONFRAME_H__
#define __BADENGINE_ANIMATIONFRAME_H__

namespace BadEngine {
	class Engine;
	class Image;
	class AnimationFrame {
		private:
			double m_playTime;
			double m_currentPlayTime;
			Image* m_image;
		
		private:
			AnimationFrame();
		
		public:
			AnimationFrame(double playTime, Image* image);
			virtual ~AnimationFrame();
			void play();
			bool finishedPlaying();
			int getWidth();
			int getHeight();
			void update(double deltaTime);
			void draw(Engine& engine, int x, int y);
	};
};

#endif // __BADENGINE_ANIMATIONFRAME_H__
