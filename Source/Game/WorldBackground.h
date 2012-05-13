#ifndef __BLOCKWORLD_WORLDBACKGROUND_H__
#define __BLOCKWORLD_WORLDBACKGROUND_H__

#include "../Engine/Engine.h"
#include "../Engine/Image.h"

using namespace BadEngine;

namespace BlockWorld {
	class Camera;
	class WorldBackground {
		private:
			int m_layer;
			int m_x;
			int m_y;
			double m_speed;
			Image* m_image;
		
		private:
			WorldBackground();
		
		public:
			WorldBackground(int layer, int x, int y, double speed, Image& image);
			virtual ~WorldBackground();
			int getLayer();
			void draw(Engine& engine, Camera& camera);
	};
};

#endif // __BLOCKWORLD_WORLDBACKGROUND_H__
