#ifndef __BLOCKWORLD_DEFAULTBLOCK_H__
#define __BLOCKWORLD_DEFAULTBLOCK_H__

#include "../../Engine/Engine.h"
#include "../../Engine/Image.h"

#include "../Block.h"
#include "../BlockType.h"

using namespace BadEngine;

namespace BlockWorld {
	class Camera;
	class World;
	class DefaultBlock : public Block {
		private:
			Image* m_image;
		
		protected:
			DefaultBlock();
		
		public:
			DefaultBlock(World &world, int x, int y, BlockType type, Image& image);
			virtual ~DefaultBlock();
			virtual void draw(Engine& engine, Camera& camera);
	};
};

#endif // __BLOCKWORLD_DEFAULTBLOCK_H__
