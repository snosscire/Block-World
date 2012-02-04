#ifndef __BLOCKWORLD_WORLD_H__
#define __BLOCKWORLD_WORLD_H__

#include "Engine/Engine.h"

using namespace BadEngine;

namespace BlockWorld {
	class Block;
	class Camera;
	class World {
		private:
			unsigned int m_width;
			unsigned int m_height;
			Block*** m_blocks;
		
		private:
			World();
		
		public:
			World(unsigned int width, unsigned int height);
			~World();
			unsigned int getWidth();
			unsigned int getHeight();
			void setBlock(unsigned int x, unsigned int y, Block* block);
			Block* getBlock(unsigned int x, unsigned int y);
			void draw(Engine* engine, Camera *camera);
			bool haveCollision(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
			void getWorldPositionFromScreenPosition(Camera *camera, unsigned int screenX, unsigned int screenY, unsigned int* worldX, unsigned int* worldY);
			Block* takeBlock(unsigned int x, unsigned int y);
	};
};

#endif // __BLOCKWORLD_WORLD_H__
