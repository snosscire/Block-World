#ifndef __BLOCKWORLD_WORLD_H__
#define __BLOCKWORLD_WORLD_H__

#include "../Engine/Engine.h"
#include "../Engine/Position.h"
#include "../Engine/Rectangle.h"

using namespace BadEngine;

namespace BlockWorld {
	class Block;
	class Camera;
	class World {
		private:
			int m_width;
			int m_height;
			Block*** m_blocks;
		
		private:
			World();
			bool _haveCollision(Rectangle& a, Rectangle& b);
			
		public:
			World(int width, int height);
			~World();
			int getWidth();
			int getHeight();
			void setBlock(int x, int y, Block* block);
			Block* getBlock(int x, int y);
			void draw(Engine& engine, Camera& camera);
			bool haveCollision(int x, int y, int width, int height);
			void getWorldPositionFromScreenPosition(Camera& camera, Position& screenPosition, Position& worldPosition);
			Block* takeBlock(int x, int y);
	};
};

#endif // __BLOCKWORLD_WORLD_H__
