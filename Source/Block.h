#ifndef ___BLOCKWORLD_BLOCK_H__
#define ___BLOCKWORLD_BLOCK_H__

#include "Engine/Engine.h"
#include "Engine/Position.h"
#include "BlockType.h"

using namespace BadEngine;

namespace BlockWorld {
	class World;
	class Camera;
	class Block {
		private:
			BlockType m_type;
			Position m_position;
			World* m_world;
		
		private:
			Block();
		
		public:
			Block(World *world, unsigned int x, unsigned int y);
			~Block();
			BlockType getType();
			void setPosition(unsigned int x, unsigned int y);
			virtual void update();
			virtual void draw(Engine* engine, Camera* camera);
	};
};

#endif // __BLOCKWORLD_BLOCK_H__
