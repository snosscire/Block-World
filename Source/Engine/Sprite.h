#ifndef __BADENGINE_SPRITE_H__
#define __BADENGINE_SPRITE_H__

#include <string>
#include <map>

using namespace std;

namespace BadEngine {
	class Animation;
	class Engine;
	class Sprite {
		private:
			map<const string, Animation*> m_animations;
			Animation* m_currentAnimation;
			const string* m_currentAnimationName;
		
		public:
			Sprite();
			virtual ~Sprite();
			void addAnimation(const string& name, Animation* animation);
			void playAnimation(const string& name);
			void stopCurrentAnimation();
			const string& getCurrentAnimationName();
			void update(double deltaTime);
			void draw(Engine& engine, int x, int y);
			int getWidth();
			int getHeight();
	};
};

#endif // __BADENGINE_SPRITE_H__
